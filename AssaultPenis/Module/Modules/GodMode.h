#pragma once

class GodMode : public Module {
public:
	GodMode() : Module::Module("GodMode", "Infinite Health", "yeemi#0", Keyboard::L) {};

	void OnTick(physent* player) override {
		// set health & armour to 100 every tick (no damage)
		player->health = 100;
		player->armour = 100;
	};
};