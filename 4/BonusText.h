#ifndef BONUSTEXT_H
#define BONUSTEXT_H

#include "PlainText.h"

class BonusText : public PlainText {
public:
    BonusText(const std::string& text);
    ~BonusText() override;

    std::string decrypt(const std::string& key) override;
};

#endif // BONUSTEXT_H
