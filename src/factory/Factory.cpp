/*
    TODO :

    Take a text that will be transform in text (Job: parse the text)
    Take a list of pre matching parameters (Job: search for token types (URL, DATE, GPS, CORP, ...))

    Take a Pos Tag class type (Job: classifies all remaining tokens)

    Run : 

        Do the works

*/


#include "factory/Factory.hh"

Factory::Factory(Sentence* sentence, PosApi* posApi, list<PreMatchingModel*> preMatchingModelList) {
    this->sentence = sentence;
    this->posApi = posApi;
    this->preMatchingModelList = preMatchingModelList;
}

Sentence* Factory::getSentence() {
    return this->sentence;
}
