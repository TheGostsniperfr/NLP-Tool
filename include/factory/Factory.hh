#ifndef FACTORY_HH
#define FACTORY_HH

#include "sentence/Sentence.hh"
#include "preMatching/PreMatchingModel.hh"

#include <string>
#include <list>

using namespace std;


class FactoryBuilder;

class Factory {
private:
    Sentence* sentence;
    list<PreMatchingModel*> preMatchingModelList;

public:
    Factory(Sentence* sentence, list<PreMatchingModel*> preMatchingModelList);

    Sentence* getSentence();
};


#endif