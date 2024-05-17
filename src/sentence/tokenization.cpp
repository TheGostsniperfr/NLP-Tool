#include "sentence/tokenization.hh"

list<Token*> parseText(const string& text) {
    list<Token*> tokenList;

    regex wordRegex("\\b(?:\\w+(?:'\\w+)?|'\\w+)\\b|[^\\w\\s]|\\s"); // \b(?:\w+(?:'\w+)?|'\w+)\b|[^\w\s]|\s
    sregex_iterator iter(text.begin(), text.end(), wordRegex);
    sregex_iterator end;

    int wordId = 0;

    while(iter != end) {
        Token* token = new Token((*(iter++)).str(), wordId++);

        // check space
        if(token->getOriginalString() == " ") {
            token->setPosTag(SPACE);
        }

        tokenList.push_back(token);
    }

    return tokenList;
}