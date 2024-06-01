#include "factory/FactoryBuilder.hh"

#include <list>
#include <string>

using namespace std;

FactoryBuilder::FactoryBuilder() { }

FactoryBuilder& FactoryBuilder::withPreMatchingModifier(PreMatchingModifier* preMatchingModifier) {
    this->preMatchingModifierList.push_back(preMatchingModifier);
    return *this;
}

Factory* FactoryBuilder::build() {
    preMatchingModifierList.sort([](PreMatchingModifier* a, PreMatchingModifier* b) {
        return a->getModelCoef() < b->getModelCoef();
    });
    
    return new Factory(this->preMatchingModifierList);
}