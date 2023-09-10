#pragma once

class InfAmmo : public Module {
public:
	InfAmmo() : Module::Module("InfAmmo", "Infinite Ammo", "yeemi#0", Keyboard::P) {};

	void OnTick(physent* player) override {
		loopi(NUMGUNS) player->ammo[i] = player->mag[i] = 100;
	};
};