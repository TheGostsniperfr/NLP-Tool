
#include "token/IPosTags.hh"

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <memory>
#include <stdexcept>

using namespace std;

class LaposApi
{
private:
    string text;
    bool verbose;

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
        return "echo " + text + "| ./lapos-0.1.2/lapos -t -m ./lapos-0.1.2/model_big/";
    }
    
    string getApiPOSTaggingResponse() {
        string out = exec(getPosTagCmd(this->text).c_str());

        size_t pos_done = out.find("done");
        if (pos_done != string::npos) {
            return  out.substr(pos_done + 5);
        } else {
            throw runtime_error("Invalid api response: Could not find 'done'.");
        }
    }
public:
    LaposApi(const string text, bool verbose = false) {
        this->text = text;
        this->verbose = verbose;
    }

    vector<pair<string, PosTags>> run() {
        string out = this->getApiPOSTaggingResponse();

        if(this->verbose) {
            cout << "Lapos API out: " + out << endl;
        }

        vector<pair<string, PosTags>> tags = this->getPosTagText(out);

        if(this->verbose) {
            printPosTagText(tags);
        }

        return tags;
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
};