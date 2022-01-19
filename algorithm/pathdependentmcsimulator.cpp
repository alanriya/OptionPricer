#include "algorithm/pathdependentmcsimulator.h"
#include <QDebug>
PathDependentMCSimulator::PathDependentMCSimulator()
{

}

void PathDependentMCSimulator::runSimulation()
{
    std::vector<double> times(m_steps);
    for (unsigned long i=0; i < m_steps; i++){
        times[i] = (i+1.0)*m_T/m_steps;
    }
    ParametersConstant VolParam(m_sigma);
    ParametersConstant rParam(m_r);
    ParametersConstant dParam(m_d);
    // need to come up with a way to map to different option pricing formula.
    std::string optionType;
    PayOff* PayOffPtr = nullptr;
    PathDependent* theOption = nullptr;
    if (m_type == "Geometric Asian Call"){
      PayOffPtr = PayOffFactory::Instance().CreatePayOff("Call", m_K);
      theOption = new PayOffGeometricAsian(times, m_T, *PayOffPtr);
    } else if (m_type == "Geometric Asian Put"){
       PayOffPtr = PayOffFactory::Instance().CreatePayOff("Put", m_K);
      theOption = new PayOffGeometricAsian(times, m_T, *PayOffPtr);
    } else if (m_type == "Arithmetic Asian Call"){
      PayOffPtr = PayOffFactory::Instance().CreatePayOff("Call", m_K);
      theOption = new PayOffArithmeticAsian(times, m_T, *PayOffPtr);
    } else if (m_type == "Arithmetic Asian Put"){
      PayOffPtr = PayOffFactory::Instance().CreatePayOff("Put", m_K);
      theOption = new PayOffArithmeticAsian(times, m_T, *PayOffPtr);
    }
    StatisticsMean gather;
    ConvergenceTable gatherer(gather);
    RandomParkMiller generator(m_steps);
    AntiThetic generator2(generator);
    generator2.ResetDimensionality(1);
    ExoticBSEngine theEngine(*theOption, rParam, dParam, VolParam, generator2, m_S);
    theEngine.DoSimulation(gatherer, m_simulations);
    m_results = gatherer.GetResultsSoFar();
    delete PayOffPtr;
    delete theOption;
    return;
}

void PathDependentMCSimulator::setParams(double S_, double K_, double sigma_, double r_, double d_, double T_, unsigned numSimulations, double steps_)
{
    m_S = S_;
    m_K = K_;
    m_sigma = sigma_;
    m_r = r_;
    m_T = T_;
    m_d = d_;
    m_simulations = numSimulations;
    m_steps = steps_;
}

double PathDependentMCSimulator::S() const
{
    return m_S;
}

void PathDependentMCSimulator::setS(double newS)
{
    m_S = newS;
}

double PathDependentMCSimulator::K() const
{
    return m_K;
}

void PathDependentMCSimulator::setK(double newK)
{
    m_K = newK;
}

double PathDependentMCSimulator::sigma() const
{
    return m_sigma;
}

void PathDependentMCSimulator::setSigma(double newSigma)
{
    m_sigma = newSigma;
}

double PathDependentMCSimulator::r() const
{
    return m_r;
}

void PathDependentMCSimulator::setR(double newR)
{
    m_r = newR;
}

double PathDependentMCSimulator::T() const
{
    return m_T;
}

void PathDependentMCSimulator::setT(double newT)
{
    m_T = newT;
}

double PathDependentMCSimulator::steps() const
{
    return m_steps;
}

void PathDependentMCSimulator::setSteps(double newSteps)
{
    m_steps = newSteps;
}

const unsigned &PathDependentMCSimulator::simulations() const
{
    return m_simulations;
}

void PathDependentMCSimulator::setSimulations(const unsigned &newSimulations)
{
    m_simulations = newSimulations;
}

std::vector<std::vector<double> > PathDependentMCSimulator::results()
{
    return m_results;
}

double PathDependentMCSimulator::d() const
{
    return m_d;
}

void PathDependentMCSimulator::setD(double newD)
{
    m_d = newD;
}

const std::string &PathDependentMCSimulator::type() const
{
    return m_type;
}

void PathDependentMCSimulator::setType(const std::string &newType)
{
    m_type = newType;
}

