#include "Menu.h"

namespace Menu {

void Update() {
  ZeroGUI::Input::Handle();

  static bool bMenuOpened = false;
  if (GetAsyncKeyState(VK_INSERT) & 1)
    bMenuOpened = !bMenuOpened;

  SDK::FVector2D pos{700.0f, 400.0f};

  if (ZeroGUI::Window(Utils::GetWndowTitle().c_str(), &pos,
                      SDK::FVector2D{600.0f, 400.f}, bMenuOpened)) {

    static int tab = 0;
    if (ZeroGUI::ButtonTab("Aimbot", SDK::FVector2D{110, 25}, tab == 0))
      tab = 0;

    ZeroGUI::PushNextElementY(10.0f);

    if (ZeroGUI::ButtonTab("ESP", SDK::FVector2D{110, 25}, tab == 1))
      tab = 1;

    ZeroGUI::PushNextElementY(10.0f);

    if (ZeroGUI::ButtonTab("MISC", SDK::FVector2D{110, 25}, tab == 2))
      tab = 2;

    ZeroGUI::PushNextElementY(10.0f);

    if (ZeroGUI::ButtonTab("EXPLOITS", SDK::FVector2D{110, 25}, tab == 3))
      tab = 3;

    ZeroGUI::PushNextElementY(10.0f);

    if (ZeroGUI::ButtonTab("DEV", SDK::FVector2D{110, 25}, tab == 4))
      tab = 4;

    static bool test_ = false;

    ZeroGUI::NextColumn(130.0f);

    if (tab == 0) {
      ZeroGUI::Checkbox("Enabled", &test_);
      static bool text_check = false;
      static float text_slider = 15.0f;
      static int test_hotkey = 0x2;
      static SDK::FLinearColor test_color{0.0f, 0.0f, 1.0f, 1.0f};

      ZeroGUI::Checkbox("Test Checkbox", &text_check);
      ZeroGUI::SliderFloat("Test Slider", &text_slider, 0.0f, 180.0f);
      ZeroGUI::Hotkey("Test Hotkey", FVector2D{80, 25}, &test_hotkey);

      ZeroGUI::PushNextElementY(50.0f);
      static int test_number = 1;
      ZeroGUI::Combobox("Memebox", SDK::FVector2D{100, 25}, &test_number, "1",
                        "2", "3", "4", NULL);
      ZeroGUI::SameLine();
      if (ZeroGUI::Button("Button", SDK::FVector2D{100, 25})) {
      }
      ZeroGUI::ColorPicker("Color Picker", &test_color);
    }

    ZeroGUI::NextColumn(130.0f);

    if (tab == 1) {
      static int test_number = 0;
      ZeroGUI::Text("ESP", false, true);
      ZeroGUI::Checkbox("Enabled", &Config::Visual::Player::bEnabled);
      ZeroGUI::Checkbox("Box", &Config::Visual::Player::bBox);
      ZeroGUI::Combobox("Type", SDK::FVector2D{100, 25}, &test_number, "Corner",
                        "3D", "2D", NULL);
      ZeroGUI::Checkbox("Healthbar", &Config::Visual::Player::bHealthBar);
      ZeroGUI::Checkbox("Team", &Config::Visual::Player::bTeam);
      ZeroGUI::Checkbox("Names", &Config::Visual::Player::bName);
      ZeroGUI::Checkbox("Snaplines", &Config::Visual::Player::bSnaplines);
      ZeroGUI::Checkbox("Distance", &Config::Visual::Player::bDistance);
      ZeroGUI::Checkbox("Skeleton", &Config::Visual::Player::bSkeleton);

      ZeroGUI::NextColumn(280.f);
      ZeroGUI::Text("Chams", false, true);
      ZeroGUI::Checkbox("Enabled", &Config::Visual::Player::bChamsEnabled);
      ZeroGUI::Checkbox("Player Chams", &Config::Visual::Player::bPlayerChams);
      ZeroGUI::Checkbox("Weapon Chams", &Config::Visual::Player::bWeaponChams);
      //ZeroGUI::Checkbox("Grenade Chams", &Config::Visual::Player::bSkeleton);

    }

    ZeroGUI::NextColumn(130.0f);

    if (tab == 2) {
      ZeroGUI::Text("Memefn");
      ZeroGUI::Checkbox("Chams", &test_);
    }

    ZeroGUI::NextColumn(130.0f);

    if (tab == 3) {
      ZeroGUI::Text("Exploits");
      ZeroGUI::Checkbox("God", &Config::Exploit::bGod);
      ZeroGUI::Checkbox("Fly", &Config::Exploit::bFly);
      ZeroGUI::Checkbox("Infinite Ammo", &Config::Exploit::bInfiniteAmmo);
      ZeroGUI::Checkbox("No Spread", &Config::Exploit::bNoSpread);
      ZeroGUI::Checkbox("No Recoil", &Config::Exploit::bNoRecoil);
      ZeroGUI::Checkbox("One Hit Kill", &Config::Exploit::bOneHitKill);
      ZeroGUI::Checkbox("Rapid Fire", &Config::Exploit::bRapidFire);
      ZeroGUI::Checkbox("Speed Hack", &Config::Exploit::bSpeedHack);
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
