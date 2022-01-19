#ifndef VANILLAOPTION_H
#define VANILLAOPTION_H

#include "payoffwrapper.h"

class VanillaOption
{
public:
    VanillaOption(const PayOffWrapper &payoff_, double expiry_);
    double getExpiry() const;
    double OptionPayOff(double spot) const;
private:
    double expiry;
    PayOffWrapper payoff;
};
#endif // VANILLAOPTION_H
