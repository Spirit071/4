#include "CaesarText.h"

CaesarText::CaesarText(const std::string& text) : ShiftText(text, 3) {}

CaesarText::~CaesarText() {}

std::string CaesarText::encrypt() {
    text = encrypt(text, 3);  // Caesar cipher uses key 3
    isEncrypted = true;
    return text;
}

std::string CaesarText::decrypt() {
    text = decrypt(text, 3);
    isEncrypted = false;
    return text;
}

std::string CaesarText::encrypt(const std::string& text) {
    return ShiftText::encrypt(text, 3);  // Using Caesar cipher's fixed key (3)
}

std::string CaesarText::decrypt(const std::string& text) {
    return ShiftText::decrypt(text, 3);  // Using Caesar cipher's fixed key (3)
}
