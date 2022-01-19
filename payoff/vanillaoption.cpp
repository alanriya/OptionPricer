#include "vanillaoption.h"

VanillaOption::VanillaOption(const PayOffWrapper &payoff_, double expiry_) : payoff(payoff_), expiry(expiry_)
{

}

double VanillaOption::getExpiry() const
{
    return expiry;
}

double VanillaOption::OptionPayOff(double spot) const
{
    return payoff(spot);
}
