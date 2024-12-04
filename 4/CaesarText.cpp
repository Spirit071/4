#include "CaesarText.h"
#include "PlainText.h"

CaesarText::CaesarText(const std::string& text) : ShiftText(text, 3) {
    algorithm = "CaesarText";
}

CaesarText::~CaesarText() {}
