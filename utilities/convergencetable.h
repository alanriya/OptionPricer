#ifndef CONVERGENCETABLE_H
#define CONVERGENCETABLE_H

#include "statistics.h"
#include "wrapper.h"
#include <iostream>

class ConvergenceTable : public Statistics
{
public:
    ConvergenceTable(const Wrapper<Statistics>& Inner_);
    virtual Statistics* clone() const;
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double> >
    GetResultsSoFar() const;
private:
    Wrapper<Statistics> Inner;
    std::vector<std::vector<double> > ResultsSoFar;
    unsigned long StoppingPoint;
    unsigned long PathsDone;
};

#endif // CONVERGENCETABLE_H
