#ifndef TOKENIZATION_H
#define TOKENIZATION_H

#include <string>
#include <list>
#include <regex>

#include "token/Token.hh"

using namespace std;

list<Token> parseText(const string& text);


#endif