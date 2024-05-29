#include "factory/Factory.hh"

Factory::Factory(list<PreMatchingModifier*> preMatchingModifierList) {
    this->preMatchingModifierList = preMatchingModifierList;
}

Factory::~Factory() { 
    for(PreMatchingModifier* modifier : this->preMatchingModifierList) {
        delete modifier;
    }
}

Sentence* Factory::run(string inputText, bool verbose) {
    Sentence* sentence = new Sentence(inputText);

    // Apply modifiers
    for(PreMatchingModifier* modifier : this->preMatchingModifierList) {
        modifier->run(sentence, verbose);
    }

    return sentence;
}

