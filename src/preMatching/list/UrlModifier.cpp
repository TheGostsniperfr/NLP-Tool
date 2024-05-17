#include "preMatching/list/UrlModifier.hh"

UrlModifier::UrlModifier() { }

void UrlModifier::run(Sentence* sentence, bool verbose) {
    bool urlDetected = false;
    
    for (Token* token : sentence->getTokenSentence()) {
        if (urlDetected) {
            if(token->getPosTag() == SPACE) {
                urlDetected = false;
            } else {
                token->setPosTag(URL);
            }
        } else if (token->getPostProcessingString().compare(0, 4, "http") == 0) {
            token->setPosTag(URL);
            urlDetected = true; 
        } 
    }
}
