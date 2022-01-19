#ifndef PAYOFFWRAPPER_H
#define PAYOFFWRAPPER_H


#include "payoff.h"

class PayOffWrapper
{
public:
    PayOffWrapper(const PayOff &innerPayOff);
    PayOffWrapper(const PayOffWrapper &original);
    inline double operator()(double spot) const;
    ~PayOffWrapper();
    PayOffWrapper& operator=(const PayOffWrapper &original);
private:
    PayOff* payoffPtr;
};

inline double PayOffWrapper::operator()(double spot) const {
    return payoffPtr->operator()(spot);
}
#endif // PAYOFFWRAPPER_H
