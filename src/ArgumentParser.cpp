#include "../include/ArgumentParser.h"
#include <getopt.h>
#include <cstring>
#include <iostream>

ArgumentParser::ArgumentParser(int argc, char *argv[]) : argc(argc), argv(argv), recursive(false), caseInsensitive(false) {
    parseArguments();
}

void ArgumentParser::parseArguments() {
    int opt;
    while ((opt = getopt(argc, argv, "Ri")) != -1) {
        switch (opt) {
            case 'R':
                recursive = true;
                break;
            case 'i':
                caseInsensitive = true;
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " [-R] [-i] searchpath filename1 [filename2] ... [filenameN]" << std::endl;
                exit(EXIT_FAILURE);
        }
    }

    if (optind < argc) {
        searchPath = argv[optind++];
    }

    while (optind < argc) {
        fileNames.push_back(argv[optind++]);
    }

    if (searchPath.empty() || fileNames.empty()) {
        std::cerr << "Usage: " << argv[0] << " [-R] [-i] searchpath filename1 [filename2] ... [filenameN]" << std::endl;
        exit(EXIT_FAILURE);
    }
}

bool ArgumentParser::isRecursive() const {
    return recursive;
}

bool ArgumentParser::isCaseInsensitive() const {
    return caseInsensitive;
}

std::string ArgumentParser::getSearchPath() const {
    return searchPath;
}

std::vector<std::string> ArgumentParser::getFileNames() const {
    return fileNames;
}
