#include <iostream>
#include <vector>

#include "api/LaposApi.cpp"

using namespace std;

int main(int argc, char* argv[]) {
    // Get user textInput input
    vector<string> args(argv, argv + argc);
    bool verbose = false;
    string textInput;
    
    // Check flags
    for(size_t i = 0; i < args.size(); i++) {
        if(args[i] == "-v" || args[i] == "-verbose") {
            verbose = true;
        }

        if(args[i] == "-t" || args[i] == "-textInput") {
            textInput = args[i+1];
            cout << "textInput: " + textInput << endl;
        }
    }

    // Transform textInput input in POS Tagging (via lapos)
    LaposApi* api = new LaposApi(textInput, verbose);
    api->run();

    // Free memory
    delete api;

    return 0;
}

