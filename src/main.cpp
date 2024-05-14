#include <iostream>
#include <vector>

#include "api/LaposApi.cpp"
#include "factory/Factory.cpp"
#include "factory/FactoryBuilder.cpp"

using namespace std;

void printHelp() {
    printf(
        "NLP-TOOL :\n" 
        "[-t/-text] [input text]     // Input text for POS tagging\n" 
        "[-v/-verbose]               // Turn on verbose mode\n"
    );
}

int main(int argc, char* argv[]) {
    // Get user textInput input
    vector<string> args(argv, argv + argc);
    bool verbose = false;
    string textInput = "";
    
    // Check flags
    for(size_t i = 0; i < args.size(); i++) {
        if(args[i] == "-v" || args[i] == "-verbose") {
            verbose = true;
        }

        if(args[i] == "-t" || args[i] == "-textInput") {
            textInput = args[i+1];
        }
        if(argc <= 1 || args[0] == "help") {
            printHelp();
            return 0;
        }
    }

    if(textInput == "") {
        printHelp();
        return 0;
    }


    FactoryBuilder fb = FactoryBuilder("Hello world ! I'm John. Is John's phone on the table?");
    Factory factory = fb.build();

    cout << factory.getSentence().toString();

    // Transform textInput input in POS Tagging (via lapos)
    LaposApi* api = new LaposApi(textInput, verbose);
    api->run();

    // Free memory
    delete api;

    return 0;
}