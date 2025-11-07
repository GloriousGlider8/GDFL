#include "Mii.hpp"
#include "MiiResource.hpp"
#include "Convert.hpp"

#include "godot_cpp/core/class_db.hpp"

void register_all() {
	godot::ClassDB::register_class<Mii>();
	godot::ClassDB::register_class<MiiResource>();
	//godot::ClassDB::register_class<MiiDataConverter>();
}