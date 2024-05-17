
#include "api/list/LaposApi.hh"



LaposApi::LaposApi() : PosApi() {
    
}

void LaposApi::run(Sentence* sentence, bool verbose) {
    this->sentence = sentence;
    this->verbose = verbose;

    string out = getApiPOSTaggingResponse();
    
    

    if(this->verbose) {
        cout << "Lapos API out: " + out << endl;
    }

    list<pair<string, PosTags>> tags = getPosTagText(out);

    if(this->verbose) {
        printPosTagText(tags);
    }

    if(this->sentence->getTokenSentence().size() != tags.size()) {
        throw runtime_error("Differents size of sentence tokens and tags found!");
    }

    auto tagsIterator = tags.begin();

    for(Token* token : this->sentence->getTokenSentence()) {
        if(token->getPosTag() != NONE) {
            token->setPosTag(tagsIterator->second);
        }
        ++tagsIterator;
    } 
}



string LaposApi::exec(const char* cmd) {
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

string LaposApi::getPosTagCmd(string text) {
    return "echo " + text + "| ./lapos-0.1.2/lapos -t -m ./lapos-0.1.2/model_big/";
}

string LaposApi::getApiPOSTaggingResponse() {
    string out = exec(getPosTagCmd(this->sentence->toString()).c_str());

    size_t pos_done = out.find("done");
    if (pos_done != string::npos) {
        return out.substr(pos_done + 5);
    } else {
        throw InvalidApiResponseException("Could not find 'done'.");
    }
}

list<pair<string, PosTags>> LaposApi::getPosTagText(string text) {
    list<pair<string, PosTags>> tokens;

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