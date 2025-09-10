// Copied from godot-cpp/test/src and modified.

#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/method_bind.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

#include "Main.h"
#include "kty/mii_data.h"

// Used to mark unused parameters to indicate intent and suppress warnings.
#define UNUSED( expr ) (void)( expr )

// GDFLMii
void GDFLMii::from_ffsd(godot::PackedByteArray data) {
    godot::UtilityFunctions::print(data);
    std::string buf(reinterpret_cast<const char*>(data.ptr()), data.size());
    godot::UtilityFunctions::print("a");

    kaitai::kstream ks(buf.c_str());
    godot::UtilityFunctions::print("b");
    g2_t kty(&ks);
    godot::UtilityFunctions::print("c");

    this->mii_name = godot::String(kty.mii_name().c_str());
    this->creator_name = godot::String(kty.creator_name().c_str());
    this->copying = kty.copying();
    this->mingle = kty.mingle();
    this->hair_flip = kty.hair_flip();
    this->is_favorite = kty.favorite();
    this->is_female = (kty.gender() == 1);
    this->mole_enable = (kty.mole_enable() == 1);
    this->is_special = false;
    this->body_height = kty.body_height();
    this->body_weight = kty.body_weight();
    this->skin_color = kty.face_color();
    this->face_type = kty.face_type();
    this->face_makeup = kty.face_makeup();
    this->face_wrinkles = kty.face_wrinkles();
    this->hair_type = kty.hair_type();
    this->hair_color = kty.hair_color();
    this->glasses_color = kty.glasses_color();
    this->eyebrow_horizontal = kty.eyebrow_horizontal();
    this->eye_vertical = kty.eye_vertical();
    this->facial_hair_beard = kty.facial_hair_beard();
    this->mouth_size = kty.mouth_size();
    this->eyebrow_stretch = kty.eyebrow_stretch();
    this->nose_vertical = kty.nose_vertical();
    this->eye_color = kty.eye_color();
    this->birth_month = kty.birth_month();
    this->mouth_color = kty.mouth_color();
    this->mole_horizontal = kty.mole_horizontal();
    this->facial_hair_mustache = kty.facial_hair_mustache();
    this->eyebrow_rotation = kty.eyebrow_rotation();
    this->mole_vertical = kty.mole_vertical();
    this->glasses_type = kty.glasses_type();
    this->eyebrow_size = kty.eyebrow_size();
    this->mole_size = kty.mole_size();
    this->nose_size = kty.nose_size();
    this->facial_hair_vertical = kty.facial_hair_vertical();
    this->eye_stretch = kty.eye_stretch();
    this->eye_size = kty.eye_size();
    this->eye_type = kty.eye_type();
    this->eye_horizontal = kty.eye_horizontal();
    this->eyebrow_type = kty.eyebrow_type();
    this->mouth_vertical = kty.mouth_vertical();
    this->eyebrow_color = kty.eyebrow_color();
    this->nose_type = kty.nose_type();
    this->facial_hair_color = kty.facial_hair_color();
    this->eyebrow_vertical = kty.eyebrow_vertical();
    this->glasses_size = kty.glasses_size();
    this->eye_rotation = kty.eye_rotation();
    this->birth_day = kty.birth_day();
    this->mouth_stretch = kty.mouth_stretch();
    this->glasses_vertical = kty.glasses_vertical();
    this->favorite_color = kty.favorite_color();
    this->mouth_type = kty.mouth_type();
    this->facial_hair_size = kty.facial_hair_size();
    this->initialised = true;
    godot::UtilityFunctions::print("d");
};

void GDFLMii::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("from_ffsd", "data"), &GDFLMii::from_ffsd);
};

void GDFLBasicTestClass::test_func() {
    godot::UtilityFunctions::print("worked, bitch");
};

void GDFLBasicTestClass::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("test_func"), &GDFLBasicTestClass::test_func);
};

GDFLBasicTestClass::GDFLBasicTestClass() {
    godot::UtilityFunctions::print("constructed, bitch");
}

//void GDFLMiiGLBProcessor::_bind_methods() {};

//void GDFLMiiPortrait::_bind_methods() {};