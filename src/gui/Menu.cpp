#include "Menu.h"

namespace Menu {

void Update() {
  ZeroGUI::Input::Handle();

  static bool bMenuOpened = false;
  if (GetAsyncKeyState(VK_INSERT) & 1)
    bMenuOpened = !bMenuOpened;

  SDK::FVector2D pos{700.0f, 400.0f};

  if (ZeroGUI::Window(Utils::GetWndowTitle().c_str(), &pos,
                      SDK::FVector2D{600.0f, 400.0f}, bMenuOpened)) {

    static int tab = 0;
    if (ZeroGUI::ButtonTab("Aimbot", SDK::FVector2D{110, 25}, tab == 0))
      tab = 0;
    if (ZeroGUI::ButtonTab("ESP", SDK::FVector2D{110, 25}, tab == 1))
      tab = 1;
    if (ZeroGUI::ButtonTab("MISC", SDK::FVector2D{110, 25}, tab == 2))
      tab = 2;
    if (ZeroGUI::ButtonTab("EXPLOITS", SDK::FVector2D{110, 25}, tab == 3))
      tab = 3;
    if (ZeroGUI::ButtonTab("DEV", SDK::FVector2D{110, 25}, tab == 4))
      tab = 4;

    static bool test_ = false;

    ZeroGUI::NextColumn(130.0f);

    if (tab == 0) {
      ZeroGUI::Checkbox("Enabled", &test_);
    }

    ZeroGUI::NextColumn(130.0f);

    if (tab == 1) {

      static bool text_check = false;
      static float text_slider = 15.0f;
      static int test_hotkey = 0x2;
      static SDK::FLinearColor test_color{0.0f, 0.0f, 1.0f, 1.0f};

      ZeroGUI::Checkbox("Test Checkbox", &text_check);
      ZeroGUI::SliderFloat("Test Slider", &text_slider, 0.0f, 180.0f);
      ZeroGUI::Hotkey("Test Hotkey", FVector2D{80, 25}, &test_hotkey);

      ZeroGUI::PushNextElementY(50.0f);
      static int test_number = 1;
      ZeroGUI::Combobox("Memebox", SDK::FVector2D{100, 25}, &test_number,
                        "1", "2", "3", "4", NULL);
      ZeroGUI::SameLine();
      if (ZeroGUI::Button("Button", SDK::FVector2D{100, 25})) {
      }
      ZeroGUI::ColorPicker("Color Picker", &test_color);
    }

    ZeroGUI::NextColumn(130.0f);

    if (tab == 2) {
      ZeroGUI::Text("Memefn");
      ZeroGUI::Checkbox("Chams", &test_);
    }

    ZeroGUI::NextColumn(130.0f);

    if (tab == 3) {
      ZeroGUI::Text("Memefn2");
    }

    ZeroGUI::NextColumn(130.0f);

    if (tab == 4) {

      if (ZeroGUI::Button("List Fonts", SDK::FVector2D({100, 25}))) {
        Utils::ListAvailableFonts();
      }

      if (ZeroGUI::Button("List Materials", SDK::FVector2D({100, 25}))) {
        Utils::ListAvailableMaterials();
      }
    }

    ZeroGUI::NextColumn(130.0f);
  }
  ZeroGUI::Render();

  ZeroGUI::Draw_Cursor(bMenuOpened);
}
} // namespace Menu
