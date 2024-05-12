#include <iostream>
#include <unordered_map>
#include <string>
#include <stdexcept>

using namespace std;

// List from https://stackoverflow.com/questions/15388831/what-are-all-possible-pos-tags-of-nltk

enum PosTags
{
    CC, // conjunction, coordinating
    CD, // numeral, cardinal
    DT, // Determiner
    EX, // Existantial
    IN, // preposition or conjunction, subordinating
    JJ, // adjective or numeral, ordinal
    JJR, // adjective, comparative
    JJS, // adjective, superlative
    LS, // List item marker
    MD, // Modal auxilliary
    NN, // noun, common, singular or mass
    NNP, // noun, proper, singular
    NNS, // noun, common, plural
    PDT, // pre-determiner
    POS, // genitive marker
    PRP, // pronoun, personal
    PPP$, // pronoun, possessive
    RB, // adverb
    RBR, // adverb
    RBS, // adverb, superlative
    RP, // particle
    TO, // "to" as preposition or infinitive marker
    UH, // interjection
    VB, //  verb, base form
    VBD, // verb, past tense
    VBG, // verb, present participle or gerund
    VBN, // verb, past participle
    VBP, // verb, present tense, not 3rd person singular
    VBZ, // verb, present tense, 3rd person singular
    WDT, //  WH-determiner
    WP, // WH-pronoun
    WRB, // Wh-adverb
    PONCT,  // Punctuation
};
