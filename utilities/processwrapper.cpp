#include "processwrapper.h"


ProcessWrapper::ProcessWrapper(const ProcessWrapper &originalProcess){
    evolutionPtr = originalProcess.evolutionPtr->clone();
}


ProcessWrapper::ProcessWrapper(const Evolution &innerEvolution){
    evolutionPtr = innerEvolution.clone();
}

ProcessWrapper::~ProcessWrapper(){
    delete evolutionPtr;
}

ProcessWrapper& ProcessWrapper::operator=(const ProcessWrapper &originalProcess){
    if (this != &originalProcess){
        delete evolutionPtr;
        evolutionPtr = originalProcess.evolutionPtr->clone();
    }
    return *this;
}

std::vector<double> ProcessWrapper::operator()(const Parameters &Sigma,
                                  const Parameters &rf,
                                    double &m_z,
                                    double &m_S,
                                    double &m_T,
                                    double &m_N) const {
    return evolutionPtr->operator()(Sigma, rf, m_z, m_S, m_T, m_N);
}