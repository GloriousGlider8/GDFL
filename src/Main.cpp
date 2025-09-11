#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/method_bind.hpp"
#include "godot_cpp/variant/utility_functions.hpp"
#include "GDClassSTLConv.h"

#include "Main.h"
#include "kty/mii_data.h"

#define D_METHOD godot::D_METHOD
#define BIND_METHOD godot::ClassDB::bind_method
#define BIND_PROPERTY(prop, variant_type) \
	BIND_METHOD(D_METHOD("set_" #prop, "value"), &set_##prop); \
	BIND_METHOD(D_METHOD("get_" #prop), &get_##prop); \
	ADD_PROPERTY(godot::PropertyInfo(variant_type, #prop), "set_" #prop, "get_" #prop);

// GDFLMii

void GDFLMii::from_ffsd(godot::PackedByteArray data) {
    MemoryIStream stream(data.ptr(), data.size());
    kaitai::kstream ks(&stream);
    g2_t kty(&ks);

    mii_name = godot::String(kty.mii_name().c_str());
    creator_name = godot::String(kty.creator_name().c_str());
    copying = kty.copying();
    mingle = kty.mingle();
    hair_flip = kty.hair_flip();
    is_favorite = kty.favorite();
    is_female = (kty.gender() == 1);
    mole_enable = (kty.mole_enable() == 1);
    is_special = false;
    body_height = kty.body_height();
    body_weight = kty.body_weight();
    skin_color = kty.face_color();
    face_type = kty.face_type();
    face_makeup = kty.face_makeup();
    face_wrinkles = kty.face_wrinkles();
    hair_type = kty.hair_type();
    hair_color = kty.hair_color();
    glasses_color = kty.glasses_color();
    eyebrow_horizontal = kty.eyebrow_horizontal();
    eye_vertical = kty.eye_vertical();
    facial_hair_beard = kty.facial_hair_beard();
    mouth_size = kty.mouth_size();
    eyebrow_stretch = kty.eyebrow_stretch();
    nose_vertical = kty.nose_vertical();
    eye_color = kty.eye_color();
    birth_month = kty.birth_month();
    mouth_color = kty.mouth_color();
    mole_horizontal = kty.mole_horizontal();
    facial_hair_mustache = kty.facial_hair_mustache();
    eyebrow_rotation = kty.eyebrow_rotation();
    mole_vertical = kty.mole_vertical();
    glasses_type = kty.glasses_type();
    eyebrow_size = kty.eyebrow_size();
    mole_size = kty.mole_size();
    nose_size = kty.nose_size();
    facial_hair_vertical = kty.facial_hair_vertical();
    eye_stretch = kty.eye_stretch();
    eye_size = kty.eye_size();
    eye_type = kty.eye_type();
    eye_horizontal = kty.eye_horizontal();
    eyebrow_type = kty.eyebrow_type();
    mouth_vertical = kty.mouth_vertical();
    eyebrow_color = kty.eyebrow_color();
    nose_type = kty.nose_type();
    facial_hair_color = kty.facial_hair_color();
    eyebrow_vertical = kty.eyebrow_vertical();
    glasses_size = kty.glasses_size();
    eye_rotation = kty.eye_rotation();
    birth_day = kty.birth_day();
    mouth_stretch = kty.mouth_stretch();
    glasses_vertical = kty.glasses_vertical();
    favorite_color = kty.favorite_color();
    mouth_type = kty.mouth_type();
    facial_hair_size = kty.facial_hair_size();
    initialised = true;
};

void GDFLMii::_bind_methods() {
    BIND_METHOD(D_METHOD("from_ffsd", "data"), &from_ffsd);

    BIND_PROPERTY(creator_name, godot::Variant::STRING);
    BIND_PROPERTY(mii_name, godot::Variant::STRING);
    BIND_PROPERTY(copying, godot::Variant::BOOL);
    BIND_PROPERTY(hair_flip, godot::Variant::BOOL);
    BIND_PROPERTY(initialised, godot::Variant::BOOL);
    BIND_PROPERTY(is_favorite, godot::Variant::BOOL);
    BIND_PROPERTY(is_female, godot::Variant::BOOL);
    BIND_PROPERTY(mingle, godot::Variant::BOOL);
    BIND_PROPERTY(mole_enable, godot::Variant::BOOL);
    BIND_PROPERTY(is_special, godot::Variant::BOOL);
    BIND_PROPERTY(body_height, godot::Variant::INT);
    BIND_PROPERTY(body_weight, godot::Variant::INT);
    BIND_PROPERTY(birth_day, godot::Variant::INT);
    BIND_PROPERTY(birth_month, godot::Variant::INT);
    BIND_PROPERTY(eyebrow_color, godot::Variant::INT);
    BIND_PROPERTY(eyebrow_horizontal, godot::Variant::INT);
    BIND_PROPERTY(eyebrow_rotation, godot::Variant::INT);
    BIND_PROPERTY(eyebrow_size, godot::Variant::INT);
    BIND_PROPERTY(eyebrow_type, godot::Variant::INT);
    BIND_PROPERTY(eyebrow_vertical, godot::Variant::INT);
    BIND_PROPERTY(facial_hair_beard, godot::Variant::INT);
    BIND_PROPERTY(facial_hair_color, godot::Variant::INT);
    BIND_PROPERTY(facial_hair_mustache, godot::Variant::INT);
    BIND_PROPERTY(facial_hair_size, godot::Variant::INT);
    BIND_PROPERTY(facial_hair_vertical, godot::Variant::INT);
    BIND_PROPERTY(face_makeup, godot::Variant::INT);
    BIND_PROPERTY(face_type, godot::Variant::INT);
    BIND_PROPERTY(face_wrinkles, godot::Variant::INT);
    BIND_PROPERTY(favorite_color, godot::Variant::INT);
    BIND_PROPERTY(glasses_color, godot::Variant::INT);
    BIND_PROPERTY(glasses_size, godot::Variant::INT);
    BIND_PROPERTY(glasses_type, godot::Variant::INT);
    BIND_PROPERTY(glasses_vertical, godot::Variant::INT);
    BIND_PROPERTY(hair_color, godot::Variant::INT);
    BIND_PROPERTY(hair_type, godot::Variant::INT);
    BIND_PROPERTY(mole_horizontal, godot::Variant::INT);
    BIND_PROPERTY(mole_size, godot::Variant::INT);
    BIND_PROPERTY(mole_vertical, godot::Variant::INT);
    BIND_PROPERTY(mouth_color, godot::Variant::INT);
    BIND_PROPERTY(mouth_size, godot::Variant::INT);
    BIND_PROPERTY(mouth_stretch, godot::Variant::INT);
    BIND_PROPERTY(mouth_type, godot::Variant::INT);
    BIND_PROPERTY(mouth_vertical, godot::Variant::INT);
    BIND_PROPERTY(nose_size, godot::Variant::INT);
    BIND_PROPERTY(nose_type, godot::Variant::INT);
    BIND_PROPERTY(nose_vertical, godot::Variant::INT);
    BIND_PROPERTY(eye_color, godot::Variant::INT);
    BIND_PROPERTY(eye_horizontal, godot::Variant::INT);
    BIND_PROPERTY(eye_rotation, godot::Variant::INT);
    BIND_PROPERTY(eye_size, godot::Variant::INT);
    BIND_PROPERTY(eye_stretch, godot::Variant::INT);
    BIND_PROPERTY(eye_type, godot::Variant::INT);
    BIND_PROPERTY(eye_vertical, godot::Variant::INT);
};

//void GDFLMiiGLBProcessor::_bind_methods() {};

//void GDFLMiiPortrait::_bind_methods() {};