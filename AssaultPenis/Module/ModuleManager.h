#pragma once

#include "Module.h"

std::vector<Module*> modules;

#include "Modules/InfAmmo.h"

void InitMods() {
	modules.push_back(new InfAmmo());

	modules[0]->SetEnabled(true);
}