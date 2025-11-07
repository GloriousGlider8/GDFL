#pragma once

#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/core/binder_common.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/method_bind.hpp"
#include "godot_cpp/variant/utility_functions.hpp"
#include "godot_cpp/classes/resource.hpp"

enum Origin {
	RFL, // Wii / DS
	FFL, // Wii U / 3DS / AFL
	NN_MII, // Switch
	NXW // mii.nxw.pw
};

class MiiDataConverter : godot::Object {
	GDCLASS(MiiDataConverter, godot::Object)
};