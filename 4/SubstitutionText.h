#ifndef SUBSTITUTIONTEXT_H
#define SUBSTITUTIONTEXT_H

#include "PlainText.h"
#include <unordered_map>

class SubstitutionText : public PlainText {
private:
    std::unordered_map<char, char> dictionary;

public:
    SubstitutionText(const std::string& text, const std::string& dictionaryFileName);
    ~SubstitutionText();

    static std::string encrypt(const std::string& text, const std::unordered_map<char, char>& dictionary);
    static std::string decrypt(const std::string& text, const std::unordered_map<char, char>& dictionary);

    std::string encrypt();
    std::string decrypt();
};

#endif // SUBSTITUTIONTEXT_H
