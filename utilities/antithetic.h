#ifndef ANTITHETIC_H
#define ANTITHETIC_H


#include "utilities/randombase.h"
#include "utilities/wrapper.h"

class AntiThetic : public RandomBase
{
public:
    AntiThetic(const Wrapper<RandomBase>& innerGenerator );
    virtual RandomBase* clone() const;
    virtual void GetUniforms(std::vector<double> &variates);
    virtual void Skip(unsigned long numberOfPaths);
    virtual void SetSeed(unsigned long Seed);
    virtual void ResetDimensionality(unsigned long
                                     NewDimensionality);
    virtual void Reset();
private:
    Wrapper<RandomBase> InnerGenerator;
    bool OddEven;
    std::vector<double> NextVariates;
};

#endif // ANTITHETIC_H
