#ifndef LAPOS_API_MODIFIER_HH
#define LAPOS_API_MODIFIER_HH

#include "preMatching/PreMatchingModifier.hh"

#include "token/IPosTags.hh"
#include "exception/list/api/InvalidApiResponseException.hh"

#include <list>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <memory>
#include <stdexcept>

using namespace std;

class LaposApiModifier : public PreMatchingModifier {
private:
    string exec(const char* cmd);
    string getPosTagCmd(string text);
    string getApiPOSTaggingResponse(Sentence* sentence);
    list<pair<string, PosTags>> getPosTagText(string text);
public:
    LaposApiModifier();
    void run(Sentence* sentence, bool verbose) override;
};



#endif