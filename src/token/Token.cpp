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

string Token::getOriginalString() const {
    return this->originalString;
}

string Token::getPostProcessingString() const {
    return this->postProcessingString;
}

void Token::setPosProcessingString(string postProcessingString) {
    this->postProcessingString = postProcessingString;
}

PosTags Token::getPosTag() const {
    return this->posTag;
}

string Token::getPosTagName() const {
    return getPosTagInfo(this->posTag).tagName;
}

string Token::getPosTagDescription() const {
    return getPosTagInfo(this->posTag).description;
}

void Token::setPosTag(PosTags posTag) {
    this->posTag = posTag;
}

