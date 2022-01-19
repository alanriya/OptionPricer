#include "montecarlossimulator.h"

MonteCarlosSimulator::MonteCarlosSimulator()
{

}

void MonteCarlosSimulator::runSimulation()
{
    PayOff* PayOffPtr = nullptr;
    PayOffPtr = PayOffFactory::Instance().CreatePayOff(m_type, m_K);

    if (PayOffPtr == nullptr){
        std::cout << "No option is found in the options, this is fucked up" << std::endl;
        return;
    }
    //
    VanillaOption theOption(*PayOffPtr, m_T);

    ParametersConstant rParam(m_r);
    ParametersConstant volParam(m_sigma);
    StatisticsMean gather;
    ConvergenceTable gatherer(gather);
    RandomParkMiller generator(1);
    AntiThetic generator2(generator);
    generator2.ResetDimensionality(1);

    double Expiry = theOption.getExpiry();
    std::vector<double> thisSpot;
    double discounting = exp(-rParam.Integral(0,Expiry));
    std::vector<double> VariateArray(1);
    GeometricBrownianEvolution gbm;
    Process PriceProcess(gbm);

    for (unsigned long i=0; i < m_simulations; i++)
        {
            generator.GetGaussians(VariateArray);
            thisSpot = PriceProcess.GeneratePrice(volParam, rParam, VariateArray[0], m_S, Expiry, m_steps);
            // take the first double as the spot price at time T.
            double thisPayOff = theOption.OptionPayOff(thisSpot.at(0));
            gatherer.DumpOneResult(thisPayOff*discounting);
        }

    m_results = gatherer.GetResultsSoFar();
    delete PayOffPtr;
    return;
}


std::vector<std::vector<double> > MonteCarlosSimulator::results()
{
    return m_results;
}

double MonteCarlosSimulator::S() const
{
    return m_S;
}

void MonteCarlosSimulator::setS(double newS)
{
    m_S = newS;
}

double MonteCarlosSimulator::K() const
{
    return m_K;
}

void MonteCarlosSimulator::setK(double newK)
{
    m_K = newK;
}

double MonteCarlosSimulator::sigma() const
{
    return m_sigma;
}

void MonteCarlosSimulator::setSigma(double newSigma)
{
    m_sigma = newSigma;
}

double MonteCarlosSimulator::r() const
{
    return m_r;
}

void MonteCarlosSimulator::setR(double newR)
{
    m_r = newR;
}

double MonteCarlosSimulator::T() const
{
    return m_T;
}

void MonteCarlosSimulator::setT(double newT)
{
    m_T = newT;
}

const unsigned &MonteCarlosSimulator::simulations() const
{
    return m_simulations;
}

void MonteCarlosSimulator::setSimulations(const unsigned &newSimulations)
{
    m_simulations = newSimulations;
}

void MonteCarlosSimulator::setParams(double S_, double K_, double sigma_, double r_, double T_, unsigned numSimulations, double steps_)
{
    m_S = S_;
    m_K = K_;
    m_sigma = sigma_;
    m_r = r_;
    m_T = T_;
    m_simulations = numSimulations;
    m_steps = steps_;
}

const std::string &MonteCarlosSimulator::type() const
{
    return m_type;
}

void MonteCarlosSimulator::setType(const std::string &newType)
{
    m_type = newType;
}
