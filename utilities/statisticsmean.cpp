#include "statisticsmean.h"

StatisticsMean::StatisticsMean()
{
    RunningSum = 0.0;
    PathsDone=0;
}

void StatisticsMean::DumpOneResult(double result)
{
    PathsDone += 1;
    RunningSum += result;
}

std::vector<std::vector<double> > StatisticsMean::GetResultsSoFar() const
{
    std::vector<std::vector<double> > results(1);
    results[0].resize(1);
    results[0][0] = RunningSum/PathsDone;
    return results;
}

Statistics *StatisticsMean::clone() const
{
    return new StatisticsMean(*this);
}
