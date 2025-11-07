#pragma once

#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/core/binder_common.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/method_bind.hpp"
#include "godot_cpp/variant/utility_functions.hpp"
#include "godot_cpp/classes/resource.hpp"

#define D_METHOD godot::D_METHOD
#define BIND_METHOD godot::ClassDB::bind_method
#define BIND_STATIC_METHOD godot::ClassDB::bind_static_method
#define BIND_PROPERTY(prop, variant_type) \
	BIND_METHOD(D_METHOD("set_" #prop, "value"), &set_##prop); \
	BIND_METHOD(D_METHOD("get_" #prop), &get_##prop); \
	ADD_PROPERTY(godot::PropertyInfo(variant_type, #prop), "set_" #prop, "get_" #prop)

#define PROP_DEF(prop, type, default_value) \
	type prop = default_value; \
	void set_##prop(type value) { prop = value; } \
	type get_##prop() const { return prop; }