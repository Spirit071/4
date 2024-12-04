#include <string>
#include "PlainText.h"

int PlainText::numOfTexts = 0;
std::string PlainText::algorithm = "Plain";

PlainText::PlainText(const std::string& text) : text(text) {
    numOfTexts++;
}

PlainText::~PlainText() {}

std::string PlainText::getText() const {
    return text;
}

// Implementing the << operator
std::ostream& operator<<(std::ostream& os, const PlainText& pt) {
    os << pt.algorithm << std::endl;
    os << pt.getText() << std::endl;
    return os;
}