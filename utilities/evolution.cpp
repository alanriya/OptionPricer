#include "evolution.h"

Evolution::Evolution(){

}

Evolution::~Evolution(){
     
} 


GeometricBrownianEvolution::GeometricBrownianEvolution(){}

std::vector<double> GeometricBrownianEvolution::operator()(
                                    const Parameters &Vol,
                                    const Parameters &r,
                                    double &z,
                                    double &Spot,
                                    double &Expiry,
                                    double &N) const {
    // N is the number of periods in a period of time.
    // start generating the price movement and return
    double delta_t = Expiry/N;
    double variance = Vol.IntegralSquare(0,delta_t);
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    double movedSpot = Spot*exp(r.Integral(0,delta_t)+itoCorrection);
    double thisSpot;
    // the price in vector of double.
    std::vector<double> SpotValues(N);
    for (unsigned i = 0; i<N; i++){
        movedSpot =  movedSpot*exp(rootVariance*z);
        SpotValues[i] = movedSpot;
    }

    return SpotValues;
}

GeometricBrownianEvolution::~GeometricBrownianEvolution(){

}

Evolution* GeometricBrownianEvolution::clone() const {
    return new GeometricBrownianEvolution(*this);
}


