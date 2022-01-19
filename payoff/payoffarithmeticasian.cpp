#include "payoffarithmeticasian.h"

PayOffArithmeticAsian::PayOffArithmeticAsian(const std::vector<double> &LookAtTimes_, double DeliveryTime_, const PayOffWrapper &ThePayOff_)
    :
      PathDependent(LookAtTimes_),
      DeliveryTime(DeliveryTime_),
      ThePayOff(ThePayOff_),
      NumberOfTimes(LookAtTimes_.size())
{
}

unsigned long PayOffArithmeticAsian::MaxNumberOfCashFlow() const
{
    return 1UL;
}

std::vector<double> PayOffArithmeticAsian::PossibleCashFlowTimes() const
{
    std::vector<double> tmp(1UL);
    tmp[0] = DeliveryTime;
    return tmp;
}

unsigned long PayOffArithmeticAsian::CashFlows(const std::vector<double>&SpotValues,
                                            std::vector<CashFlow>& GeneratedFlows) const
{
    double sum = std::accumulate(SpotValues.begin(), SpotValues.end(), 0.0);
    double mean = sum/NumberOfTimes;
    GeneratedFlows[0].TimeIndex = 0UL;
    GeneratedFlows[0].Amount = ThePayOff(mean);
    return 1UL;
}

PathDependent* PayOffArithmeticAsian::clone() const
{
    return new PayOffArithmeticAsian(*this);
}
