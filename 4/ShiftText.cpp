#include "ShiftText.h"

ShiftText::ShiftText(const std::string& text, int key)
    : PlainText(text), _key(key) {}

ShiftText::~ShiftText() {}

std::string ShiftText::encrypt() {
    text = encrypt(text, _key);
    isEncrypted = true;
    return text;
}

std::string ShiftText::decrypt() {
    text = decrypt(text, _key);
    isEncrypted = false;
    return text;
}

std::string ShiftText::encrypt(const std::string& text, int key) {
    std::string encrypted = text;
    for (char& c : encrypted) {
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + key) % 26 + 'a';
        }
    }
    return encrypted;
}

std::string ShiftText::decrypt(const std::string& text, int key) {
    std::string decrypted = text;
    for (char& c : decrypted) {
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' - key + 26) % 26 + 'a';
        }
    }
    return decrypted;
}
