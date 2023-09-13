#pragma once

// all hooks should inherit from this class
class FuncHook {
public:
    // define funchook naming convention signature here which we will use to log information about the hook
    std::string NC_Signature;

    // define funchook naming convention signature here
    FuncHook(std::string ncsig)
    {
	    NC_Signature = ncsig;
    }

public:
    // initialize hook
	virtual bool Initialize() = 0;
};

// include hooks here
#include "Hooks/PlayerHook.h"
#include "Hooks/OpenALHook.h"

// call this function to initialize all hooks (only once though else it'll crash)
void InitHooks() {
	// initialize hooks here
	static FuncHook* hooks[] = { // include hooks here
        &PlayerHook::Get(),
        &OpenALHook::Get()
	};

    // loop over all hooks and initialize them
    for (FuncHook* hook : hooks)
    {
        // tell the hook to initialize
        if (not hook->Initialize())
        {
            // log the string using macro I wrote in dllmain
            Log("[!] Failed to hook %s", hook->NC_Signature.c_str());
        }
        else
        {
            // log the string using macro I wrote in dllmain (x2)
            Log("[*] Hooked %s", hook->NC_Signature.c_str());
        }
    }
}