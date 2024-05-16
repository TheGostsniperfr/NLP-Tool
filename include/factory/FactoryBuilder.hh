#ifndef FACTORY_BUILDER_HH
#define FACTORY_BUILDER_HH

#include "factory/Factory.hh"
#include "preMatching/PreMatchingModifier.hh"
#include "sentence/Sentence.hh"
#include "api/PosApi.hh"

#include "exception/list/factory/InvalidFactoryBuilderParametersException.hh"

#include <list>
#include <string>

using namespace std;


class FactoryBuilder
{
private:
    PosApi* posApi;
    list<PreMatchingModifier*> preMatchingModifierList;
public:
    FactoryBuilder();

    FactoryBuilder& withPreMatchingModifier(PreMatchingModifier* PreMatchingModifier);

    void withPosApi(PosApi* posApi);

    Factory* build();
};


#endif