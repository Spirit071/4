#include "PlainText.h"
#include "ShiftText.h"
#include "CaesarText.h"
#include "SubstitutionText.h"
#include "FileHandler.h"
#include <iostream>
#include <fstream>  // for file checking

int main() {
    // Testing the text encryption/decryption
    PlainText pt("Hello");
    std::cout << pt << std::endl;

    ShiftText st("Hello", 5);
    std::cout << st << std::endl;

    CaesarText ct("Hello");
    std::cout << ct << std::endl;

    SubstitutionText sub("Hello", "dictionary.csv");
    std::cout << sub << std::endl;

	// print out all the decrypted data
	std::cout << "ShiftText Decrypted: " << st.decrypt() << std::endl;
    std::cout << "CaesarText Decrypted: " << ct.decrypt() << std::endl;
    std::cout << "SubstitutionText Decrypted: " << sub.decrypt() << std::endl;

    // Testing the static field for the number of instances
    std::cout << "Number of PlainText instances created: " << PlainText::numOfTexts << std::endl;

    // FileHandler Testing

    // Test 1: Read file content to string
    std::string inputFile = "txt.example"; // Ensure this file exists with content
    std::string fileContent = FileHandler::readFileToString(inputFile);
    std::cout << "\nContent of " << inputFile << ":\n" << fileContent << std::endl;

    // Check if the file exists
    std::ifstream testInputFile(inputFile);
    if (!testInputFile) {
        std::cout << "Error: Input file does not exist or cannot be opened." << std::endl;
    } else {
        std::cout << "Input file opened successfully." << std::endl;
    }

    // Test 2: Write words from input file to output file
    std::string outputFile = "output.txt";
    FileHandler::writeWordsToFile(inputFile, outputFile);
    std::cout << "\nWords from " << inputFile << " written to " << outputFile << std::endl;

    // Check if the output file exists
    std::ifstream testOutputFile(outputFile);
    if (!testOutputFile) {
        std::cout << "Error: Output file was not created or cannot be opened." << std::endl;
    } else {
        std::cout << "Output file created successfully." << std::endl;
    }

    // Test 3: Save text to file
    std::string textToSave = "This is some text to be saved in a file.";
    std::string saveFile = "savedText.txt";
    FileHandler::saveTextInFile(textToSave, saveFile);
    std::cout << "\nText saved to " << saveFile << std::endl;

    // Check if the saved file exists
    std::ifstream testSaveFile(saveFile);
    if (!testSaveFile) {
        std::cout << "Error: Saved file was not created or cannot be opened." << std::endl;
    } else {
        std::cout << "Saved file created successfully." << std::endl;
    }

    return 0;
}
