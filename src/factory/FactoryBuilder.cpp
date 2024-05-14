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

FactoryBuilder& FactoryBuilder::addPreMatchingModel(const PreMatchingModel& preMatchingModel) {
    this->preMatchingModelList.push_back(preMatchingModel);
    return *this;
}

Factory FactoryBuilder::build() {
    return Factory(Sentence(this->inputText), this->preMatchingModelList);
}