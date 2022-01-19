#ifndef TREESIMULATOR_H
#define TREESIMULATOR_H

#include <string>
#include <vector>
#include <memory>
#include "payoff/payoff.h"
#include "utilities/parameters.h"
#include "payoff/treeamerican.h"
#include "payoff/binomialtree.h"


class TreeSimulator
{
public:
    TreeSimulator();
    void runSimulation();

    const std::string &type() const;
    void setType(const std::string &newType);

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

    double d() const;
    void setD(double newD);

    double steps() const;
    void setSteps(double newSteps);

    double results() const;
    void setResults(double newResults);

private:
    std::string m_type;
    double m_S;
    double m_K;
    double m_sigma;
    double m_r;
    double m_T;
    double m_d;
    double m_steps;
    double m_results; // store the results.
};

#endif // TREESIMULATOR_H
