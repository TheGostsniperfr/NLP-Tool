#ifndef PONCT_MODIFIER_H
#define PONCT_MODIFIER_H

#include "preMatching/PreMatchingModifier.hh"
#include <regex>

class PonctModifier : public PreMatchingModifier
{
private:
public:
    PonctModifier();
    ~PonctModifier() override;

    void run(Sentence* sentence, bool verbose) override;
};

#endif