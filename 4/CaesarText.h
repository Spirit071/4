#ifndef CAESARTEXT_H
#define CAESARTEXT_H

#include "ShiftText.h"

class CaesarText : public ShiftText {
public:
    CaesarText(const std::string& text);
    ~CaesarText();
};

#endif // CAESARTEXT_H
