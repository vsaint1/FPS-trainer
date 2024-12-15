#include "Memory.h"

namespace Memory {
uintptr_t ResolveAddress(uintptr_t baseAddress,
                         const std::vector<uintptr_t> &offsets) {
  uintptr_t address = baseAddress;

  for (auto &offset : offsets) {

    address = *(uintptr_t *)address;
    address += offset;
  }

  return address;
}


} // namespace Memory