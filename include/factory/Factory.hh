#ifndef FACTORY_HH
#define FACTORY_HH

#include "sentence/Sentence.hh"
#include "preMatching/PreMatchingModel.hh"
#include "api/PosApi.hh"

#include <string>
#include <list>

using namespace std;


class FactoryBuilder;

class Factory {
private:
    PosApi* posApi;
    list<PreMatchingModel*> preMatchingModelList;

public:
    Factory(PosApi* posApi, list<PreMatchingModel*> preMatchingModelList);

    Sentence* run(string inputText);
};

#endif