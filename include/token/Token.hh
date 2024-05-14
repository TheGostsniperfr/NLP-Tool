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

    string getOriginalString() const;

    string getPostProcessingString() const;

    void setPosProcessingString(string postProcessingString);

    PosTags getPosTag() const;

    string getPosTagName() const;

    string getPosTagDescription() const;

    void setPosTag(PosTags posTag); 
};

#endif