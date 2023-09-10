#pragma once

#include "Module.h"

std::vector<Module*> modules;

#include "Modules/InfAmmo.h"
#include "Modules/GodMode.h"
#include "Modules/ImShort.h"

void InitMods() {
	modules.push_back(new InfAmmo());
	modules.push_back(new GodMode());
	modules.push_back(new ImShort());
}