#include <iostream>
#include <vector>

#include "api/list/LaposApi.hh"
#include "factory/Factory.hh"
#include "factory/FactoryBuilder.hh"

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

    string text = "Hello world ! I'm John. Is John's phone on the table?";

    FactoryBuilder* fb = new FactoryBuilder();
    fb->withPosApi(new LaposApi());
    

    Factory* factory = fb->build();
    
    cout << factory->run(text)->toString();



    // Free memory
    // delete api;

    return 0;
}