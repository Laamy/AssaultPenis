#pragma once

#include "../../SDK/physent.h"

void* __o__ticklp;

void TickLocalplayerDetour(void* _this, physent* player) {

	player->maxSpeed

	// dont call original else ur gonna crash it
}

class PlayerHook : public FuncHook {
public:
	bool Initialize() override {
		uintptr_t localPlayerTickAddr = findOffset("8B D1 83 EC 0C F3", "LocalPlayer");

		if (not HookFunction((void*)localPlayerTickAddr, &TickLocalplayerDetour, &__o__ticklp))
			return false;

		return true;
	}

	static PlayerHook& Get() {
		static PlayerHook single;
		return single;
	}
};