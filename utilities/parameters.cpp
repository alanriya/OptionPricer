#include "parameters.h"

Parameters::Parameters(const ParametersInner& innerObject)
{
    InnerObjectPtr = innerObject.clone();
}

Parameters::Parameters(const Parameters& original)
{
    InnerObjectPtr = original.InnerObjectPtr->clone();
}
Parameters& Parameters::operator=(const Parameters& original)
{
    if (this != &original)
    {
        delete InnerObjectPtr;
        InnerObjectPtr = original.InnerObjectPtr->clone();
    }
    return *this;
}

Parameters::~Parameters()
{
    delete InnerObjectPtr;
}

double Parameters::Mean(double time1, double time2) const
{
    double total = Integral(time1,time2);
    return total/(time2-time1);
}

double Parameters::RootMeanSquare(double time_1, double time_2) const {
    double total = IntegralSquare(time_1, time_2);
    return total/(time_2-time_1);
}

ParametersConstant::ParametersConstant(double constant){
    Constant = constant;
    ConstantSquare = constant*constant;
}

ParametersInner* ParametersConstant::clone() const {
    return new ParametersConstant(*this);
}

double ParametersConstant::Integral(double time_1, double time_2) const {
    return (time_2 - time_1) * Constant;
}

double ParametersConstant::IntegralSquare(double time_1, double time_2) const {
    return (time_2 - time_1) * ConstantSquare;
}
