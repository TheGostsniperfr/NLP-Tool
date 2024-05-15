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

#include "sentence/Sentence.hh"

Sentence::Sentence(string inputText) {
    this->inputText = inputText;
    this->tokenSentence = parseText(this->inputText);
}

string Sentence::toString() {
    ostringstream oss;
    for(Token* token : this->tokenSentence) {
        oss << token->getOriginalString() << " ";
    }

    oss << endl;
    return oss.str();
}