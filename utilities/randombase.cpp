#include "./utilities/randombase.h"

#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

double RationalApproximation(double t)
{
    // Abramowitz and Stegun formula 26.2.23.
    // The absolute value of the error should be less than 4.5 e-4.
    double c[] = {2.515517, 0.802853, 0.010328};
    double d[] = {1.432788, 0.189269, 0.001308};
    return t - ((c[2]*t + c[1])*t + c[0]) / 
               (((d[2]*t + d[1])*t + d[0])*t + 1.0);
}


double NormalCDFInverse(const double& p)
{
    // See article above for explanation of this section.
    if (p < 0.5)
    {
        // F^-1(p) = - G^-1(p)
        return -RationalApproximation( sqrt(-2.0*log(p)) );
    }
    else
    {
        // F^-1(p) = G^-1(1-p)
        return RationalApproximation( sqrt(-2.0*log(1-p)) );
    }
}

double inv_cdf(const double& quantile) {
  // This is the Beasley-Springer-Moro algorithm which can
  // be found in Glasserman [2004]. We won't go into the
  // details here, so have a look at the reference for more info
  static double a[4] = {   2.50662823884,
                         -18.61500062529,
                          41.39119773534,
                         -25.44106049637};

  static double b[4] = {  -8.47351093090,
                          23.08336743743,
                         -21.06224101826,
                           3.13082909833};

  static double c[9] = {0.3374754822726147,
                        0.9761690190917186,
                        0.1607979714918209,
                        0.0276438810333863,
                        0.0038405729373609,
                        0.0003951896511919,
                        0.0000321767881768,
                        0.0000002888167364,
                        0.0000003960315187};

  if (quantile >= 0.5 && quantile <= 0.92) {
    double num = 0.0;
    double denom = 1.0;

    for (int i=0; i<4; i++) {
      num += a[i] * pow((quantile - 0.5), 2*i + 1);
      denom += b[i] * pow((quantile - 0.5), 2*i);
    }
    return num/denom;

  } else if (quantile > 0.92 && quantile < 1) {
    double num = 0.0;

    for (int i=0; i<9; i++) {
      num += c[i] * pow((log(-log(1-quantile))), i);
    }
    return num;

  } else {
    return -1.0*inv_cdf(1-quantile);
  }
}

void RandomBase::GetGaussians(std::vector<double> &variates)
{
    GetUniforms(variates);
    for (unsigned long i=0; i < Dimensionality; i++)
    {
        double x=variates[i];
        variates[i] = NormalCDFInverse(x);
    }
}

void RandomBase::ResetDimensionality(unsigned long
                                     NewDimensionality)
{
    Dimensionality = NewDimensionality;
}

RandomBase::RandomBase(unsigned long Dimensionality_)
    : Dimensionality(Dimensionality_)
{
}
