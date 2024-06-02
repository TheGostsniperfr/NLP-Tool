#ifndef CORP_MODIFIER_H
#define CORP_MODIFIER_H

#include "preMatching/PreMatchingModifier.hh"

class CorpModifier : public PreMatchingModifier
{
private:
    bool isCorp(const string& str);
public:
    CorpModifier();
    ~CorpModifier() override;
    void run(Sentence* sentence, bool verbose) override;
};

#endif