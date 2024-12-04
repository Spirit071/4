#include "PlainText.h"

PlainText::PlainText(const std::string& text) : text(text), isEncrypted(false) {}

PlainText::~PlainText() {}

bool PlainText::isEncrypted() const {
    return isEncrypted;
}

std::string PlainText::getText() const {
    return text;
}
