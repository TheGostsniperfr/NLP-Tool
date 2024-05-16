#include "api/PosApi.hh"

PosApi::PosApi(Sentence* sentence, bool verbose) {
    this->sentence = sentence;
    this->verbose = verbose;
}