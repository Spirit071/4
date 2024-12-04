#include "ShiftText.h"

ShiftText::ShiftText(const std::string& text, int key) 
    : PlainText(text), key(key) {
    this->text = encrypt(text, key);
    isEnc = true;
}

ShiftText::~ShiftText() {}

std::string ShiftText::encrypt(const std::string& text, int key) {
    std::string result;
    for (char c : text) {
        if (std::isalpha(c)) {
            char base = std::islower(c) ? 'a' : 'A';
            result += (c - base + key) % 26 + base;
        } else {
            result += c;
        }
    }
    return result;
}

std::string ShiftText::decrypt(const std::string& text, int key) {
    return encrypt(text, 26 - key); // Reverse the shift
}

std::string ShiftText::encrypt() {
    text = encrypt(text, key);
    isEnc = true;
    return text;
}

std::string ShiftText::decrypt() {
    text = decrypt(text, key);
    isEnc = false;
    return text;
}
