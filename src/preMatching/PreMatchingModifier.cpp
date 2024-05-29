
#include "preMatching/PreMatchingModifier.hh"


PreMatchingModifier::PreMatchingModifier(int modelCoef) {
    this->modelCoef = modelCoef;
 }

PreMatchingModifier::~PreMatchingModifier() { }

int PreMatchingModifier::getModelCoef() {
    return this->modelCoef;
}

bool PreMatchingModifier::operator<(PreMatchingModifier& other) {
    return modelCoef < other.modelCoef;
}