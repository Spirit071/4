#ifndef SUBSTITUTIONTEXT_H
#define SUBSTITUTIONTEXT_H

#include "PlainText.h"

class SubstitutionText : public PlainText {
private:
    std::string dictionaryFileName;

public:
    SubstitutionText(const std::string& text, const std::string& dictionaryFileName);
    ~SubstitutionText() override;

    std::string encrypt() override;
    std::string decrypt() override;
};

#endif // SUBSTITUTIONTEXT_H
