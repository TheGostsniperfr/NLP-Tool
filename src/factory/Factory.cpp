/*
    TODO :

    Take a text that will be transform in text (Job: parse the text)
    Take a list of pre matching parameters (Job: search for token types (URL, DATE, GPS, CORP, ...))

    Take a Pos Tag class type (Job: classifies all remaining tokens)

    Run : 

        Do the works

*/


#include "factory/Factory.hh"

Factory::Factory(PosApi* posApi, list<PreMatchingModifier*> preMatchingModifierList) {
    this->posApi = posApi;
    this->preMatchingModifierList = preMatchingModifierList;
}

Sentence* Factory::run(string inputText, bool verbose) {
    Sentence* sentence = new Sentence(inputText);

    // Apply modifiers
    for(PreMatchingModifier* modifier : this->preMatchingModifierList) {
        modifier->run(sentence, verbose);
    }

    return sentence;
}

