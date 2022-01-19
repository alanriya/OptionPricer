#include "exoticengine.h"
#include <cmath>

ExoticEngine::ExoticEngine(const Wrapper<PathDependent>& TheProduct_,
                           const Parameters& r_):
    TheProduct(TheProduct_), r(r_), Discounts(TheProduct_->PossibleCashFlowTimes())
{
    for (unsigned long i = 0; i < Discounts.size(); i++){
        Discounts[i]=exp(-r.Integral(0.0,Discounts[i]));
    }
    TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlow());
}

void ExoticEngine::DoSimulation(Statistics &TheGatherer, unsigned long NumberOfPaths){
    std::vector<double> SpotValues(TheProduct->GetLookAtTimes().size());
    TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlow());
    double thisValue;

    for (unsigned i =0 ; i< NumberOfPaths; ++i){
        GetOnePath(SpotValues);
        thisValue = DoOnePath(SpotValues);
        TheGatherer.DumpOneResult(thisValue);
    }
    return ;
}

double ExoticEngine::DoOnePath(const std::vector<double>& SpotValues) const {
    unsigned long NumbersFlows = TheProduct->CashFlows(SpotValues, TheseCashFlows);
    double Value = 0.0;
    for (unsigned i=0; i<NumbersFlows; ++i){
        Value+=TheseCashFlows[i].Amount*Discounts[TheseCashFlows[i].TimeIndex];
    }
    return Value;
}
