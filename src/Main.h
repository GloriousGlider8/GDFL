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
    int body_height = 0;
    int body_weight = 0;
    int skin_color = 0;
    int face_type = 0;
    int face_makeup = 0;
    int face_wrinkles = 0;
    int hair_type = 0;
    int hair_color = 0;
    int glasses_color = 0;
    int eyebrow_horizontal = 0;
    int eye_vertical = 0;
    int facial_hair_beard = 0;
    int mouth_size = 0;
    int eyebrow_stretch = 0;
    int nose_vertical = 0;
    int eye_color = 0;
    int birth_month = 0;
    int mouth_color = 0;
    int mole_horizontal = 0;
    int facial_hair_mustache = 0;
    int eyebrow_rotation = 0;
    int mole_vertical = 0;
    int glasses_type = 0;
    int eyebrow_size = 0;
    int mole_size = 0;
    int nose_size = 0;
    int facial_hair_vertical = 0;
    int eye_stretch = 0;
    int eye_size = 0;
    int eye_type = 0;
    int eye_horizontal = 0;
    int eyebrow_type = 0;
    int mouth_vertical = 0;
    int eyebrow_color = 0;
    int nose_type = 0;
    int facial_hair_color = 0;
    int eyebrow_vertical = 0;
    int glasses_size = 0;
    int eye_rotation = 0;
    int birth_day = 0;
    int mouth_stretch = 0;
    int glasses_vertical = 0;
    int favorite_color = 0;
    int mouth_type = 0;
    int facial_hair_size = 0;
    
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