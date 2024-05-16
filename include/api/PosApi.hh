#ifndef POS_API_HH
#define POS_API_HH

#include "sentence/Sentence.hh"

using namespace std;

class PosApi {
protected:
    bool verbose;
    Sentence* sentence;
public:
    PosApi(Sentence* sentence, bool verbose);
    virtual void run() = 0;
};


#endif