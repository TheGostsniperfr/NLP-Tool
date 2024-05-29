#ifndef PRE_MATCHING_MODEL_H
#define PRE_MATCHING_MODEL_H

#include "sentence/Sentence.hh"

using namespace std;

class PreMatchingModifier
{
private:
    int modelCoef;
public:
    PreMatchingModifier(int modelCoef);
    virtual ~PreMatchingModifier();
    virtual void run(Sentence* sentence, bool verbose) = 0;
    int getModelCoef(); 
    bool operator<(PreMatchingModifier& other);
};

#endif