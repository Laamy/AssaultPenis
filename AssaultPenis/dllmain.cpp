#pragma region Includes

#include <windows.h>
#include <vector>
#include <string>
#include <Psapi.h>
#include <sstream>
#include <thread>
#include <queue>
#include <map>
#include <iostream>
#include <mutex>

#define Log(msg, ...) printf_s(msg, __VA_ARGS__); printf_s("\n");
#define SplitLog() std::cout << std::endl;

#include "Libs/minhook/minhook.h"
#include "Libs/math/Math.h"

#include "Utils/MemoryUtils.h"

#include "FileIO.h"

#include "SDK/physent.h"

#include "Game.h"

#include "Module/ModuleManager.h"

#include "Hook/FuncHook.h"

#include "Console.h"

#pragma endregion

// thread to handle keypresses via a loop
void keypressLoop() {
    while (true) {
        // loop over 0-0xff (255) keycodes and getasync store then compare to last and trigger keyevents
        for (int i = 0; i < 0xff; i++) {
            bool curPress = GetAsyncKeyState(i);
            if (not Game::Keymap[i] && curPress) {
                // trigger module enable/disables if keybind
                for (auto& mod : modules) {
					if (mod->keybind == i) {
                        // toggle the module
                        mod->SetEnabled(not mod->enabled);
					}
				}
            }

            Game::Keymap[i] = curPress;
		}

        Sleep(1000 / 60); // update keypresses at 60hz
    }
}

void Init(HANDLE module) {
    // init uwp supported console
    Console::CreateConsole("TemplateCheat");
    Log("Created console");

    VF_c(); // init the virtual function table

    SplitLog(); // quick \r\n split

    InitHooks(); // init the hooks

    SplitLog(); // quick \r\n split

    InitMods(); // init the modules
    
    // start the keypress thread
    std::thread keypressThread(keypressLoop);
    keypressThread.detach();
}

// cheat entry point
BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(module); // stop multiple calls to DllMain
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Init, module, 0, 0); // create a thread to init the cheat
    }
    return TRUE;
}