#include "process.h"
// base class for stochastic time series.
Process::Process(const ProcessWrapper &process_) : process(process_)
{

}

std::vector<double> Process::GeneratePrice(const Parameters &Sigma,
                            const Parameters &rf,
                            double &m_z,
                            double &m_S,
                            double &m_T,
                            double &m_N)
{
    return process(Sigma, rf, m_z, m_S, m_T, m_N);
}