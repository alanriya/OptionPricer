#ifndef PAYOFFARITHMETICASIAN_H
#define PAYOFFARITHMETICASIAN_H
#include "pathdependent.h"
#include "payoffwrapper.h"
#include <vector>
#include <algorithm>
#include <numeric>

class PayOffArithmeticAsian: public PathDependent {
public:
    PayOffArithmeticAsian(const std::vector<double>& LookAtTimes_,
                         double DeliveryTime_,
                         const PayOffWrapper& ThePayOff_);
    virtual unsigned long MaxNumberOfCashFlow() const;
    virtual std::vector<double> PossibleCashFlowTimes() const;
    virtual unsigned long CashFlows(const std::vector<double>& SpotValues,
                                    std::vector<CashFlow>& GeneratedFlows) const;
    virtual ~PayOffArithmeticAsian(){}
    virtual PathDependent* clone() const;
private:
    double DeliveryTime;
    PayOffWrapper ThePayOff;
    unsigned long NumberOfTimes;
};

#endif // PAYOFFARITHMETICASIAN_H
