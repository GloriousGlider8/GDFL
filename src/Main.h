#pragma once
// Copied from godot-cpp/test/src and modified.

#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/core/binder_common.hpp"
#include "godot_cpp/classes/texture_rect.hpp"

class GDFLMii : public godot::Resource
{
    GDCLASS( GDFLMii, godot::Resource )

public:
    GDFLMii();
    ~GDFLMii() override;

    bool initialised = false;
    int generation = 0;
    bool copying;
    godot::String mii_name;
    int body_height;
    int body_weight;
    int skin_color;
    int face_type;
    bool mingle;
    int face_makeup;
    int face_wrinkles;
    int hair_type;
    bool hair_flip;
    int hair_color;
    godot::String creator_name;
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
    bool is_female;
    int birth_day;
    int mouth_stretch;
    int mole_enable;
    bool is_favorite;
    bool is_special;
    int glasses_vertical;
    int favorite_color;
    int mouth_type;
    int facial_hair_size;
    
    virtual void load_data(godot::PackedByteArray data);
    virtual godot::PackedByteArray get_data();

protected:
    static void _bind_methods();
};

class GDFLG1Mii : public GDFLMii
{
    GDCLASS( GDFLG1Mii, GDFLMii )

public:
    GDFLG1Mii();
    ~GDFLG1Mii() override;
    
    int generation = 1;

    void load_data(godot::PackedByteArray data) override;

protected:
    static void _bind_methods();
};

class GDFLG2Mii : public GDFLMii
{
    GDCLASS( GDFLG2Mii, GDFLMii )

public:
    GDFLG2Mii();
    ~GDFLG2Mii() override;
    
    int generation = 2;

    void load_data(godot::PackedByteArray data) override;

protected:
    static void _bind_methods();
};

class GDFLG3Mii : public GDFLMii
{
    GDCLASS( GDFLG3Mii, GDFLMii )

public:
    GDFLG3Mii();
    ~GDFLG3Mii() override;
    
    int generation = 3;

    void load_data(godot::PackedByteArray data) override;

protected:
    static void _bind_methods();
};

class GDFLG4Mii : public GDFLMii
{
    GDCLASS( GDFLG4Mii, GDFLMii )

public:
    GDFLG4Mii();
    ~GDFLG4Mii() override;
    
    int generation = 4;

    void load_data(godot::PackedByteArray data) override;

protected:
    static void _bind_methods();
};

class GDFLMiiGLBRenderer : public godot::Node
{
    GDCLASS( GDFLMiiGLBRenderer, godot::Node )

public:
    GDFLMiiGLBRenderer();
    ~GDFLMiiGLBRenderer() override;

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