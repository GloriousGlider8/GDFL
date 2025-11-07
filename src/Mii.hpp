#pragma once

#include "CommonDefs.hpp"
#include "Convert.hpp"

class Mii: public godot::Resource {
    GDCLASS(Mii, godot::Resource)
public:
	Origin origin;

	PROP_DEF(initialised, bool, false)

	PROP_DEF(mii_version, int, 0)
	PROP_DEF(face_type, int, 0)
	PROP_DEF(face_color, int, 0)
	PROP_DEF(face_tex, int, 0)
	PROP_DEF(face_make, int, 0)
	PROP_DEF(hair_type, int, 0)
	PROP_DEF(hair_color, int, 0)
	PROP_DEF(hair_flip, int, 0)
	PROP_DEF(eye_type, int, 0)
	PROP_DEF(eye_color, int, 0)
	PROP_DEF(eye_scale, int, 0)
	PROP_DEF(eye_aspect, int, 0)
	PROP_DEF(eye_rotate, int, 0)
	PROP_DEF(eye_x, int, 0)
	PROP_DEF(eye_y, int, 0)
	PROP_DEF(eyebrow_type, int, 0)
	PROP_DEF(eyebrow_color, int, 0)
	PROP_DEF(eyebrow_scale, int, 0)
	PROP_DEF(eyebrow_aspect, int, 0)
	PROP_DEF(eyebrow_rotate, int, 0)
	PROP_DEF(eyebrow_x, int, 0)
	PROP_DEF(eyebrow_y, int, 0)
	PROP_DEF(nose_type, int, 0)
	PROP_DEF(nose_scale, int, 0)
	PROP_DEF(nose_y, int, 0)
	PROP_DEF(mouth_type, int, 0)
	PROP_DEF(mouth_color, int, 0)
	PROP_DEF(mouth_scale, int, 0)
	PROP_DEF(mouth_aspect, int, 0)
	PROP_DEF(mouth_y, int, 0)
	PROP_DEF(mustache_type, int, 0)
	PROP_DEF(beard_type, int, 0)
	PROP_DEF(beard_color, int, 0)
	PROP_DEF(beard_scale, int, 0)
	PROP_DEF(beard_y, int, 0)
	PROP_DEF(glass_type, int, 0)
	PROP_DEF(glass_color, int, 0)
	PROP_DEF(glass_scale, int, 0)
	PROP_DEF(glass_y, int, 0)
	PROP_DEF(mole_type, int, 0)
	PROP_DEF(mole_scale, int, 0)
	PROP_DEF(mole_x, int, 0)
	PROP_DEF(mole_y, int, 0)
	PROP_DEF(height, int, 0)
	PROP_DEF(build, int, 0)
	PROP_DEF(name, godot::String, godot::String("Unknown"))
	PROP_DEF(creator_name, godot::String, godot::String("Unknown"))
	PROP_DEF(gender, int, 0)
	PROP_DEF(birth_month, int, 0)
	PROP_DEF(birth_day, int, 0)
	PROP_DEF(favorite_color, int, 0)
	PROP_DEF(favorite, bool, false)
	PROP_DEF(copyable, bool, false)
	PROP_DEF(ng_word, bool, false)
	PROP_DEF(local_only, bool, false)
	PROP_DEF(region_move, int, 0)
	PROP_DEF(font_region, int, 0)
	PROP_DEF(room_index, int, 0)
	PROP_DEF(position_in_room, int, 0)
	PROP_DEF(birth_platform, int, 0)
	PROP_DEF(create_id, godot::PackedByteArray, godot::PackedByteArray())
	PROP_DEF(author_type, int, 0)
	PROP_DEF(author_id, godot::PackedByteArray, godot::PackedByteArray())

	static godot::Ref<Mii> New();

    //static godot::Ref<Mii> FromRSD(godot::PackedByteArray data);
    static godot::Ref<Mii> FromVer3(godot::PackedByteArray data);
    //static godot::Ref<Mii> FromCharInfo(godot::PackedByteArray data);
    //static godot::Ref<Mii> FromStudio(godot::PackedByteArray data);
    //static godot::Ref<Mii> FromMiiC(godot::PackedByteArray data);
/*
    godot::PackedByteArray ToRSD();
    godot::PackedByteArray ToVer3();
    godot::PackedByteArray ToCharInfo();
    godot::PackedByteArray ToStudio();
    godot::PackedByteArray ToMiiC();*/
protected:
    static void _bind_methods();
};