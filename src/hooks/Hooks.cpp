#include "Hooks.h"

inline void ProcessEventHooked(SDK::UObject *pObj, SDK::UFunction *pFunc,
                               void *params);

namespace Hooks {

bool Setup() {

  if (MH_Initialize() != MH_OK) {
    U_LOG("Failed to initialized MH");
    return false;
  }

  if (MH_CreateHook(reinterpret_cast<void *>(SDK::InSDKUtils::GetImageBase() +
                                             SDK::Offsets::ProcessEvent),
                    &ProcessEventHooked,
                    reinterpret_cast<void **>(
                        &Defines::originalProcessEventFn)) != MH_OK) {

    U_LOG("Failed to hook ProcessEvent");

    return false;
  }

  MH_EnableHook(MH_ALL_HOOKS);
}

bool Shutdown() {
  if (MH_DisableHook(MH_ALL_HOOKS) != MH_OK) {
    U_LOG("Failed to disable hooks");
    return false;
  }

  if (MH_Uninitialize() != MH_OK) {
    U_LOG("Failed to uninitialized MH");
    return false;
  }

  return true;
}

bool Remove(void **vfTable, std::int32_t index, void *originalFn) {

  vfTable[index] = originalFn;
  originalFn = nullptr;

  return true;
}

} // namespace Hooks