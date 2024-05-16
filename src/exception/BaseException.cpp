#include "execption/BaseException.hh"

BaseException::BaseException(const string& message) : message(message) { }

const char* BaseException::what() const noexcept {
    return message.c_str();
}
