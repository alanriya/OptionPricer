#ifndef PATHDEPENDENTMCSIMULATOR_H
#define PATHDEPENDENTMCSIMULATOR_H

#include <string>
#include <vector>
#include <memory>
#include "utilities/parkmiller.h"
#include "utilities/statisticsmean.h"
#include "utilities/antithetic.h"
#include "utilities/parameters.h"
#include "utilities/process.h"
#include "utilities/convergencetable.h"
#include "payoff/payofffactory.h"
#include "utilities/exoticengine.h"
#include "utilities/exoticbsengine.h"

#include "payoff/vanillaoption.h"
#include "payoff/payoffconstructible.h"
#include "payoff/payoffwrapper.h"
#include "payoff/pathdependentasian.h"
#include "payoff/payoffarithmeticasian.h"
#include "payoff/payoffgeometricasian.h"

class PathDependentMCSimulator
{
public:
    PathDependentMCSimulator();
    void runSimulation();
    void setParams(double S_, double K_, double sigma_, double r_, double d_, double T_, unsigned numSimulations, double steps_=1);

    // for returning the results;
    double S() const;
    void setS(double newS);

    double K() const;
    void setK(double newK);

    double sigma() const;
    void setSigma(double newSigma);

    double r() const;
    void setR(double newR);

    double T() const;
    void setT(double newT);

    double steps() const;
    void setSteps(double newSteps);

    const unsigned &simulations() const;
    void setSimulations(const unsigned &newSimulations);

    std::vector<std::vector<double> > results();

    double d() const;
    void setD(double newD);

    const std::string &type() const;
    void setType(const std::string &newType);

private:
    std::string m_type;
    double m_S;
    double m_K;
    double m_sigma;
    double m_r;
    double m_T;
    double m_d;
    double m_steps;
    unsigned m_simulations;
    std::vector<std::vector<double> > m_results;
};

#endif // PATHDEPENDENTMCSIMULATOR_H
