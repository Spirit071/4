#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class FileHandler {
public:
    // Static method to read the file content into a string
    static std::string readFileToString(const std::string& fileName);

    // Static method to read words from an input file and write them to an output file
    static void writeWordsToFile(const std::string& inputFileName, const std::string& outputFileName);

    // Static method to save text to an output file
    static void saveTextInFile(const std::string& text, const std::string& outputFileName);
};

#endif
