#pragma once
#include "../Utils.h"
#include <Psapi.h>

namespace Memory {
template <typename T> T Read(uintptr_t address) { return *(T *)address; }

template <typename T> void Write(uintptr_t address, const T &value) {
  *(T *)address = value;
}

uintptr_t ResolveAddress(uintptr_t baseAddress,
                         const std::vector<uintptr_t> &offsets);

inline char *VMT_Hook(void **vtable, uint32_t index, void *targetFunction) {

  char *original = reinterpret_cast<char *>(vtable[index]);

  DWORD oldProtection = 0;

  VirtualProtect(&vtable[index], sizeof(void *), PAGE_EXECUTE_READWRITE,
                 &oldProtection);

  vtable[index] = targetFunction;

  VirtualProtect(&vtable[index], sizeof(void *), oldProtection, 0);

  return original;
}

inline bool _Mask(BYTE *address, PBYTE signature, const char *mask) {
  for (; *mask; ++mask, ++address, ++signature) {
    if (*mask == 'x' && *address != *signature)
      return false;
  }
  return (*mask) == 0;
}

inline PBYTE FindPattern(BYTE *signature, const char *mask,
                         std::int32_t instructionSize,
                         std::int32_t relativeOffset,
                         const wchar_t *moduleName = nullptr) {

  HMODULE module{};

  if (!moduleName)
    module = GetModuleHandle(moduleName);
  else
    module = GetModuleHandle(0);

  MODULEINFO mInfo{};
  K32GetModuleInformation(GetCurrentProcess(), module, &mInfo, sizeof(mInfo));

  BYTE *baseAddress = (BYTE *)mInfo.lpBaseOfDll;
  DWORD dwSize = mInfo.SizeOfImage;
  size_t length = strlen(mask);

  for (size_t i = 0; i < dwSize - length; i++) {
    if (_Mask(baseAddress + i, signature, mask)) {
      BYTE *matchAddress = baseAddress + i;

      std::int32_t relativeAddress =
          *(std::int32_t *)(matchAddress + instructionSize);

      U_LOG("[%p] RELATIVE_OFFSET\n", relativeOffset);

      BYTE *address = matchAddress + relativeAddress +relativeOffset;

      return address;
    }
  }
  return nullptr;
}

} // namespace Memory