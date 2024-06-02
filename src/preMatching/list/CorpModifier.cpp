#include "preMatching/list/CorpModifier.hh"

CorpModifier::CorpModifier() : PreMatchingModifier(10) { }

CorpModifier::~CorpModifier() { }


bool CorpModifier::isCorp(const string& str) {
    vector<string> businessTerms = {
        "corp",
        "corporation",
        "inc",
        "ltd",
        "llc",
        "llp",
        "co",
        "plc",
        "inc.",
        "gmbh",
        "ag",
        "npo",
        "s.a.",
        "pty ltd",
        "b.v."
    };

    return find(businessTerms.begin(), businessTerms.end(), str) != businessTerms.end();
}

void CorpModifier::run(Sentence* sentence, __attribute__((unused)) bool verbose) {

    Token* previousToken = NULL;

    for(Token* token : sentence->getTokenSentence()) {
        if(this->isCorp(token->getPostProcessingString())) {
            token->setPosTagWithOverWrite(CORP);
            if(previousToken != NULL) {
                previousToken->setPosTagWithOverWrite(CORP);
            }
        }

        if(token->getPosTag() != SPACE) {
            previousToken = token;
        }   
    }
}