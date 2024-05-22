#ifndef CONTRACTION_MODIFIER_H
#define CONTRACTION_MODIFIER_H

#include "preMatching/PreMatchingModifier.hh"

class ContractionModifier : public PreMatchingModifier
{
private:
public:
    ContractionModifier();
    ~ContractionModifier() override;
    void run(Sentence* sentence, bool verbose) override;
};

#endif