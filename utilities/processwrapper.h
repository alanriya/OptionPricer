#ifndef PROCESSWRAPPER_H
#define PROCESSWRAPPER_H

#include "utilities/evolution.h"

#include <vector>

class ProcessWrapper
{
public:
    ProcessWrapper(const Evolution &innerEvolution);
    ProcessWrapper(const ProcessWrapper &originalEvolution);
    ~ProcessWrapper();
    ProcessWrapper& operator=(const ProcessWrapper &originalEvolution);
    std::vector<double> operator()(  const Parameters &Sigma,
                        const Parameters &rf,
                        double &m_z,
                        double &m_S,
                        double &m_T,
                        double &m_N) const;
private:
    Evolution* evolutionPtr;
};
#endif // PROCESSWRAPPER_H
