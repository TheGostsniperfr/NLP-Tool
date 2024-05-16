/*
    TODO :

    Build the main factory:

    addPreMatchingModifier:
        - take a pre maching model

        - return this

    build:
        - return a factory class
*/

#include "factory/FactoryBuilder.hh"

#include <list>
#include <string>

using namespace std;

FactoryBuilder::FactoryBuilder() { }

FactoryBuilder& FactoryBuilder::withPreMatchingModifier(PreMatchingModifier* preMatchingModifier) {
    this->preMatchingModifierList.push_back(preMatchingModifier);
    return *this;
}

void FactoryBuilder::withPosApi(PosApi* posApi) {
    this->posApi = posApi;
}

Factory* FactoryBuilder::build() {
    if(
        this->posApi == NULL
        // || this->preMatchingModifierList.empty()
    ) {
        throw InvalidFactoryBuilderParametersException();
    }

    return new Factory(this->posApi, this->preMatchingModifierList);
}