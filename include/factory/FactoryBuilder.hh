#ifndef FACTORY_BUILDER_HH
#define FACTORY_BUILDER_HH

#include "factory/Factory.hh"
#include "preMatching/PreMatchingModifier.hh"
#include "sentence/Sentence.hh"

#include "exception/list/factory/InvalidFactoryBuilderParametersException.hh"

#include <list>
#include <string>

using namespace std;


class FactoryBuilder
{
private:
    list<PreMatchingModifier*> preMatchingModifierList;
public:
    FactoryBuilder();

    FactoryBuilder& withPreMatchingModifier(PreMatchingModifier* PreMatchingModifier);

    Factory* build();
};


#endif