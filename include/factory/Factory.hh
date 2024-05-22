#ifndef FACTORY_HH
#define FACTORY_HH

#include "sentence/Sentence.hh"
#include "preMatching/PreMatchingModifier.hh"

#include <string>
#include <list>

using namespace std;


class FactoryBuilder;

class Factory {
private:
    list<PreMatchingModifier*> preMatchingModifierList;

public:
    Factory(list<PreMatchingModifier*> preMatchingModifierList);
    ~Factory();

    Sentence* run(string inputText, bool verbose);
};

#endif