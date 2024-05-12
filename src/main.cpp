#include <iostream>
#include <vector>

#include "api/LaposApi.cpp"

using namespace std;

int main() {
    // Get user text input
    // string userTextInput;
    // getline(cin, userTextInput);

    // Transform text input in POS Tagging
    LaposApi* api = new LaposApi("Hello world !", true);
    api->run();

    delete api;

    return 0;
}

