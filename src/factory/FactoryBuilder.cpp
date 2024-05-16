/*
    TODO :

    Build the main factory:

    addPreMatchingModel:
        - take a pre maching model

        - return this

    build:
        - return a factory class
*/

#include "factory/FactoryBuilder.hh"

#include <list>
#include <string>

using namespace std;

FactoryBuilder::FactoryBuilder(string inputText) {
    this->inputText = inputText;
}

FactoryBuilder& FactoryBuilder::withPreMatchingModel(PreMatchingModel* preMatchingModel) {
    this->preMatchingModelList.push_back(preMatchingModel);
    return *this;
}

void FactoryBuilder::withPosApi(PosApi* posApi) {
    this->posApi = posApi;
}

Factory* FactoryBuilder::build() {
    return new Factory(new Sentence(this->inputText), this->posApi, this->preMatchingModelList);
}