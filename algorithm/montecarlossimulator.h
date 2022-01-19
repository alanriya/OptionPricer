#ifndef MONTECARLOSSIMULATOR_H
#define MONTECARLOSSIMULATOR_H

#include <string>
#include <vector>
#include <iostream>

#include "utilities/parkmiller.h"
#include "utilities/statisticsmean.h"
#include "utilities/antithetic.h"
#include "utilities/parameters.h"
#include "utilities/process.h"
#include "utilities/convergencetable.h"

#include "payoff/payofffactory.h"
#include "payoff/vanillaoption.h"
#include "payoff/payoffconstructible.h"
#include "payoff/payoffwrapper.h"

class MonteCarlosSimulator
{
public:
    MonteCarlosSimulator();
    void runSimulation();

    // for returning the results;
    std::vector<std::vector<double> > results();

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

    const unsigned &simulations() const;
    void setSimulations(const unsigned &newSimulations);

    void setParams(double S_, double K_, double sigma_, double r_, double T, unsigned numSimulations, double steps_=1);
    const std::string &type() const;
    void setType(const std::string &newType);

private:
    std::string m_type;
    double m_S;
    double m_K;
    double m_sigma;
    double m_r;
    double m_T;
    double m_steps = 1;
    unsigned m_simulations;
    std::vector<std::vector<double> > m_results;
};

#endif // MONTECARLOSSIMULATOR_H
