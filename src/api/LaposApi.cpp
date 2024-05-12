#include "api/LaposApi.hh"

string exec(const char* cmd) {
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

string getPosTagCmd(string text) {
    cout << "cmd: " << "echo " + text + "| ./lapos-0.1.2/lapos -t -m ./lapos-0.1.2/model_big/" << endl;
    return "echo " + text + "| ./lapos-0.1.2/lapos -t -m ./lapos-0.1.2/model_big/";
}

string getApiPOSTaggingResponse(string text) {
    string out = exec(getPosTagCmd(text).c_str());

    size_t pos_done = out.find("done");
    if (pos_done != string::npos) {
        return  out.substr(pos_done + 5);
    } else {
        throw runtime_error("Invalid api response: Could not find 'done'.");
    }
}


vector<pair<string, PosTags>> getPosTagText(string text) {
    vector<pair<string, PosTags>> tokens;

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

void printPosTagText(vector<pair<string, PosTags>> posTagText) {
    for(pair<string, PosTags> e : posTagText) {
        cout << e.first << " | " << getPosTagInfo(e.second).tagName << endl;
    }
}