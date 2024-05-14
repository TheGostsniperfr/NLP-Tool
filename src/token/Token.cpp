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

#include <string>

#include "token/IPosTags.hh"

using namespace std;


class Token
{
private:
    string originalString;
    string postProcessingString;
    PosTags posTag;
public:
    Token(string originalString) {
        this->originalString = originalString;
        this->postProcessingString = "Not defind";
        this->posTag = NONE;
    };

    string getOriginalString() {
        return this->originalString;
    }

    string getPostProcessingString() {
        return this->postProcessingString;
    }

    void setPosProcessingString(string postProcessingString) {
        this->postProcessingString = postProcessingString;
    }

    PosTags getPosTag() {
        return this->posTag;
    }

    string getPosTagName() {
        return getPosTagInfo(this->posTag).tagName;
    }

    string getPosTagDescription() {
        return getPosTagInfo(this->posTag).description;
    }

    void setPosTag(PosTags posTag) {
        this->posTag = posTag;
    }
};

