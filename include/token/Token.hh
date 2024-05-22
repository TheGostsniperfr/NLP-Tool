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
    int wordId; // To match with the original word
    string originalString;
    string postProcessingString;
    PosTags posTag;
public:
    Token(string originalString, int wordId);

    Token(Token* token);

    ~Token();

    string getOriginalString();

    string getPostProcessingString();

    void setPosProcessingString(string postProcessingString);

    PosTags getPosTag();

    string getPosTagName();

    string getPosTagDescription();

    void setPosTag(PosTags posTag); 

    void setPosTagWithOverWrite(PosTags posTag); 

    int getWordId();

    void setWordId(int newWordId);
};

#endif