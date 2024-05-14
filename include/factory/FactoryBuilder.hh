#ifndef FACTORY_BUILDER_HH
#define FACTORY_BUILDER_HH

#include "factory/Factory.hh"
#include "preMatching/PreMatchingModel.hh"
#include "sentence/Sentence.hh"

#include <list>
#include <string>

using namespace std;


class FactoryBuilder
{
private:
    string inputText;
    list<PreMatchingModel> preMatchingModelList;
public:
    FactoryBuilder(string inputText);

    FactoryBuilder& addPreMatchingModel(const PreMatchingModel& preMatchingModel);

    Factory build() const;
};


#endif