#include "../include/FileFinder.h"
#include <cstdio>

FileFinder::FileFinder(const std::string &searchPath, bool recursive, bool caseInsensitive)
    : searchPath(searchPath), recursive(recursive), caseInsensitive(caseInsensitive) {}

std::vector<std::string> FileFinder::findFiles(const std::string &fileName) const {
    std::vector<std::string> results;
    
    // Simulate searching with printf
    printf("Searching for file: %s\n", fileName.c_str());
    printf("Search path: %s\n", searchPath.c_str());
    printf("Recursive: %s\n", recursive ? "true" : "false");
    printf("Case Insensitive: %s\n", caseInsensitive ? "true" : "false");
    
    // Simulate finding some files
    results.push_back(searchPath + "/mock_result1.txt");
    results.push_back(searchPath + "/mock_result2.txt");
    
    return results;
}
