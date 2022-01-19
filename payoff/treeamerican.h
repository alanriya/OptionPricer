#ifndef TREEAMERICAN_H
#define TREEAMERICAN_H

#include "payoff/treeproduct.h"
#include "payoff/payoffwrapper.h"
#include "payoff/payofffactory.h"
#include <algorithm>

class TreeAmerican : public TreeProduct
{
public:
    TreeAmerican(double FinalTime,
                const PayOffWrapper& ThePayOff_);
    virtual TreeProduct* clone() const;
    virtual double FinalPayOff(double Spot) const;
    virtual double PreFinalValue(double Spot,
                                 double Time,
                                 double DiscountedFutureValue) const;
    virtual ~TreeAmerican(){}
private:
    PayOffWrapper ThePayOff;
};

#endif // TREEAMERICAN_H
