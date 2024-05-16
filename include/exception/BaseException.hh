#ifndef BASE_EXCEPTION_HH
#define BASE_EXCEPTION_HH

#include <exception>
#include <string>

using namespace std;

class BaseException : public exception {
public:
    BaseException(const string& message);
    virtual const char* what() const noexcept override;

private:
    string message;
};

#endif