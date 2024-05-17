#ifndef TOKEN_H
#define TOKEN_H

#include "token/IPosTags.hh"

#include <string>
#include <algorithm>
#include <cctype>

using namespace std;


class Token
{
private:
    string originalString;
    string postProcessingString;
    PosTags posTag;
public:
    Token(string originalString);

    Token(Token* token);

    string getOriginalString();

    string getPostProcessingString();

    void setPosProcessingString(string postProcessingString);

    PosTags getPosTag();

    string getPosTagName();

    string getPosTagDescription();

    void setPosTag(PosTags posTag); 
};

#endif