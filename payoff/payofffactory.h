#ifndef PAYOFFFACTORY_H
#define PAYOFFFACTORY_H
#include "payoff/payoff.h"
#include <map>
#include <string>


class PayOffFactory
{
public:
    typedef PayOff* (*CreatePayOffFunction)(double );
    static PayOffFactory& Instance();
    void RegisterPayOff(std::string, CreatePayOffFunction);
    PayOff* CreatePayOff(std::string PayOffId,double Strike);
    ~PayOffFactory(){};

private:
    std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
    PayOffFactory(){}
    PayOffFactory(const PayOffFactory&){}
    PayOffFactory& operator=(const PayOffFactory&){ return *this;}
};

#endif // PAYOFFFACTORY_H
