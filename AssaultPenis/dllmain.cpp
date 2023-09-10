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
    Console::CreateConsole("TemplateCheat");

    std::cout << "initializing" << std::endl;

    InitHooks();
    InitMods();
    
    std::thread keypressThread(keypressLoop);
    keypressThread.detach();

    // module display loop
    while (true) {
        // create a double buffer for console output
        std::stringstream doubleBuffer;
        doubleBuffer << "AssaultPenis" << std::endl;

        // add each module to the display buffer
		for (auto& mod : modules) {
            doubleBuffer << "[" << (mod->enabled ? "x" : " ") << "] " << "[" << mod->keybind << "] " << mod->name << std::endl;
		}

        // clear the screen and print the double buffer (swap)
        system("cls");
        std::cout << doubleBuffer.str();

        Sleep(1000 / 24); // display at 24 fps (smooth animation)
	}
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
    if (reason == DLL_PROCESS_ATTACH) {
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Init, module, 0, 0);
    }
    return TRUE;
}