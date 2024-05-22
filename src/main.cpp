#include <iostream>
#include <vector>

#include "factory/Factory.hh"
#include "factory/FactoryBuilder.hh"

#include "preMatching/list/ContractionModifier.hh"
#include "preMatching/list/UrlModifier.hh"
#include "preMatching/list/PonctModifier.hh"
#include "preMatching/list/LaposApiModifier.hh"

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

    FactoryBuilder* fb = new FactoryBuilder();
    fb->withPreMatchingModifier(new ContractionModifier());
    fb->withPreMatchingModifier(new UrlModifier());
    fb->withPreMatchingModifier(new PonctModifier());
    fb->withPreMatchingModifier(new LaposApiModifier());

    Factory* factory = fb->build();

    Sentence* sentence = factory->run(textInput, verbose);

    cout << sentence->toString() << endl;
    cout << sentence->toStringPosProcess() << endl;

    cout << sentence->toStringWithDebug() << endl;
    cout << sentence->toStringPosProcessWithDebug();

    // Free memory
    delete fb;
    delete factory;
    delete sentence;

    return 0;
}