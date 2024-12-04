#ifndef SHIFTTEXT_H
#define SHIFTTEXT_H

#include "PlainText.h"

class ShiftText : public PlainText {
private:
    int key;

public:
    ShiftText(const std::string& text, int key);
    ~ShiftText() override;

    std::string encrypt() override;
    std::string decrypt() override;
};

#endif // SHIFTTEXT_H
