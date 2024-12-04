#ifndef SHIFTTEXT_H
#define SHIFTTEXT_H

#include "PlainText.h"

class ShiftText : public PlainText {
private:
    int key;

public:
    ShiftText(const std::string& text, int key);
    ~ShiftText();

    static std::string encrypt(const std::string& text, int key);
    static std::string decrypt(const std::string& text, int key);

    std::string encrypt();
    std::string decrypt();
};

#endif // SHIFTTEXT_H
