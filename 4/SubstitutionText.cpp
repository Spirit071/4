#include "SubstitutionText.h"
#include <fstream>
#include <sstream>
#include <unordered_map>

SubstitutionText::SubstitutionText(const std::string& text, const std::string& dictionaryFileName)
    : PlainText(text), _dictionaryFileName(dictionaryFileName) {}

SubstitutionText::~SubstitutionText() {}

std::string SubstitutionText::encrypt() {
    std::unordered_map<char, char> substitutionMap = loadDictionary(_dictionaryFileName);
    text = encrypt(text, substitutionMap);
    isEncrypted = true;
    return text;
}

std::string SubstitutionText::decrypt() {
    std::unordered_map<char, char> substitutionMap = loadDictionary(_dictionaryFileName);
    text = decrypt(text, substitutionMap);
    isEncrypted = false;
    return text;
}

std::unordered_map<char, char> SubstitutionText::loadDictionary(const std::string& dictionaryFileName) {
    std::unordered_map<char, char> substitutionMap;
    std::ifstream file(dictionaryFileName);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        char key, value;
        ss >> key >> value;
        substitutionMap[key] = value;
    }
    return substitutionMap;
}

std::string SubstitutionText::encrypt(const std::string& text, const std::unordered_map<char, char>& substitutionMap) {
    std::string encrypted = text;
    for (char& c : encrypted) {
        if (substitutionMap.find(c) != substitutionMap.end()) {
            c = substitutionMap.at(c);
        }
    }
    return encrypted;
}

std::string SubstitutionText::decrypt(const std::string& text, const std::unordered_map<char, char>& substitutionMap) {
    std::unordered_map<char, char> reverseMap;
    for (const auto& pair : substitutionMap) {
        reverseMap[pair.second] = pair.first;
    }

    std::string decrypted = text;
    for (char& c : decrypted) {
        if (reverseMap.find(c) != reverseMap.end()) {
            c = reverseMap.at(c);
        }
    }
    return decrypted;
}
