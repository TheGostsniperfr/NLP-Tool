#ifndef DATE_MODIFIER_H
#define DATE_MODIFIER_H

#include "preMatching/PreMatchingModifier.hh"

class DateModifier : public PreMatchingModifier
{
private:
    bool isMounth(const string& str);
public:
    DateModifier();
    ~DateModifier() override;
    void run(Sentence* sentence, bool verbose) override;
};

#endif