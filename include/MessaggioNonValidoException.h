#ifndef MESSAGGIONONVALIDOEXCEPTION_H
#define MESSAGGIONONVALIDOEXCEPTION_H

#include <exception>
#include <string>

class MessaggioNonValidoException : public std::exception {
private:
    std::string message;

public:
    explicit MessaggioNonValidoException(const std::string &msg) : message(msg) {}

    const char *what() const noexcept override {
        return message.c_str();
    }
};

#endif // MESSAGGIONONVALIDOEXCEPTION_H
