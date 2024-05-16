#ifndef POS_API_HH
#define POS_API_HH

#include "sentence/Sentence.hh"

using namespace std;

class PosApi {
protected:
    bool verbose;
    Sentence* sentence;
public:
    PosApi();
    virtual void run(Sentence* sentence, bool verbose) = 0;
};


#endif