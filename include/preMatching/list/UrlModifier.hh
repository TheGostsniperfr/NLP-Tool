#ifndef URL_MODIFIER_H
#define URL_MODIFIER_H

#include "preMatching/PreMatchingModifier.hh"

class UrlModifier : public PreMatchingModifier
{
private:
public:
    UrlModifier();
    ~UrlModifier() override;

    void run(Sentence* sentence, bool verbose) override;
};

#endif