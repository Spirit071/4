#include "SubstitutionText.h"
#include <fstream>
#include <stdexcept>

SubstitutionText::SubstitutionText(const std::string& text, const std::string& dictionaryFileName) 
    : PlainText(text) {
    std::ifstream file(dictionaryFileName);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open dictionary file");
    }

    char plain, cipher;
    while (file >> plain >> cipher) {
        dictionary[plain] = cipher;
    }

    this->text = encrypt(text, dictionary);
    algorithm = "SubstitutionText";
}

SubstitutionText::~SubstitutionText() {}

std::string SubstitutionText::encrypt(const std::string& text, const std::unordered_map<char, char>& dictionary) {
    std::string result;
    for (char c : text) {
        if (dictionary.find(c) != dictionary.end()) {
            result += dictionary.at(c);
        } else {
            result += c;
        }
    }
    return result;
}

std::string SubstitutionText::decrypt(const std::string& text, const std::unordered_map<char, char>& dictionary) {
    std::unordered_map<char, char> reverseDict;
    for (const auto& pair : dictionary) {
        reverseDict[pair.second] = pair.first;
    }
    return encrypt(text, reverseDict);
}

std::string SubstitutionText::encrypt() {
    text = encrypt(text, dictionary);
    return text;
}

std::string SubstitutionText::decrypt() {
    text = decrypt(text, dictionary);
    return text;
}
