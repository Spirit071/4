#ifndef CAESARTEXT_H
#define CAESARTEXT_H

#include "ShiftText.h"

class CaesarText : public ShiftText {
public:
    CaesarText(const std::string& text); // Constructor
    ~CaesarText() override;

    std::string encrypt() override;      // Override encrypt
    std::string decrypt() override;      // Override decrypt
};

#endif // CAESARTEXT_H
