#include <stdlib.h>

#include "Ver3StoreData.hpp"
#include "CommonDefs.hpp"
#include "Convert.hpp"

#include "Mii.hpp"

godot::Ref<Mii> Mii::FromVer3(godot::PackedByteArray data) {
    godot::Ref<Mii> mii;
    mii.instantiate();
    
    std::shared_ptr<miifu::Ver3CharInfo> charInfo = std::make_unique<miifu::Ver3CharInfo>();
	miifu::Ver3StoreData::setFromBytes(data.ptr(), charInfo);
	
    mii->mii_version = charInfo->getMiiVersion();

	mii->face_type = charInfo->getFaceType();
	mii->face_color = charInfo->getFaceColor();
	mii->face_tex = charInfo->getFaceTex();
	mii->face_make = charInfo->getFaceMake();

	mii->hair_type = charInfo->getHairType();
	mii->hair_color = charInfo->getHairColor();
	mii->hair_flip = charInfo->getHairFlip();

	mii->eye_type = charInfo->getEyeType();
	mii->eye_color = charInfo->getEyeColor();
	mii->eye_scale = charInfo->getEyeScale();
	mii->eye_aspect = charInfo->getEyeAspect();
	mii->eye_rotate = charInfo->getEyeRotate();
	mii->eye_x = charInfo->getEyeX();
	mii->eye_y = charInfo->getEyeY();

	mii->eyebrow_type = charInfo->getEyebrowType();
	mii->eyebrow_color = charInfo->getEyebrowColor();
	mii->eyebrow_scale = charInfo->getEyebrowScale();
	mii->eyebrow_aspect = charInfo->getEyebrowAspect();
	mii->eyebrow_rotate = charInfo->getEyebrowRotate();
	mii->eyebrow_x = charInfo->getEyebrowX();
	mii->eyebrow_y = charInfo->getEyebrowY();

	mii->nose_type = charInfo->getNoseType();
	mii->nose_scale = charInfo->getNoseScale();
	mii->nose_y = charInfo->getNoseY();

	mii->mouth_type = charInfo->getMouthType();
	mii->mouth_color = charInfo->getMouthColor();
	mii->mouth_scale = charInfo->getMouthScale();
	mii->mouth_aspect = charInfo->getMouthAspect();
	mii->mouth_y = charInfo->getMouthY();

	mii->mustache_type = charInfo->getMustacheType();

	mii->beard_type = charInfo->getBeardType();
	mii->beard_color = charInfo->getBeardColor();
	mii->beard_scale = charInfo->getBeardScale();
	mii->beard_y = charInfo->getBeardY();

	mii->glass_type = charInfo->getGlassType();
	mii->glass_color = charInfo->getGlassColor();
	mii->glass_scale = charInfo->getGlassScale();
	mii->glass_y = charInfo->getGlassY();

	mii->mole_type = charInfo->getMoleType();
	mii->mole_scale = charInfo->getMoleScale();
	mii->mole_x = charInfo->getMoleX();
	mii->mole_y = charInfo->getMoleY();

	mii->height = charInfo->getHeight();
	mii->build = charInfo->getBuild();

	std::string s = miifu::Utf16ToUtf8Converter::convert(charInfo->getName(), 11);
	mii->name = godot::String(s.c_str());

	s = miifu::Utf16ToUtf8Converter::convert(charInfo->getCreatorName(), 11);
	mii->creator_name = godot::String(s.c_str());

	mii->gender = charInfo->getGender();

	mii->birth_month = charInfo->getBirthDay();
	mii->birth_day = charInfo->getBirthMonth();
	mii->birth_platform = charInfo->getBirthPlatform();

	mii->favorite_color = charInfo->getFavoriteColor();

	mii->favorite = charInfo->getFavorite();
	mii->copyable = charInfo->getCopyable();
	mii->ng_word = charInfo->getNgWord();
	mii->local_only = charInfo->getLocalonly();

	mii->region_move = charInfo->getRegionMove();
	mii->font_region = charInfo->getFontRegion();

	mii->room_index = charInfo->getRoomIndex();
	mii->position_in_room = charInfo->getPositionInRoom();

	const uint8_t *createId = charInfo->getCreateId();
	godot::PackedByteArray arr;
	arr.resize(10);
	std::memcpy(arr.ptrw(), createId, 10);
	mii->create_id = arr;

	mii->author_type = charInfo->getAuthorType();

	const uint8_t *authorId = charInfo->getAuthorId();
	godot::PackedByteArray arr1;
	arr1.resize(8);
	std::memcpy(arr1.ptrw(), authorId, 8);
	mii->author_id = arr1;
    
    mii->initialised = true;
	mii->origin = Origin::FFL;
    return mii;
};

godot::Ref<Mii> Mii::New() {
    godot::Ref<Mii> mii;
    mii.instantiate();

	return mii;
};

void Mii::_bind_methods() {
    BIND_STATIC_METHOD("Mii", D_METHOD("from_v3", "data"), &Mii::FromVer3);
	BIND_STATIC_METHOD("Mii", D_METHOD("new"), &Mii::New);

	BIND_PROPERTY(mii_version, godot::Variant::INT);
	BIND_PROPERTY(face_type, godot::Variant::INT);
	BIND_PROPERTY(face_color, godot::Variant::INT);
	BIND_PROPERTY(face_tex, godot::Variant::INT);
	BIND_PROPERTY(face_make, godot::Variant::INT);
	BIND_PROPERTY(hair_type, godot::Variant::INT);
	BIND_PROPERTY(hair_color, godot::Variant::INT);
	BIND_PROPERTY(hair_flip, godot::Variant::INT);
	BIND_PROPERTY(eye_type, godot::Variant::INT);
	BIND_PROPERTY(eye_color, godot::Variant::INT);
	BIND_PROPERTY(eye_scale, godot::Variant::INT);
	BIND_PROPERTY(eye_aspect, godot::Variant::INT);
	BIND_PROPERTY(eye_rotate, godot::Variant::INT);
	BIND_PROPERTY(eye_x, godot::Variant::INT);
	BIND_PROPERTY(eye_y, godot::Variant::INT);
	BIND_PROPERTY(eyebrow_type, godot::Variant::INT);
	BIND_PROPERTY(eyebrow_color, godot::Variant::INT);
	BIND_PROPERTY(eyebrow_scale, godot::Variant::INT);
	BIND_PROPERTY(eyebrow_aspect, godot::Variant::INT);
	BIND_PROPERTY(eyebrow_rotate, godot::Variant::INT);
	BIND_PROPERTY(eyebrow_x, godot::Variant::INT);
	BIND_PROPERTY(eyebrow_y, godot::Variant::INT);
	BIND_PROPERTY(nose_type, godot::Variant::INT);
	BIND_PROPERTY(nose_scale, godot::Variant::INT);
	BIND_PROPERTY(nose_y, godot::Variant::INT);
	BIND_PROPERTY(mouth_type, godot::Variant::INT);
	BIND_PROPERTY(mouth_color, godot::Variant::INT);
	BIND_PROPERTY(mouth_scale, godot::Variant::INT);
	BIND_PROPERTY(mouth_aspect, godot::Variant::INT);
	BIND_PROPERTY(mouth_y, godot::Variant::INT);
	BIND_PROPERTY(mustache_type, godot::Variant::INT);
	BIND_PROPERTY(beard_type, godot::Variant::INT);
	BIND_PROPERTY(beard_color, godot::Variant::INT);
	BIND_PROPERTY(beard_scale, godot::Variant::INT);
	BIND_PROPERTY(beard_y, godot::Variant::INT);
	BIND_PROPERTY(glass_type, godot::Variant::INT);
	BIND_PROPERTY(glass_color, godot::Variant::INT);
	BIND_PROPERTY(glass_scale, godot::Variant::INT);
	BIND_PROPERTY(glass_y, godot::Variant::INT);
	BIND_PROPERTY(mole_type, godot::Variant::INT);
	BIND_PROPERTY(mole_scale, godot::Variant::INT);
	BIND_PROPERTY(mole_x, godot::Variant::INT);
	BIND_PROPERTY(mole_y, godot::Variant::INT);
	BIND_PROPERTY(height, godot::Variant::INT);
	BIND_PROPERTY(build, godot::Variant::INT);
	BIND_PROPERTY(name, godot::Variant::STRING);
	BIND_PROPERTY(creator_name, godot::Variant::STRING);
	BIND_PROPERTY(gender, godot::Variant::INT);
	BIND_PROPERTY(birth_month, godot::Variant::INT);
	BIND_PROPERTY(birth_day, godot::Variant::INT);
	BIND_PROPERTY(favorite_color, godot::Variant::INT);
	BIND_PROPERTY(favorite, godot::Variant::BOOL);
	BIND_PROPERTY(copyable, godot::Variant::BOOL);
	BIND_PROPERTY(ng_word, godot::Variant::BOOL);
	BIND_PROPERTY(local_only, godot::Variant::BOOL);
	BIND_PROPERTY(region_move, godot::Variant::INT);
	BIND_PROPERTY(font_region, godot::Variant::INT);
	BIND_PROPERTY(room_index, godot::Variant::INT);
	BIND_PROPERTY(position_in_room, godot::Variant::INT);
	BIND_PROPERTY(birth_platform, godot::Variant::INT);
	BIND_PROPERTY(create_id, godot::Variant::PACKED_BYTE_ARRAY);
	BIND_PROPERTY(author_type, godot::Variant::INT);
	BIND_PROPERTY(author_id, godot::Variant::PACKED_BYTE_ARRAY);
};