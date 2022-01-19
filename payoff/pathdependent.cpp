#include "pathdependent.h"

PathDependent::PathDependent(const std::vector<double> LookAtTimes) : LookAtTimes(LookAtTimes)
{

}

const std::vector<double> &PathDependent::GetLookAtTimes() const
{
    return LookAtTimes;
}
