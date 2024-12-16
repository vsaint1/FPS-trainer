#include "Hooks.h"

namespace Hooks {


bool Remove(void **vfTable, std::int32_t index, void *originalFn) {

  vfTable[index] = originalFn;
  originalFn = nullptr;

  return true;
}


} // namespace Hooks