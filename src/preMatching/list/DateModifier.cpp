#include "preMatching/list/DateModifier.hh"

DateModifier::DateModifier() : PreMatchingModifier(10) { }

DateModifier::~DateModifier() { }


bool DateModifier::isMounth(const string& str) {
    vector<string> months = {
        "january", "february", "march", "april", "may", "june",
        "july", "august", "september", "october", "november", "december"
    };

    return find(months.begin(), months.end(), str) != months.end();
}

void DateModifier::run(Sentence* sentence, __attribute__((unused)) bool verbose) {

    // Find date on format mm-dd-yyyy

    int findDate = -1;

    for(Token* token : sentence->getTokenSentence()) {
        if(findDate != -1) {
            if(token->getPosTag() == CD) {
                token->setPosTagWithOverWrite(DATE);
            }
            
            if(token->getPosTag() != SPACE) {
                findDate--;
            }
        }

        if(this->isMounth(token->getPostProcessingString())) {
            token->setPosTagWithOverWrite(DATE);
            findDate = 2;
        }
    }
}