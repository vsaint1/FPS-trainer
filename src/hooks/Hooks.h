#pragma once
#include "../Globals.h"
#include "../Utils.h"
#include "../mem/Memory.h"
#include "../../ext/minhook/MinHook.h"

namespace Defines {
using PostRenderFn = void (*)(SDK::UGameViewportClient *_this,
                              SDK::UCanvas *canvas);
inline PostRenderFn originalPostRenderFn = 0;

using ProcessEventFn = void (*)(SDK::UObject *, SDK::UFunction *, void *);

inline ProcessEventFn originalProcessEventFn = 0;



} // namespace Defines

namespace Hooks {

bool Setup();

bool Remove(void **vfTable, std::int32_t index, void *originalFn);

bool Shutdown();

} // namespace Hooks