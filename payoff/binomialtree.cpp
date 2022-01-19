#include "binomialtree.h"


BinomialTree::BinomialTree(double Spot_, const Parameters &r_, const Parameters &d_,
                           double Volatility_, unsigned long Steps_, double Time_)
    : Spot(Spot_),
      r(r_),
      d(d_),
      Volatility(Volatility_),
      Steps(Steps_),
      Time(Time_),
      Discounts(Steps){
  TreeBuilt = false;
  TheTime = Time/Steps;
  // computation of risk neutral valuation;
  UpFactor = exp(Volatility*sqrt(TheTime));
  DownFactor = 1/UpFactor;
  ProbabilityUp = (exp((r.Integral(0.0, 1.0)-d.Integral(0.0,1.0))*TheTime) - DownFactor)/(UpFactor - DownFactor);
}

void BinomialTree::BuildTree()
{
    TreeBuilt = true;
    Tree.resize(Steps+1);

    double InitialLogSpot = log(Spot);

    for (unsigned long i = 0; i <= Steps; i++){
      Tree[i].resize(i+1);
      double thisTime = (i*Time)/Steps;
      double movedLogSpot = InitialLogSpot + r.Integral(0.0, thisTime) - d.Integral(0.0, thisTime);
      movedLogSpot -= 0.5*Volatility*Volatility*thisTime;
      double sd = Volatility*sqrt(Time/Steps);
      for (long j = -static_cast<long>(i), k=0;
         j <= static_cast<long>(i);
         j=j+2,k++)
       Tree[i][k].first = exp(movedLogSpot+ j*sd);
      }
    for (unsigned long l=0; l <Steps; l++){
      Discounts[l] = exp(- r.Integral(l*Time/Steps,(l+1)*Time/Steps));
    }
}

double BinomialTree::GetThePrice(const TreeProduct &TheProduct)
{
  if (!TreeBuilt){
      BuildTree();
  }

  if (TheProduct.GetFinalTime() != Time){
      throw("mismatched Product in Binomial Tree");
  }

  for (long j = -static_cast<long>(Steps), k=0;
        j <=static_cast<long>( Steps); j=j+2,k++)
      Tree[Steps][k].second =
      TheProduct.FinalPayOff(Tree[Steps][k].first);

  for (unsigned long i=1; i <= Steps; i++){
    unsigned long index = Steps-i;
    double ThisTime = index*Time/Steps;
    for (long j = -static_cast<long>(index), k=0;
      j <= static_cast<long>(index); j=j+2,k++)
      {
        double Spot = Tree[index][k].first;
        double futureDiscountedValue = Discounts[index]*(ProbabilityUp*Tree[index+1][k].second + (1-ProbabilityUp)*Tree[index+1][k+1].second);
        Tree[index][k].second = TheProduct.PreFinalValue(Spot, ThisTime, futureDiscountedValue);
      }
  }
  return Tree[0][0].second;
}



