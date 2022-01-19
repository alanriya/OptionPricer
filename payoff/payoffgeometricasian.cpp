#include "payoffgeometricasian.h"


PayOffGeometricAsian::PayOffGeometricAsian(const std::vector<double> &LookAtTimes_, double DeliveryTime_, const PayOffWrapper &ThePayOff_)
    :
      PathDependent(LookAtTimes_),
      DeliveryTime(DeliveryTime_),
      ThePayOff(ThePayOff_),
      NumberOfTimes(LookAtTimes_.size())
{
}

unsigned long PayOffGeometricAsian::MaxNumberOfCashFlow() const
{
    return 1UL;
}

std::vector<double> PayOffGeometricAsian::PossibleCashFlowTimes() const
{
    std::vector<double> tmp(1UL);
    tmp[0] = DeliveryTime;
    return tmp;
}

unsigned long PayOffGeometricAsian::CashFlows(const std::vector<double>&SpotValues,
                                            std::vector<CashFlow>& GeneratedFlows) const
{

    double SpotSize = SpotValues.size();
    double result = 1.0;
    for (double spot : SpotValues){
        result *= spot;
    }
    double mean = pow(result, 1/SpotSize);
    GeneratedFlows[0].TimeIndex = 0UL;
    GeneratedFlows[0].Amount = ThePayOff(mean);
    return 1UL;
}

PathDependent* PayOffGeometricAsian::clone() const
{
    return new PayOffGeometricAsian(*this);
}
