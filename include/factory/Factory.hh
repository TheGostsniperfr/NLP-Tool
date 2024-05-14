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
    Sentence sentence;

public:
    Factory(const Sentence& sentence);

    Sentence getSentence() const;
};


#endif