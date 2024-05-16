#ifndef FACTORY_HH
#define FACTORY_HH

#include "sentence/Sentence.hh"
#include "preMatching/PreMatchingModifier.hh"
#include "api/PosApi.hh"

#include <string>
#include <list>

using namespace std;


class FactoryBuilder;

class Factory {
private:
    PosApi* posApi;
    list<PreMatchingModifier*> preMatchingModifierList;

public:
    Factory(PosApi* posApi, list<PreMatchingModifier*> preMatchingModifierList);

    Sentence* run(string inputText);
};

#endif