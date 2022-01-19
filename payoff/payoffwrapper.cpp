#include "payoffwrapper.h"

PayOffWrapper::PayOffWrapper(const PayOffWrapper &original)
{
    payoffPtr = original.payoffPtr->clone();
}

PayOffWrapper::PayOffWrapper(const PayOff &innerPayOff)
{
    payoffPtr=innerPayOff.clone();
}

PayOffWrapper::~PayOffWrapper()
{
    delete payoffPtr;
}

PayOffWrapper &PayOffWrapper::operator=(const PayOffWrapper &original)
{
    if (this != &original){
        delete payoffPtr;
        payoffPtr = original.payoffPtr->clone();
    }
    return *this;
}
