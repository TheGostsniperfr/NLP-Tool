#ifndef LAPOS_API_HH
#define LAPOS_API_HH

#include "api/PosApi.hh"
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

class LaposApi : public PosApi {
private:
    string exec(const char* cmd);
    string getPosTagCmd(string text);
    string getApiPOSTaggingResponse();
    list<pair<string, PosTags>> getPosTagText(string text);
public:
    LaposApi();
    void run(Sentence* sentence, bool verbose) override;
};



#endif