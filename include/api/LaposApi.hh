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

struct PosTagInfo
{
    std::string tagName;       
    std::string description;   
};

vector<pair<string, PosTags>> getPosTagText(const string& text);
void printPosTagText(vector<pair<string, PosTags>> posTagText);
PosTags getPosTagFromToken(const string& tag);
PosTagInfo getPosTagInfo(PosTags tag);

#endif
