#ifndef TOKEN_H
#define TOKEN_H

#include "token/IPosTags.hh"

#include <string>

using namespace std;


class Token
{
private:
    string originalString;
    string postProcessingString;
    PosTags posTag;
public:
    Token(string originalString);

    string getOriginalString();

    string getPostProcessingString();

    void setPosProcessingString(string postProcessingString);

    PosTags getPosTag();

    string getPosTagName();

    string getPosTagDescription();

    void setPosTag(PosTags posTag); 
};

#endif