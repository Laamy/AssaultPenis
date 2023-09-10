#pragma once

class Module {
public:
	std::string name;
	std::string description;
	std::string author;
	uintptr_t keybind;
	bool enabled = false;

	Module(std::string name, std::string description, std::string author, uintptr_t keybind) {
		this->name = name;
		this->description = description;
		this->author = author;
		this->keybind = keybind;
	}

	void SetEnabled(bool value) {
		if (value) {
			enabled = true;
			OnEnable();
		}
		else {
			enabled = false;
			OnDisable();
		}
	}

	// essential events
	virtual void OnEnable() {};
	virtual void OnDisable() {};

	// game events
	virtual void OnTick(physent* player) {};

	// rendering events
};