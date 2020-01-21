#include "../Engine.h"

eCDX9Instance * eCDX9Instantiator::CreateInstance(eCAPIInstance ** a_ppInstance)
{
    return GE_NEW(eCDX9Instance)(a_ppInstance);
}
