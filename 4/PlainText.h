#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include <string>

class PlainText {
protected:
    std::string text;
    bool isEnc;

public:
    PlainText(const std::string& text);
    virtual ~PlainText();

    bool isEncrypted() const;
    std::string getText() const;

    static int numOfTexts;
};

#endif // PLAINTEXT_H
