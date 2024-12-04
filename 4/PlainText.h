#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include <string>
#include <iostream>  // For std::ostream

class PlainText {
protected:
    std::string text;

public:
    PlainText(const std::string& text);
    virtual ~PlainText();

    std::string getText() const;

    static int numOfTexts;
    static std::string algorithm;

    // Member function for operator<<
    friend std::ostream& operator<<(std::ostream& os, const PlainText& pt);
};

#endif // PLAINTEXT_H
