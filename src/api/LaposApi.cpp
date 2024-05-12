#include "api/LaposApi.hh"

string getApiPOSTaggingResponse( ) {
    return "";
}


vector<pair<string, PosTags>> getPosTagText(const string& text) {
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





