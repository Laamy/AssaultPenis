#pragma once

// define our localplayer class reference
physent* playerPtr = nullptr;

// define our localplayer original tick function for us to call
void* __o__ticklp;

// define our detour function which the original games physent tick will be redirected to
void TickLocalplayerDetour(void* _this, physent* player) {

	if (playerPtr == nullptr) {
		playerPtr = player;
	}

	for (auto& mod : modules) {
		if (mod->enabled) {
			mod->OnTick(playerPtr);
		}
	}

	// dont call original else ur gonna crash it
}

// define our player hook class
class PlayerHook : public FuncHook {
public:
	// override funchook constructor to pass our naming convention signature name
	PlayerHook() : FuncHook("LocalPlayer") {}

	// override initialize to hook our function
	bool Initialize() override {
		// find our localplayer tick function address using raw machine code signatures
		uintptr_t localPlayerTickAddr = findOffset("8B D1 83 EC 0C F3", "LocalPlayer");

		// HookFunction is a small wrapper around MinHook I wrote so ctrl+click it to see the implementation
		if (not HookFunction((void*)localPlayerTickAddr, &TickLocalplayerDetour, &__o__ticklp))
			return false;

		return true;
	}

	// singleton function to get our instance
	static PlayerHook& Get() {
		static PlayerHook single;
		return single;
	}
};