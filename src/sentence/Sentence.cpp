/*
    TODO :

    list of token class
    parse a text in token 
    
    Pre Machining :
        - transform invalid token in valid (n't -> not)
        - 

    Pos Tag process : 
        - run a Pos Tag algorithm
    
    Post Processing


    
    - toString
    




*/

#include <string>
#include <list>

#include "../src/token/Token.cpp"
#include "../src/sentence/tokenization.cpp"

using namespace std;

class Sentence
{
private:
    string inputText;
    list<Token> tokenSentence;
public:
    Sentence(string inputText) {
        this->inputText = inputText;
        this->tokenSentence = parseText(this->inputText);
    }

    string toString() {
        ostringstream oss;
        for(Token token : this->tokenSentence) {
            oss << token.getPostProcessingString() << " ";
        }

        return oss.str();
    } 
};


