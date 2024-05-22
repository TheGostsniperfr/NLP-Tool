
#include "preMatching/list/LaposApiModifier.hh"

LaposApiModifier::LaposApiModifier() { }

LaposApiModifier::~LaposApiModifier() { }

void LaposApiModifier::run(Sentence* sentence, bool verbose) {
    string out = getApiPOSTaggingResponse(sentence);

    list<pair<string, PosTags>> tags = getPosTagText(out);

    if(verbose) {
        printPosTagText(tags);
    }

    auto tagsIterator = tags.begin();

    for(Token* token : sentence->getTokenSentence()) {
        if(token->getPosTag() != SPACE) {
            if(token->getPosTag() == NONE) {
                token->setPosTag(tagsIterator->second);
            }
            ++tagsIterator;
        }

        if(tagsIterator == tags.end()) {
            return;
        }
    } 
}



string LaposApiModifier::exec(const char* cmd) {
    char buffer[128];
    string result = "";
    shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw runtime_error("popen() failed!");
    }
    while (!feof(pipe.get())) {
        if (fgets(buffer, 128, pipe.get()) != nullptr) {
            result += buffer;
        }
    }

    if (!result.empty() && result[result.length() - 1] == '\n') {
        result.erase(result.length() - 1);
    }
    
    return result;
}

string LaposApiModifier::getPosTagCmd(string text) {
    return "echo \"" + text + "\"| ./lapos-0.1.2/lapos -m ./lapos-0.1.2/model_big/";
}

string LaposApiModifier::getApiPOSTaggingResponse(Sentence* sentence) {
    string out = exec(getPosTagCmd(sentence->toStringFakeSpace()).c_str());

    cout << "out: " + out << endl;

    size_t pos_done = out.find("done");
    if (pos_done != string::npos) {
        return out.substr(pos_done + 5);
    } else {
        throw InvalidApiResponseException("Could not find 'done'.");
    }
}

list<pair<string, PosTags>> LaposApiModifier::getPosTagText(string text) {
    list<pair<string, PosTags>> tokens;

    replace(text.begin(), text.end(), '\n', ' ');

    istringstream iss(text);
    string token;

    while(getline(iss, token, ' ')) {
        size_t pos = token.find('/');
        if(pos != string::npos) {
            string word = token.substr(0, pos);
            string strTag = token.substr(pos + 1);

            PosTags tag = getPosTagFromToken(strTag);

            tokens.push_back(make_pair(word, tag));
        }
    }

    return tokens;
}