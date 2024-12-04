#include "PlainText.h"
#include "ShiftText.h"
#include "CaesarText.h"
#include "SubstitutionText.h"
#include "FileHandler.h"
#include <iostream>

int main() {
    // Testing the text encryption/decryption
    PlainText pt("Hello");
    std::cout << "PlainText: " << pt.getText() << std::endl;

    ShiftText st("Hello", 5);
    std::cout << "ShiftText Encrypted: " << st.getText() << std::endl;
    std::cout << "ShiftText Decrypted: " << st.decrypt() << std::endl;

    CaesarText ct("Hello");
    std::cout << "CaesarText Encrypted: " << ct.getText() << std::endl;
    std::cout << "CaesarText Decrypted: " << ct.decrypt() << std::endl;

    SubstitutionText sub("Hello", "dictionary.csv");
    std::cout << "SubstitutionText Encrypted: " << sub.getText() << std::endl;
    std::cout << "SubstitutionText Decrypted: " << sub.decrypt() << std::endl;

    // Testing the static field for the number of instances
    std::cout << "Number of PlainText instances created: " << PlainText::numOfTexts << std::endl;

    // FileHandler Testing

    // Test 1: Read file content to string
    std::string inputFile = "txt.example"; // Ensure this file exists with content
    std::string fileContent = FileHandler::readFileToString(inputFile);
    std::cout << "\nContent of " << inputFile << ":\n" << fileContent << std::endl;

    // Test 2: Write words from input file to output file
    std::string outputFile = "output.txt";
    FileHandler::writeWordsToFile(inputFile, outputFile);
    std::cout << "\nWords from " << inputFile << " written to " << outputFile << std::endl;

    // Test 3: Save text to file
    std::string textToSave = "This is some text to be saved in a file.";
    std::string saveFile = "savedText.txt";
    FileHandler::saveTextInFile(textToSave, saveFile);
    std::cout << "\nText saved to " << saveFile << std::endl;

    return 0;
}
