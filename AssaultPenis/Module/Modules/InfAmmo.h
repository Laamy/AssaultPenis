#pragma once

class InfAmmo : public Module {
public:
	InfAmmo() : Module::Module("InfAmmo", "Infinite Ammo", "yeemi#0", Keyboard::P) {};

	void OnTick(physent* player) override {
		// Loop through all guns and set ammo and mag size to 100
		loopi(NUMGUNS) player->ammo[i] = player->mag[i] = 100;

		loopi(NUMGUNS) player->pstatdamage[i] = 0;
	};
};