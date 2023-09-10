#pragma once

class ImShort : public Module {
public:
	ImShort() : Module::Module("ImShort", "Makes you short", "yeemi#0", Keyboard::K) {};

	void OnTick(physent* player) override {
		// set eyeheight to 1 (default is 4.6-ish)
		player->eyeheight = 1;
	};
};