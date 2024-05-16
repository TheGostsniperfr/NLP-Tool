#ifndef INVALID_FACTORY_BUILDER_PARAMETERS_EXCEPTION_HH
#define INVALID_FACTORY_BUILDER_PARAMETERS_EXCEPTION_HH

#include "exception/BaseException.hh"

class InvalidFactoryBuilderParametersException : public BaseException {
public:
    InvalidFactoryBuilderParametersException(const string& message);
    InvalidFactoryBuilderParametersException();
};

#endif