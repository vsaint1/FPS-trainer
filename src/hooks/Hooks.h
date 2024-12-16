#pragma once
#include "../Globals.h"
#include "../Utils.h"
#include "../mem/Memory.h"

namespace Defines {
using PostRenderFn = void (*)(SDK::UGameViewportClient *_this,
                              SDK::UCanvas *canvas);
inline PostRenderFn originalPostRenderFn = 0;
} // namespace Defines

namespace Hooks {

bool Remove(void **vfTable, std::int32_t index, void *originalFn);



} // namespace Hooks