#ifndef INVALID_API_RESPONSE_EXCEPTION_HH
#define INVALID_API_RESPONSE_EXCEPTION_HH

#include "exception/BaseException.hh"

class InvalidApiResponseException : public BaseException {
public:
    InvalidApiResponseException(const string& message);
    InvalidApiResponseException();
};

#endif