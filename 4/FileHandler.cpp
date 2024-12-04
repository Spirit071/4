#include "FileHandler.h"

// Static method to read the content of the file into a string
std::string FileHandler::readFileToString(const std::string& fileName) {
    std::ifstream inFile(fileName);
    std::stringstream buffer;

    if (!inFile) {
        std::cerr << "Error opening file for reading: " << fileName << std::endl;
        return "";
    }

    buffer << inFile.rdbuf();  // Read file content into the stringstream
    inFile.close();
    return buffer.str();
}

// Static method to read words from an input file and write them to an output file
void FileHandler::writeWordsToFile(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inFile(inputFileName);
    std::ofstream outFile(outputFileName);

    if (!inFile) {
        std::cerr << "Error opening input file: " << inputFileName << std::endl;
        return;
    }
    if (!outFile) {
        std::cerr << "Error opening output file: " << outputFileName << std::endl;
        return;
    }

    std::string word;
    while (inFile >> word) {
        outFile << word << std::endl;  // Write each word to a new line in the output file
    }

    inFile.close();
    outFile.close();
}

// Static method to save text to an output file
void FileHandler::saveTextInFile(const std::string& text, const std::string& outputFileName) {
    std::ofstream outFile(outputFileName);

    if (!outFile) {
        std::cerr << "Error opening output file: " << outputFileName << std::endl;
        return;
    }

    outFile << text;  // Write the given text to the file
    outFile.close();
}
