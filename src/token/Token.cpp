/*
        TODO :

        parameter:
            - originalString
            - postProcessingString (n't -> not)
            - IPOSToken

        getIPosToken
        getIPosTokenAsString
        getIPosTokenDescription
        toString

*/

#include "token/Token.hh"



Token::Token(string originalString, int wordId) {
    this->originalString = originalString;
    this->wordId = wordId;

    this->postProcessingString = originalString;
    transform(this->postProcessingString.begin(), this->postProcessingString.end(), this->postProcessingString.begin(), ::tolower);
    
    this->posTag = NONE;
};

Token::Token(Token* token) {
    this->originalString = token->getOriginalString();
    this->wordId = token->wordId;
    this->postProcessingString = token->getPostProcessingString();
    this->posTag = token->posTag;    
}

string Token::getOriginalString() {
    return this->originalString;
}

string Token::getPostProcessingString() {
    return this->postProcessingString;
}

void Token::setPosProcessingString(string postProcessingString) {
    this->postProcessingString = postProcessingString;
}

PosTags Token::getPosTag() {
    return this->posTag;
}

string Token::getPosTagName() {
    return getPosTagInfo(this->posTag).tagName;
}

string Token::getPosTagDescription() {
    return getPosTagInfo(this->posTag).description;
}

void Token::setPosTag(PosTags posTag) {
    this->posTag = posTag;
}

int Token::getWordId() {
    return this->wordId;
}

void Token::setWordId(int newWordId) {
    this->wordId = newWordId;
}

