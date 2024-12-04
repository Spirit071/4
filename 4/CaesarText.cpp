#include "CaesarText.h"

CaesarText::CaesarText(const std::string& text) : ShiftText(text, 3) {}

CaesarText::~CaesarText() {}
