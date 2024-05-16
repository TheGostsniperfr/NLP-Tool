#ifndef FACTORY_BUILDER_HH
#define FACTORY_BUILDER_HH

#include "factory/Factory.hh"
#include "preMatching/PreMatchingModel.hh"
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
    list<PreMatchingModel*> preMatchingModelList;
public:
    FactoryBuilder();

    FactoryBuilder& withPreMatchingModel(PreMatchingModel* preMatchingModel);

    void withPosApi(PosApi* posApi);

    Factory* build();
};


#endif