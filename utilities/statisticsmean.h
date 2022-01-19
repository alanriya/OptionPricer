#ifndef STATISTICSMEAN_H
#define STATISTICSMEAN_H

#include "utilities/statistics.h"

class StatisticsMean : public Statistics {
public:
    StatisticsMean();
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double> > GetResultsSoFar() const;
    virtual Statistics* clone() const;
private:
    double RunningSum;
    unsigned long PathsDone;
};
#endif // STATISTICSMEAN_H
