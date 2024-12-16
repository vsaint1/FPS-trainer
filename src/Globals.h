#pragma once
#include "Utils.h"
struct CPattern {
  const char *signature;
  const char *mask;
};


namespace G {

inline SDK::APlayerController *pLocalPlayer = nullptr;
inline SDK::TArray<SDK::AActor *> pActors;
inline SDK::UWorld *pWorld = nullptr;
inline SDK::UEngine *pEngine = nullptr;

namespace Offsets {

constexpr uintptr_t GOBJECT_OFFSET = 0x042372C8;
constexpr uintptr_t APPENDSTRING_OFFSET = 0x00D0BA40;
constexpr uintptr_t GNAMES_OFFSET = 0x0421E880;
constexpr uintptr_t GWORLD_OFFSET = 0x043795D8;
constexpr uintptr_t PE_OFFSET = 0x00EF6860;
constexpr uintptr_t PE_IDX_OFFSET = 0x00000042;
constexpr std::int32_t PR_IDX_OFFSET = 0x63;

constexpr CPattern GWORLD_SIG = {
    "\x48\x89\x05\x00\x00\x00\x00\x48\x8B\xB7\x00\x00\x00\x00",
    "xxx????xxx????"};

} // namespace Offsets
} // namespace G
