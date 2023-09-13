#pragma once

// module class which all modules inherit from
class Module {
public:
	std::string name;
	std::string description;
	std::string author;
	uintptr_t keybind;
	bool enabled = false;

	// constructor for module
	Module(std::string name, std::string description, std::string author, uintptr_t keybind) {
		this->name = name;
		this->description = description;
		this->author = author;
		this->keybind = keybind;

		Log("[*] Module Created %s", name.c_str());
	}

	// toggle module from given value with events
	void SetEnabled(bool value) {
		// toggle enabled value to given value
		enabled = value;

		// using :? operator to check if value is true or false & toggle events
		value ? OnEnable() : OnDisable();
	}

	// essential events
	virtual void OnEnable() {};
	virtual void OnDisable() {};

	// game events
	virtual void OnTick(physent* player) {};

	// rendering events
	// I should probably drop imgui events into here via a function
};