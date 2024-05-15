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



Token::Token(string originalString) {
    this->originalString = originalString;
    this->postProcessingString = "Not defind";
    this->posTag = NONE;
};

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

