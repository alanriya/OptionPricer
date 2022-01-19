#include "payoff/payofffactory.h"
#include <iostream>

void PayOffFactory::RegisterPayOff(std::string PayOffId,
                                   CreatePayOffFunction CreatorFunction)
{
    TheCreatorFunctions.insert(std::pair<std::string,CreatePayOffFunction>
                               (PayOffId,CreatorFunction));
}

PayOff* PayOffFactory:: CreatePayOff(std::string PayOffId,
                                    double Strike)
{
    std::map<std::string, CreatePayOffFunction>::const_iterator
            i = TheCreatorFunctions.find(PayOffId);
    if (i == TheCreatorFunctions.end()){
        std::cout << PayOffId << " is an unknown payoff" << std::endl;
        return nullptr;
    }
    return (i->second)(Strike);
}

PayOffFactory& PayOffFactory::Instance()
{
    static PayOffFactory theFactory;
    return theFactory;
}
