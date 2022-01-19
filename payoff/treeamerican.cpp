#include "treeamerican.h"


TreeAmerican::TreeAmerican(double FinalTime, const PayOffWrapper &ThePayOff_)
    : TreeProduct(FinalTime), ThePayOff(ThePayOff_)
{

}

TreeProduct *TreeAmerican::clone() const
{
    return new TreeAmerican(*this);
}

double TreeAmerican::FinalPayOff(double Spot) const
{
    return ThePayOff(Spot);
}

double TreeAmerican::PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const
{
  return std::max(ThePayOff(Spot), DiscountedFutureValue);
}
