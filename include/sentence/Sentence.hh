#ifndef SENTENCE_H
#define SENTENCE_H

#include <string>
#include <list>

#include "token/Token.hh"
#include "sentence/tokenization.hh"

using namespace std;

class Sentence
{
private:
    string inputText;
    list<Token*> tokenSentence;
public:
    Sentence(string inputText);

    string toString();
};


#endif