#ifndef EXOTICENGINE_H
#define EXOTICENGINE_H
#include "utilities/wrapper.h"
#include "utilities/parameters.h"
#include "utilities/statistics.h"
#include "payoff/pathdependent.h"
#include <vector>

class ExoticEngine
{
public:
    ExoticEngine(const Wrapper<PathDependent>&TheProduct_, 
                const Parameters& r_);
    virtual void GetOnePath(std::vector<double>& SpotValues)=0;
    void DoSimulation(Statistics& TheGatherer, unsigned long NumberOfPaths);
    virtual ~ExoticEngine(){};
    double DoOnePath(const std::vector<double>& SpotValues) const;
private:
    Wrapper<PathDependent> TheProduct;
    Parameters r;
    mutable std::vector<double> Discounts;
    mutable std::vector<CashFlow> TheseCashFlows;
};

#endif // EXOTICENGINE_H
