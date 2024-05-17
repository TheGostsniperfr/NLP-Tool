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

list<Token*>& Sentence::getTokenSentence() {
    return this->tokenSentence;
}

string Sentence::toString() {
    ostringstream oss;
    for(Token* token : this->tokenSentence) {
        oss << token->getOriginalString() << " ";
    }

    oss << endl;
    return oss.str();
}

string Sentence::toStringPosProcess() {
    ostringstream oss;
    for(Token* token : this->tokenSentence) {
        oss << token->getPostProcessingString() << " ";
    }

    oss << endl;
    return oss.str();
}

string Sentence::toStringWithWordId() {
    ostringstream oss;
    for(Token* token : this->tokenSentence) {
        oss << "(" << token->getWordId() << ")[" << token->getOriginalString() << "] ";
    }

    oss << endl;
    return oss.str();
}

string Sentence::toStringPosProcessWithWordId() {
    ostringstream oss;
    for(Token* token : this->tokenSentence) {
        oss << "(" << token->getWordId() << ")[" << token->getPostProcessingString() << "] ";
    }

    oss << endl;
    return oss.str();
}