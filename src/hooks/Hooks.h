#pragma once
#include "../Utils.h"


namespace Hooks {

bool Initialize();


bool RemoveHook(void *pTarget);

bool Shutdown();

} // namespace Hooks