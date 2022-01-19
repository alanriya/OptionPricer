Introduction:
This learning project is a option pricing platform that is aims to be able to price various financial securities. Currently European Call and Put Option, Path Dependent Asian Options and American Options can be priced.

The European and Path-dependent Asian Options are priced using Monte Carlos Simulations via the classical Geometric Brownian Motion.
The American Option is priced using the risk-neutral binomial tree valuation.

Future Extension: 
1) European Binary Option
2) Pricing using Heston Model.
3) Pricing vanilla bonds, floating bonds and interest rates derivatives.

Project Structure: 
algorithm: contains the various price simulators for the different type of securities
payoff: contains code that aid with the calculation of option payoff
utilities: code that will be reused almost every time like generating random numbers under normal distribution, etc...

Technology:
C++ and Qt-6 (6.0.4)



