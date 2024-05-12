#include <iostream>
#include <vector>

#include "api/LaposApi.hh"

using namespace std;

void testGetPosTagText() {
    string text = "Apple/NNP is/VBZ looking/VBG at/IN buying/VBG U.K./NNP startup/VB for/IN billion/CD Autonomous/JJ cars/NNS shift/NN insurance/NN liability/NN toward/IN manufacturers/NNS San/NNP Francisco/NNP considers/NNS banning/VBG sidewalk/JJ delivery/NN robots/NNS London/NNP is/VBZ a/DT big/JJ city/NN in/IN the/DT United/NNP Kingdom/NNP ./.";
    vector<pair<string, PosTags>> responce = getPosTagText(text);
    printPosTagText(responce);

}

int main() {


    // Get user text input
    // string userTextInput;
    // getline(cin, userTextInput);

    // Transform text input in POS Tagging
    string out = getApiPOSTaggingResponse("Hello world.");
    cout << "out: " + out << endl;
    vector<pair<string, PosTags>> tags = getPosTagText(out);
    printPosTagText(tags);


    return 0;
}

