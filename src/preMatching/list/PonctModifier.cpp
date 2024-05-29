#include "preMatching/list/PonctModifier.hh"

PonctModifier::PonctModifier() : PreMatchingModifier(-60) { }

PonctModifier::~PonctModifier() { }

void PonctModifier::run(Sentence* sentence, bool verbose) {
    regex pattern("[.,;:!?]");

    for (Token* token : sentence->getTokenSentence()) {
        if(regex_search(token->getPostProcessingString(), pattern)) {
            token->setPosTag(PONCT);
        }
    }
}