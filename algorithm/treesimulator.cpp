#include "treesimulator.h"

TreeSimulator::TreeSimulator()
{

}

void TreeSimulator::runSimulation()
{
    PayOff* PayOffPtr = nullptr;
    if (m_type == "American Put"){
        PayOffPtr = PayOffFactory::Instance().CreatePayOff("Put", m_K);
    } else if (m_type == "American Call"){
        PayOffPtr = PayOffFactory::Instance().CreatePayOff("Call", m_K);
    }

    ParametersConstant rParam(m_r);
    ParametersConstant dParam(m_d);
    TreeAmerican americanOption(m_T,*PayOffPtr);
    BinomialTree theTree(m_S, rParam, dParam, m_sigma, m_steps, m_T);
    double americanPrice = theTree.GetThePrice(americanOption);
    setResults(americanPrice);
    delete PayOffPtr;
}

const std::string &TreeSimulator::type() const
{
    return m_type;
}

void TreeSimulator::setType(const std::string &newType)
{
    m_type = newType;
}

double TreeSimulator::S() const
{
    return m_S;
}

void TreeSimulator::setS(double newS)
{
    m_S = newS;
}

double TreeSimulator::K() const
{
    return m_K;
}

void TreeSimulator::setK(double newK)
{
    m_K = newK;
}

double TreeSimulator::sigma() const
{
    return m_sigma;
}

void TreeSimulator::setSigma(double newSigma)
{
    m_sigma = newSigma;
}

double TreeSimulator::r() const
{
    return m_r;
}

void TreeSimulator::setR(double newR)
{
    m_r = newR;
}

double TreeSimulator::T() const
{
    return m_T;
}

void TreeSimulator::setT(double newT)
{
    m_T = newT;
}

double TreeSimulator::d() const
{
    return m_d;
}

void TreeSimulator::setD(double newD)
{
    m_d = newD;
}

double TreeSimulator::steps() const
{
    return m_steps;
}

void TreeSimulator::setSteps(double newSteps)
{
    m_steps = newSteps;
}

double TreeSimulator::results() const
{
    return m_results;
}

void TreeSimulator::setResults(double newResults)
{
    m_results = newResults;
}
