#pragma once

#include "CommonDefs.hpp"
#include "Convert.hpp"

class MiiResource : public godot::Resource {
	GDCLASS(MiiResource, godot::Resource)
public:
	Origin origin;

	PROP_DEF(initialised, bool, false)

	//PROP_DEF(afl)

	static godot::Ref<MiiResource> FromFFRA(godot::PackedByteArray data);
protected:
    static void _bind_methods();
};