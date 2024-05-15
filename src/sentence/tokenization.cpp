#include "sentence/tokenization.hh"

list<Token*> parseText(const string& text) {
    list<Token*> tokenList;

    regex wordRegex("\\b(?:\\w+(?:'\\w+)?|'\\w+)\\b|[^\\w\\s]"); // \b(?:\w+(?:'\w+)?|'\w+)\b|[^\w\s]
    sregex_iterator iter(text.begin(), text.end(), wordRegex);
    sregex_iterator end;

    while(iter != end) {
        tokenList.push_back(new Token((*(iter++)).str()));
    }

    return tokenList;
}