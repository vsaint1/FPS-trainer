#pragma once
#include "../Utils.h"

namespace Memory {
template <typename T> T Read(uintptr_t address) { return *(T *)address; }

template <typename T> void Write(uintptr_t address, const T &value) {
  *(T *)address = value;
}

uintptr_t ResolveAddress(uintptr_t baseAddress,
                         const std::vector<uintptr_t> &offsets);

uint8_t *FindPattern(const char *moduleName, const char *sig,
                     unsigned int byteOffset);

uintptr_t FindPatternOffset(const char *moduleName, const char *sig,
                            unsigned int byteOffset = 0u);

inline char *VMT_Hook(void **vtable, uint32_t index, void *targetFunction) {

  char *original = reinterpret_cast<char *>(vtable[index]);

  DWORD oldProtection = 0;

  VirtualProtect(&vtable[index], sizeof(void *), PAGE_EXECUTE_READWRITE,
                 &oldProtection);

  vtable[index] = targetFunction;

  VirtualProtect(&vtable[index], sizeof(void *), oldProtection, 0);

  return original;
}

} // namespace Memory