#include "exception/list/api/InvalidApiResponseException.hh"

InvalidApiResponseException::InvalidApiResponseException(const string& message)
    : BaseException(message) { }

InvalidApiResponseException::InvalidApiResponseException()
    : BaseException("Invalid Api Response Exception.") { }    