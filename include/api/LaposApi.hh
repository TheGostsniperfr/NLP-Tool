#ifndef LAPOS_API_H
#define LAPOS_API_H

#include "token/IPosTags.hh"

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;



vector<pair<string, PosTags>> getPosTagText(const string& text);
void printPosTagText(vector<pair<string, PosTags>> posTagText);


#endif
