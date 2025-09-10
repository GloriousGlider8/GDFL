#pragma once
// Copied from godot-cpp/test/src and modified.

#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/core/binder_common.hpp"
#include "godot_cpp/classes/texture_rect.hpp"

#include "kty/mii_data.h"

class GDFLMii : public godot::Resource {
    GDCLASS( GDFLMii, godot::Resource )
public:
    godot::String mii_name = godot::String("");
    godot::String creator_name = godot::String("");
    bool initialised = false;
    bool copying = false;
    bool mingle = false;
    bool hair_flip = false;
    bool is_female = false;
    bool is_favorite = false;
    bool is_special = false;
    bool mole_enable = false;
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

class GDFLBasicTestClass : public godot::Object {
    GDCLASS(GDFLBasicTestClass, godot::Object);
public:
    void test_func();
    GDFLBasicTestClass();

protected:
    static void _bind_methods();
};

/*class GDFLMiiGLBProcessor : public godot::Node {
    GDCLASS( GDFLMiiGLBProcessor, godot::Node )
public:
    GDFLMii mii;
    godot::String expression = "normal";
    bool resource_high = false;
    bool head_only = false;

    //godot::PackedByteArray get_glb();

protected:
    static void _bind_methods();
};

class GDFLMiiPortrait : public godot::TextureRect {
    GDCLASS( GDFLMiiPortrait, godot::TextureRect )
public:
    GDFLMii mii;
    godot::String expression = "normal";
    int resolution = 800;
    bool resource_high = false;
    bool head_only = false;

protected:
    static void _bind_methods();
};*/