#pragma once

#include "Module.h"

std::vector<Module*> modules;

#include "Modules/InfAmmo.h"
#include "Modules/GodMode.h"
#include "Modules/ImShort.h"
#include "Modules/Speed.h"
#include "Modules/Flight.h"

void InitMods() {
	modules.push_back(new InfAmmo());
	modules.push_back(new GodMode());
	modules.push_back(new ImShort());
	modules.push_back(new Speed());
	modules.push_back(new Flight());
}