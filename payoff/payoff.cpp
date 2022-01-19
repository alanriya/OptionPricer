#include "payoff.h"

PayOff::PayOff()
{

}

// payoff for call option.
PayOffCall::PayOffCall(double strike_) : strike(strike_)
{

}

double PayOffCall::operator()(double spot) const
{
    return std::max(spot-strike, 0.0);
}

PayOffCall::~PayOffCall(){}

PayOff* PayOffCall::clone() const
{
    return new PayOffCall(*this);
}

// payoff for put option.
PayOffPut::PayOffPut(double strike_) : strike(strike_)
{

}

double PayOffPut::operator()(double spot) const
{
    return std::max(strike-spot, 0.0);
}

PayOffPut::~PayOffPut(){}

PayOff* PayOffPut::clone() const
{
    return new PayOffPut(*this);
}
