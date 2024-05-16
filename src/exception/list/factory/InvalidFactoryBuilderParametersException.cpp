#include "exception/list/factory/InvalidFactoryBuilderParametersException.hh"

InvalidFactoryBuilderParametersException::InvalidFactoryBuilderParametersException(const string& message)
    : BaseException(message) { }

InvalidFactoryBuilderParametersException::InvalidFactoryBuilderParametersException()
    : BaseException("Invalid Factory Builder Parameters Exception.") { }    