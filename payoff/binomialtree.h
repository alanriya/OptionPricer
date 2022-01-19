#ifndef BINOMIALTREE_H
#define BINOMIALTREE_H

#include "payoff/treeproduct.h"
#include <vector>
#include <cmath>
#include <iostream>
#include "utilities/parameters.h"

class BinomialTree
{
public:
    BinomialTree(double Spot_, const Parameters& r_,
                 const Parameters& d_,
                 double Volatility_,
                 unsigned long Steps_,
                 double Time_);

    double GetThePrice (const TreeProduct& TheProduct);

protected:
    void BuildTree();

private:
    double Spot;
    Parameters r;
    Parameters d;
    double Volatility;
    unsigned long Steps;
    double Time;
    bool TreeBuilt;
    std::vector<std::vector<std::pair<double, double>>> Tree;
    std::vector<double> Discounts;
    double TheTime;
    double UpFactor;
    double DownFactor;
    double ProbabilityUp;

};

#endif // BINOMIALTREE_H
