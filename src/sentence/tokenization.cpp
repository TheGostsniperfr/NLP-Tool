#include "sentence/tokenization.hh"

list<Token> parseText(const string& text) {
    list<Token> tokenList;

    regex regex("\\b(?:\\w+(?:'\\w+)?|'\\w+)\\b|[^\\w\\s]"); // \b(?:\w+(?:'\w+)?|'\w+)\b|[^\w\s]
    sregex_token_iterator iter(text.begin(), text.end(), regex, -1);
    sregex_token_iterator end;

    while(iter != end) {
        tokenList.push_back(Token(*iter));
    }

    return tokenList;
}