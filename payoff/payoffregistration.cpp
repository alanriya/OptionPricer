#include "payoffconstructible.h"

namespace
{
    PayOffHelper<PayOffCall> RegisterCall("Call");
    PayOffHelper<PayOffPut> RegisterPut("Put");

    //    PayOffHelper<PathDependentAsian> RegisterGeometricAsianCall("GeometricAsianCall");
}
