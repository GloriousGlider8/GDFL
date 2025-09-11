#pragma once
// Copied from godot-cpp/test/src and modified.

#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/core/binder_common.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/method_bind.hpp"
#include "godot_cpp/variant/utility_functions.hpp"
#include "godot_cpp/classes/texture_rect.hpp"
#include "godot_cpp/classes/node3d.hpp"

#include "kty/mii_data.h"

#define PROP_DEF(prop, type, default_value) \
	type prop = default_value; \
	void set_##prop(type value) { prop = value; } \
	type get_##prop() const { return prop; }

class GDFLMii: public godot::Resource {
    GDCLASS(GDFLMii, godot::Resource)
public:
    PROP_DEF(mii_name, godot::String, godot::String("Unknown"));
    PROP_DEF(creator_name, godot::String, godot::String("Unknown"));
    PROP_DEF(initialised, bool, false);
    PROP_DEF(copying, bool, false);
    PROP_DEF(mingle, bool, false);
    PROP_DEF(hair_flip, bool, false);
    PROP_DEF(is_female, bool, false);
    PROP_DEF(is_favorite, bool, false);
    PROP_DEF(is_special, bool, false);
    PROP_DEF(mole_enable, bool, false);
    PROP_DEF(body_height, int, 0);
    PROP_DEF(body_weight, int, 0);
    PROP_DEF(birth_day, int, 0);
    PROP_DEF(birth_month, int, 0);
    PROP_DEF(eyebrow_color, int, 0);
    PROP_DEF(eyebrow_horizontal, int, 0);
    PROP_DEF(eyebrow_rotation, int, 0);
    PROP_DEF(eyebrow_size, int, 0);
    PROP_DEF(eyebrow_type, int, 0);
    PROP_DEF(eyebrow_vertical, int, 0);
    PROP_DEF(eyebrow_stretch, int, 0);
    PROP_DEF(facial_hair_beard, int, 0);
    PROP_DEF(facial_hair_color, int, 0);
    PROP_DEF(facial_hair_mustache, int, 0);
    PROP_DEF(facial_hair_size, int, 0);
    PROP_DEF(facial_hair_vertical, int, 0);
    PROP_DEF(face_makeup, int, 0);
    PROP_DEF(face_type, int, 0);
    PROP_DEF(face_wrinkles, int, 0);
    PROP_DEF(favorite_color, int, 0);
    PROP_DEF(glasses_color, int, 0);
    PROP_DEF(glasses_size, int, 0);
    PROP_DEF(glasses_type, int, 0);
    PROP_DEF(glasses_vertical, int, 0);
    PROP_DEF(hair_color, int, 0);
    PROP_DEF(hair_type, int, 0);
    PROP_DEF(mole_horizontal, int, 0);
    PROP_DEF(mole_size, int, 0);
    PROP_DEF(mole_vertical, int, 0);
    PROP_DEF(mouth_color, int, 0);
    PROP_DEF(mouth_size, int, 0);
    PROP_DEF(mouth_stretch, int, 0);
    PROP_DEF(mouth_type, int, 0);
    PROP_DEF(mouth_vertical, int, 0);
    PROP_DEF(nose_size, int, 0);
    PROP_DEF(nose_type, int, 0);
    PROP_DEF(nose_vertical, int, 0);
    PROP_DEF(eye_color, int, 0);
    PROP_DEF(eye_horizontal, int, 0);
    PROP_DEF(eye_rotation, int, 0);
    PROP_DEF(eye_size, int, 0);
    PROP_DEF(eye_stretch, int, 0);
    PROP_DEF(eye_type, int, 0);
    PROP_DEF(eye_vertical, int, 0);
    PROP_DEF(skin_color, int, 0);
    
    //void from_rsd(godot::PackedByteArray data);
    void from_ffsd(godot::PackedByteArray data);
    //void from_charinfo(godot::PackedByteArray data);
    //void from_studio(godot::PackedByteArray data);
    //void from_miic(godot::PackedByteArray data);
/*
    godot::PackedByteArray to_rsd();
    godot::PackedByteArray to_ffsd();
    godot::PackedByteArray to_charinfo();
    godot::PackedByteArray to_studio();
    godot::PackedByteArray to_miic();*/
protected:
    static void _bind_methods();
};

class GDFLMiiHead3D: public godot::Node3D {
    GDCLASS(GDFLMiiHead3D, godot::Node3D);
public:
    GDFLMii mii;
    PROP_DEF(expression, godot::String, godot::String("normal"));
    PROP_DEF(resource_high, bool, false);
    PROP_DEF(head_only, bool, false);

    void load_mii(GDFLMii mii);

protected:
    static void _bind_methods();
};

class GDFLMiiTextureRect: public godot::TextureRect {
    GDCLASS(GDFLMiiTextureRect, godot::TextureRect);
public:
    GDFLMii mii;
    PROP_DEF(expression, godot::String, godot::String("normal"));
    PROP_DEF(resolution, int, 800);
    PROP_DEF(resource_high, bool, false);
    PROP_DEF(head_only, bool, false);

    void load_mii(GDFLMii mii);

protected:
    static void _bind_methods();
};