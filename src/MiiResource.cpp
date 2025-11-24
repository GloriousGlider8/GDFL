#include <stdlib.h>

#include "FFLResource.hpp"
#include "CommonDefs.hpp"
#include "Convert.hpp"

#include "MiiResource.hpp"

godot::Ref<MiiResource> MiiResource::FromFFRA(godot::PackedByteArray data) {
    godot::Ref<MiiResource> resource;
    resource.instantiate();

	miifu::FFLiResourceLoaderObjects objects;
	auto resourceHeader = std::make_unique<miifu::FFLiResourceHeader>();
	auto shapeHeader = std::make_unique<miifu::FFLiResourceShapeHeader>();
	auto textureHeader = std::make_unique<miifu::FFLiResourceTextureHeader>();

	miifu::ByteReader byteReader;
	std::shared_ptr<uint8_t []> brDat(new uint8_t[data.size()]);
	byteReader.data = brDat;
	byteReader.seek(0);

	memcpy(byteReader.data.get(), data.ptr(), data.size());

	miifu::FFLResource fflResource;

	fflResource.fromByteReader(byteReader, objects);

	// godot class filling-out logic here

	resource->origin = Origin::FFL;
	return resource;
};

void MiiResource::_bind_methods() {
	BIND_STATIC_METHOD("MiiResource", D_METHOD("from_ffra", "data"), &MiiResource::FromFFRA);
};