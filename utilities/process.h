#ifndef PROCESS_H
#define PROCESS_H

#include <vector>
#include "utilities/evolution.h"
#include "utilities/parameters.h"
#include "utilities/processwrapper.h"


class Process
{
public: 
    Process(const ProcessWrapper &process_);
    std::vector<double> GeneratePrice(const Parameters &Sigma,
                        const Parameters &rf,
                        double &m_z,
                        double &m_S,
                        double &m_T,
                        double &m_N);
private:
    ProcessWrapper process;
};

#endif // PROCESS_H
