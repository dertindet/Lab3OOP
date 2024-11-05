#include <exception>
#include <string>
#include <stdexcept>

class AppException : public std::exception {
protected:
    std::string message;

public:
    explicit AppException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class FileException : public AppException {
public:
    explicit FileException(const std::string& msg) : AppException("File Error: " + msg) {}
};

class InputException : public AppException {
public:
    explicit InputException(const std::string& msg) : AppException("Input Error: " + msg) {}
};


class InvalidChoiceException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid choice.";
    }
};
class IndexOutOfBoundsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Index out of bounds.\n";
    }
};