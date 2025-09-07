#pragma once
// Copied from godot-cpp/test/src and modified.

#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/core/binder_common.hpp"
#include "godot_cpp/classes/texture_rect.hpp"

#include "kty/mii_data.h"

class GDFLMii : public godot::Resource
{
    GDCLASS( GDFLMii, godot::Resource )

public:
    GDFLMii();
    ~GDFLMii() override;

    godot::String mii_name;
    godot::String creator_name;
    bool initialised = false;
    bool copying;
    bool mingle;
    bool hair_flip;
    bool is_female;
    bool is_favorite;
    bool is_special;
    bool mole_enable;
    int body_height;
    int body_weight;
    int skin_color;
    int face_type;
    int face_makeup;
    int face_wrinkles;
    int hair_type;
    int hair_color;
    int glasses_color;
    int eyebrow_horizontal;
    int eye_vertical;
    int facial_hair_beard;
    int mouth_size;
    int eyebrow_stretch;
    int nose_vertical;
    int eye_color;
    int birth_month;
    int mouth_color;
    int mole_horizontal;
    int facial_hair_mustache;
    int eyebrow_rotation;
    int mole_vertical;
    int glasses_type;
    int eyebrow_size;
    int mole_size;
    int nose_size;
    int facial_hair_vertical;
    int eye_stretch;
    int eye_size;
    int eye_type;
    int eye_horizontal;
    int eyebrow_type;
    int mouth_vertical;
    int eyebrow_color;
    int nose_type;
    int facial_hair_color;
    int eyebrow_vertical;
    int glasses_size;
    int eye_rotation;
    int birth_day;
    int mouth_stretch;
    int glasses_vertical;
    int favorite_color;
    int mouth_type;
    int facial_hair_size;
    
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
class GDFLMiiGLBProcessor : public godot::Node
{
    GDCLASS( GDFLMiiGLBProcessor, godot::Node )

public:
    GDFLMiiGLBProcessor();
    ~GDFLMiiGLBProcessor() override;

    GDFLMii mii;
    godot::String expression = "normal";
    bool resource_high = false;
    bool head_only = false;

    godot::PackedByteArray get_glb();

protected:
    static void _bind_methods();
};

class GDFLMiiPortrait : public godot::TextureRect
{
    GDCLASS( GDFLMiiPortrait, godot::TextureRect )

public:
    GDFLMiiPortrait();
    ~GDFLMiiPortrait() override;

    GDFLMii mii;
    godot::String expression = "normal";
    int resolution = 800;
    bool resource_high = false;
    bool head_only = false;

protected:
    static void _bind_methods();
};