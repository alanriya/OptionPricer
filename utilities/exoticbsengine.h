#ifndef EXOTICBSENGINE_H
#define EXOTICBSENGINE_H
#include "utilities/exoticengine.h"
#include "utilities/randombase.h"
#include "utilities/process.h"


class ExoticBSEngine : public ExoticEngine
{
public:
    ExoticBSEngine(const Wrapper<PathDependent>& TheProduct_,
                   const Parameters& R_,
                   const Parameters& D_,
                   const Parameters& Vol_,
                   const Wrapper<RandomBase>& TheGenerator_,
                   double Spot_);
    virtual void GetOnePath(std::vector<double>& SpotValues);
    virtual ~ExoticBSEngine(){}
private:
    Wrapper<RandomBase> TheGenerator;
    std::vector<double> Drifts;
    std::vector<double> StandardDeviations;
    double LogSpot;
    unsigned long NumberOfTimes;
    std::vector<double> Variates;
};
#endif // EXOTICBSENGINE_H
