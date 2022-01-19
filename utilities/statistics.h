#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>

class Statistics
{
public:
    Statistics(){};
    virtual void DumpOneResult(double result) = 0;
    virtual std::vector<std::vector<double> > GetResultsSoFar() const=0;
    virtual Statistics* clone() const=0;
    virtual ~Statistics(){}
private:
};

#endif // STATISTICS_H
