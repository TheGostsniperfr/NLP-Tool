#include <iostream>
#include <vector>

#include "api/list/LaposApi.hh"
#include "factory/Factory.hh"
#include "factory/FactoryBuilder.hh"

#include "preMatching/list/ContractionModifier.hh"
#include "preMatching/list/UrlModifier.hh"
#include "preMatching/list/PonctModifier.hh"

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

    string text = "My url is: https://www.youtube.com/watch?v=Ze_mWpklkKQ.Hey, y'all, I'm gonna go to the store 'cause I need some groceries. Could've gone yesterday, but didn't have time. Ain't it funny how things work out sometimes?";

    FactoryBuilder* fb = new FactoryBuilder();
    fb->withPosApi(new LaposApi());
    fb->withPreMatchingModifier(new ContractionModifier());
    fb->withPreMatchingModifier(new UrlModifier());
    fb->withPreMatchingModifier(new PonctModifier());

    Factory* factory = fb->build();

    Sentence* sentence = factory->run(text, verbose);

    cout << sentence->toString() << endl;
    cout << sentence->toStringPosProcess() << endl;

    cout << sentence->toStringWithDebug() << endl;
    cout << sentence->toStringPosProcessWithDebug();

    // Free memory
    // delete api;

    return 0;
}