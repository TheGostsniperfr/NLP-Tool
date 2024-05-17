#include "preMatching/list/ContractionModifier.hh"

ContractionModifier::ContractionModifier() { }

vector<string> removeContraction(const string& word) {
    static const unordered_map<string, vector<string>> contractionsMap = {
        {"a'ight", {"alright"}},
        {"ain't", {"is", "not"}},
        {"amn't", {"am", "not"}},
        {"'n'", {"and"}},
        {"arencha", {"are", "not", "you"}},
        {"aren't", {"are", "not"}},
        {"'bout", {"about"}},
        {"can't", {"cannot"}},
        {"cap'n", {"captain"}},
        {"'cause", {"because"}},
        {"cuz", {"because"}},
        {"'cept", {"except"}},
        {"c'mon", {"come", "on"}},
        {"could've", {"could", "have"}},
        {"couldn't", {"could", "not"}},
        {"couldn't've", {"could", "not", "have"}},
        {"cuppa", {"cup", "of"}},
        {"daren't", {"dare", "not"}},
        {"dasn't", {"dare", "not"}},
        {"didn't", {"did", "not"}},
        {"doesn't", {"does", "not"}},
        {"don't", {"do", "not"}},
        {"dunno", {"do", "not", "know"}},
        {"d'ye", {"do", "you"}},
        {"d'ya", {"do", "you"}},
        {"e'en", {"even"}},
        {"e'er", {"ever"}},
        {"'em", {"them"}},
        {"everybody's", {"everybody", "is"}},
        {"everyone's", {"everyone", "is"}},
        {"everything's", {"everything", "is"}},
        {"finna", {"fixing", "to"}},
        {"fo'c'sle", {"forecastle"}},
        {"'gainst", {"against"}},
        {"g'day", {"good", "day"}},
        {"gimme", {"give", "me"}},
        {"giv'n", {"given"}},
        {"gi'z", {"give", "us"}},
        {"gonna", {"going", "to"}},
        {"gon't", {"go", "not"}},
        {"gotta", {"got", "to"}},
        {"hadn't", {"had", "not"}},
        {"had've", {"had", "have"}},
        {"hasn't", {"has", "not"}},
        {"haven't", {"have", "not"}},
        {"he'd", {"he", "would"}},
        {"he'll", {"he", "will"}},
        {"helluva", {"hell", "of", "a"}},
        {"yesn't", {"no"}},
        {"he's", {"he", "is"}},
        {"here's", {"here", "is"}},
        {"how'd", {"how", "did"}},
        {"howdy", {"how", "do", "you", "do"}},
        {"how'll", {"how", "will"}},
        {"how're", {"how", "are"}},
        {"how's", {"how", "is"}},
        {"i'd", {"i", "would"}},
        {"i'll", {"i", "will"}},
        {"i'm", {"i", "am"}},
        {"i'm'onna", {"i", "am", "going", "to"}},
        {"imma", {"i", "am", "going", "to"}},
        {"i'm'o", {"i", "am", "going", "to"}},
        {"i'm'na", {"i", "am", "going", "to"}},
        {"innit", {"isn't", "it"}},
        {"ion", {"i", "do", "not"}},
        {"i've", {"i", "have"}},
        {"isn't", {"is", "not"}},
        {"it'd", {"it", "would"}},
        {"it'll", {"it", "will"}},
        {"it's", {"it", "is"}},
        {"idunno", {"i", "do", "not", "know"}},
        {"kinda", {"kind", "of"}},
        {"lemme", {"let", "me"}},
        {"let's", {"let", "us"}},
        {"loven't", {"love", "not"}},
        {"ma'am", {"madam"}},
        {"mayn't", {"may", "not"}},
        {"may've", {"may", "have"}},
        {"methinks", {"i", "think"}},
        {"mightn't", {"might", "not"}},
        {"might've", {"might", "have"}},
        {"mine's", {"mine", "is"}},
        {"mustn't", {"must", "not"}},
        {"mustn't've", {"must", "not", "have"}},
        {"must've", {"must", "have"}},
        {"'neath", {"beneath"}},
        {"needn't", {"need", "not"}},
        {"nal", {"and", "all"}},
        {"ne'er", {"never"}},
        {"o'clock", {"of", "the", "clock"}},
        {"o'er", {"over"}},
        {"ol'", {"old"}},
        {"ought've", {"ought", "have"}},
        {"oughtn't", {"ought", "not"}},
        {"oughtn't've", {"ought", "not", "have"}},
        {"'round", {"around"}},
        {"'s", {"is"}},
        {"shalln't", {"shall", "not"}},
        {"shan'", {"shall", "not"}},
        {"shan't", {"shall", "not"}},
        {"she'd", {"she", "would"}},
        {"she'll", {"she", "will"}},
        {"she's", {"she", "is"}},
        {"should've", {"should", "have"}},
        {"shouldn't", {"should", "not"}},
        {"shouldn't've", {"should", "not", "have"}},
        {"somebody's", {"somebody", "is"}},
        {"someone's", {"someone", "is"}},
        {"something's", {"something", "is"}},
        {"so're", {"so", "are"}},
        {"so's", {"so", "is"}},
        {"so've", {"so", "have"}},
        {"that'll", {"that", "will"}},
        {"that're", {"that", "are"}},
        {"that's", {"that", "is"}},
        {"that'd", {"that", "would"}},
        {"there'd", {"there", "would"}},
        {"there'll", {"there", "will"}},
        {"there're", {"there", "are"}},
        {"there's", {"there", "is"}},
        {"these're", {"these", "are"}},
        {"these've", {"these", "have"}},
        {"they'd", {"they", "would"}},
        {"they'll", {"they", "will"}},
        {"they're", {"they", "are"}},
        {"they've", {"they", "have"}},
        {"this's", {"this", "is"}},
        {"those're", {"those", "are"}},
        {"those've", {"those", "have"}},
        {"'thout", {"without"}},
        {"'til", {"until"}},
        {"'tis", {"it", "is"}},
        {"to've", {"to", "have"}},
        {"tryna", {"trying", "to"}},
        {"'twas", {"it", "was"}},
        {"'tween", {"between"}},
        {"w'all", {"we", "all"}},
        {"w'at", {"we", "at"}},
        {"wanna", {"want", "to"}},
        {"wasn't", {"was", "not"}},
        {"we'd", {"we", "would"}},
        {"we'll", {"we", "will"}},
        {"we're", {"we", "are"}},
        {"we've", {"we", "have"}},
        {"weren't", {"were", "not"}},
        {"whatcha", {"what", "are", "you"}},
        {"what'd", {"what", "did"}},
        {"what'll", {"what", "will"}},
        {"what're", {"what", "are"}},
        {"what's", {"what", "is"}},
        {"what've", {"what", "have"}},
        {"when'd", {"when", "did"}},
        {"when's", {"when", "is"}},
        {"where'd", {"where", "did"}},
        {"where'll", {"where", "will"}},
        {"where're", {"where", "are"}},
        {"where's", {"where", "is"}},
        {"where've", {"where", "have"}},
        {"which'd", {"which", "did"}},
        {"which'll", {"which", "will"}},
        {"which're", {"which", "are"}},
        {"which's", {"which", "is"}},
        {"which've", {"which", "have"}},
        {"who'd", {"who", "did"}},
        {"who'll", {"who", "will"}},
        {"who're", {"who", "are"}},
        {"who's", {"who", "is"}},
        {"who've", {"who", "have"}},
        {"why'd", {"why", "did"}},
        {"why're", {"why", "are"}},
        {"why's", {"why", "is"}},
        {"won't", {"will", "not"}},
        {"would've", {"would", "have"}},
        {"wouldn't", {"would", "not"}},
        {"wouldn't've", {"would", "not", "have"}},
        {"y'all", {"you", "all"}},
        {"y'at", {"you", "at"}},
        {"yesm", {"yes", "ma'am"}},
        {"y'know", {"you", "know"}},
        {"you'd", {"you", "would"}},
        {"you'll", {"you", "will"}},
        {"you're", {"you", "are"}},
        {"you've", {"you", "have"}}
    };

    string wordLower = word;
    transform(wordLower.begin(), wordLower.end(), wordLower.begin(), ::tolower);

    auto it = contractionsMap.find(wordLower);
    if (it != contractionsMap.end()) {
        return it->second;
    } else {
        return {};
    }
}

void ContractionModifier::run(Sentence* sentence, bool verbose) {
    const auto& tokenSentence = sentence->getTokenSentence();

    auto it = tokenSentence.begin();
    while (it != tokenSentence.end()) {
        Token* token = *it;
        vector<string> resp = removeContraction(token->getPostProcessingString());
        if (!resp.empty()) {
            if (resp.size() == 1) {

                token->setPosProcessingString(resp[0]);
            } else {
                auto insertPos = it;
                for (const auto& newWord : resp) {
                    Token* newToken = new Token(token);
                    newToken->setPosProcessingString(newWord);
                    
                    insertPos = sentence->getTokenSentence().insert(++insertPos, newToken);

                    if(&newWord != &resp.back()) {
                        Token* spaceToken = new Token(" ", token->getWordId());
                        spaceToken->setPosTag(SPACE);
                        insertPos = sentence->getTokenSentence().insert(++insertPos, spaceToken);
                    }

                }
                it = sentence->getTokenSentence().erase(it);
                continue;
            }
        }

        ++it;
    }
}