#include "token/IPosTags.hh"

PosTags getPosTagFromToken(const string& tag) {
    static const unordered_map<string, PosTags> tagToTokenMap = {
        {"CC", PosTags::CC},
        {"CD", PosTags::CD},
        {"DT", PosTags::DT},
        {"EX", PosTags::EX},
        {"IN", PosTags::IN},
        {"JJ", PosTags::JJ},
        {"JJR", PosTags::JJR},
        {"JJS", PosTags::JJS},
        {"LS", PosTags::LS},
        {"MD", PosTags::MD},
        {"NN", PosTags::NN},
        {"NNP", PosTags::NNP},
        {"NNS", PosTags::NNS},
        {"PDT", PosTags::PDT},
        {"POS", PosTags::POS},
        {"PRP", PosTags::PRP},
        {"PPP$", PosTags::PPP$},
        {"RB", PosTags::RB},
        {"RBR", PosTags::RBR},
        {"RBS", PosTags::RBS},
        {"RP", PosTags::RP},
        {"TO", PosTags::TO},
        {"UH", PosTags::UH},
        {"VB", PosTags::VB},
        {"VBD", PosTags::VBD},
        {"VBG", PosTags::VBG},
        {"VBN", PosTags::VBN},
        {"VBP", PosTags::VBP},
        {"VBZ", PosTags::VBZ},
        {"WDT", PosTags::WDT},
        {"WP", PosTags::WP},
        {"WRB", PosTags::WRB},
        {".", PosTags::PONCT},
    };

    auto it = tagToTokenMap.find(tag);
    if (it != tagToTokenMap.end()) {
        return it->second; 
    } else {
        throw std::invalid_argument("Unknown tag: " + tag); 
    }
}



PosTagInfo getPosTagInfo(PosTags tag) {
    const unordered_map<PosTags, PosTagInfo> posTagDescriptions = {
        {PosTags::CC, {"CC", "Conjunction, Coordinating"}},
        {PosTags::CD, {"CD", "Numeral, Cardinal"}},
        {PosTags::DT, {"DT", "Determiner"}},
        {PosTags::EX, {"EX", "Existantial"}},
        {PosTags::IN, {"IN", "Preposition or Conjunction, Subordinating"}},
        {PosTags::JJ, {"JJ", "Adjective or Numeral, Ordinal"}},
        {PosTags::JJR, {"JJR", "Adjective, Comparative"}},
        {PosTags::JJS, {"JJS", "Adjective, Superlative"}},
        {PosTags::LS, {"LS", "List Item Marker"}},
        {PosTags::MD, {"MD", "Modal Auxiliary"}},
        {PosTags::NN, {"NN", "Noun, Common, Singular or Mass"}},
        {PosTags::NNP, {"NNP", "Noun, Proper, Singular"}},
        {PosTags::NNS, {"NNS", "Noun, Common, Plural"}},
        {PosTags::PDT, {"PDT", "Pre-Determiner"}},
        {PosTags::POS, {"POS", "Genitive Marker"}},
        {PosTags::PRP, {"PRP", "Pronoun, Personal"}},
        {PosTags::PPP$, {"PPP$", "Pronoun, Possessive"}},
        {PosTags::RB, {"RB", "Adverb"}},
        {PosTags::RBR, {"RBR", "Adverb"}},
        {PosTags::RBS, {"RBS", "Adverb, Superlative"}},
        {PosTags::RP, {"RP", "Particle"}},
        {PosTags::TO, {"TO", "'To' as Preposition or Infinitive Marker"}},
        {PosTags::UH, {"UH", "Interjection"}},
        {PosTags::VB, {"VB", "Verb, Base Form"}},
        {PosTags::VBD, {"VBD", "Verb, Past Tense"}},
        {PosTags::VBG, {"VBG", "Verb, Present Participle or Gerund"}},
        {PosTags::VBN, {"VBN", "Verb, Past Participle"}},
        {PosTags::VBP, {"VBP", "Verb, Present Tense, Not 3rd Person Singular"}},
        {PosTags::VBZ, {"VBZ", "Verb, Present Tense, 3rd Person Singular"}},
        {PosTags::WDT, {"WDT", "WH-Determiner"}},
        {PosTags::WP, {"WP", "WH-Pronoun"}},
        {PosTags::WRB, {"WRB", "WH-Adverb"}},
        {PosTags::PONCT, {".", "Punctuation"}}
    };

    auto it = posTagDescriptions.find(tag);
    if (it != posTagDescriptions.end()) {
        return it->second; 
    } else {
        throw std::invalid_argument("Unknown PosTag");
    }
}
