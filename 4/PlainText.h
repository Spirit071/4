#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include <string>

class PlainText {
private:
    std::string text;
    bool isEncrypted;

public:
    PlainText(const std::string& text);
    virtual ~PlainText();

    bool isEncryptedStatus() const;
    std::string getText() const;

    virtual std::string encrypt() = 0;
    virtual std::string decrypt() = 0;
};

#endif // PLAINTEXT_H
