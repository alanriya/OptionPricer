#ifndef PAYOFFGEOMETRICASIAN_H
#define PAYOFFGEOMETRICASIAN_H

#include "pathdependent.h"
#include "payoffwrapper.h"
#include <vector>
#include <algorithm>
#include <numeric>

class PayOffGeometricAsian : public PathDependent {
public:
    PayOffGeometricAsian(const std::vector<double>& LookAtTimes_,
                         double DeliveryTime_,
                         const PayOffWrapper& ThePayOff_);
    virtual unsigned long MaxNumberOfCashFlow() const;
    virtual std::vector<double> PossibleCashFlowTimes() const;
    virtual unsigned long CashFlows(const std::vector<double>& SpotValues,
                                    std::vector<CashFlow>& GeneratedFlows) const;
    virtual ~PayOffGeometricAsian(){}
    virtual PathDependent* clone() const;
private:
    double DeliveryTime;
    PayOffWrapper ThePayOff;
    unsigned long NumberOfTimes;
};

#endif // PAYOFFGEOMETRICASIAN_H


