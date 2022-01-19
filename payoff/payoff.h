#ifndef PAYOFF_H
#define PAYOFF_H

#include <cmath>
#include <algorithm>

class PayOff
{
public:
    PayOff();
    virtual ~PayOff(){};
        // overloaded operator turns this to an abstract function.
        virtual double operator()(double S) const = 0;
        virtual PayOff* clone() const = 0;
    private:
};

class PayOffCall : public PayOff {
public:
    PayOffCall(double strike_);
    virtual double operator()(double spot) const;
    virtual ~PayOffCall();
    virtual PayOff* clone() const;
private:
    double strike;
};

class PayOffPut : public PayOff {
public:
    PayOffPut(double strike_);
    virtual double operator()(double spot) const;
    virtual ~PayOffPut();
    virtual PayOff* clone() const;
private:
    double strike;
};


#endif // PAYOFF_H
