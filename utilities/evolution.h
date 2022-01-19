#ifndef EVOLUTION_H
#define EVOLUTION_H

#include "parameters.h"
#include <cmath>
#include <vector>

class Evolution
{
public:
    Evolution();
    virtual ~Evolution();
    virtual std::vector<double> operator()( const Parameters &Sigma,
                                const Parameters &rf,
                                double &m_z,
                                double &m_S,
                                double &m_T, 
                                double &m_N) const = 0;
    virtual Evolution* clone() const = 0;
private:
    
};


class GeometricBrownianEvolution : public Evolution {
    public: 
        GeometricBrownianEvolution();
        virtual std::vector<double> operator()(  const Parameters &Sigma,
                                    const Parameters &rf,
                                    double &m_z,
                                    double &m_S,
                                    double &m_T,
                                    double &m_N) const;
        virtual ~GeometricBrownianEvolution();
        virtual Evolution* clone() const;
    private:
};

#endif // EVOLUTION_H
