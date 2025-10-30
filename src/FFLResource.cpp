// Generated automatically with "fut". Do not edit.
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include "FFLResource.hpp"

void BitConverter::convert1010102ToFloat(int packed, float * outVec, int offset)
{
	int nx = packed << 22 >> 22;
	int ny = packed << 12 >> 22;
	int nz = packed << 2 >> 22;
	outVec[offset * 3 + 0] = static_cast<float>(nx / 511.0);
	outVec[offset * 3 + 1] = static_cast<float>(ny / 511.0);
	outVec[offset * 3 + 2] = static_cast<float>(nz / 511.0);
}

void BitConverter::convert8888SnormToFloat(int packed, float * outVec)
{
	int r = packed >> 16 & 255;
	int g = packed >> 8 & 255;
	int b = packed & 255;
	int a = packed >> 24 & 255;
	if (r > 127)
		r -= 256;
	if (g > 127)
		g -= 256;
	if (b > 127)
		b -= 256;
	if (a > 127)
		a -= 256;
	outVec[0] = static_cast<float>(r / 127.0);
	outVec[1] = static_cast<float>(g / 127.0);
	outVec[2] = static_cast<float>(b / 127.0);
	outVec[3] = static_cast<float>(a / 127.0);
}

float BitConverter::halfToFloat(int half)
{
	int sign = half >> 15 & 1;
	int exp = half >> 10 & 31;
	int mant = half & 1023;
	int f;
	if (exp == 0) {
		if (mant == 0) {
			f = sign << 31;
		}
		else {
			exp = 1;
			while ((mant & 1024) == 0) {
				mant <<= 1;
				exp--;
			}
			mant &= 1023;
			exp += 112;
			f = sign << 31 | exp << 23 | mant << 13;
		}
	}
	else if (exp == 31) {
		f = sign << 31 | 2139095040 | mant << 13;
	}
	else {
		int add = 112;
		exp = exp + add;
		f = sign << 31 | exp << 23 | mant << 13;
	}
	return uIntToFloat(f);
}

float BitConverter::uIntToFloat(int bits)
{
	 return *(float *)&bits; return 0.0f;
}

int BitConverter::floatToInt(float v)
{
	 return *(int *)&v; return 0;
}

void BitfieldReader::seek(int where)
{
	this->offset = where;
}

void BitfieldReader::padding(int size)
{
	this->offset += size;
}

bool BitfieldReader::readBool()
{
	return (this->value & 1 << this->offset++) != 0;
}

int BitfieldReader::readBits(int size)
{
	int result = 0;
	for (int i = 0; i < size; i++) {
		int bit = this->value >> this->offset++ & 1;
		result |= bit << i;
	}
	return result;
}

void ByteReader::seek(int where)
{
	this->offset = where;
}

void ByteReader::padding(int size)
{
	this->offset += size;
}

int ByteReader::readByte()
{
	return this->data[this->offset++];
}

int ByteReader::readUShort(int size)
{
	int res = 0;
	for (int i = 0; i < size; i++) {
		res = res << 8 | this->data[this->offset++];
	}
	return res;
}

int ByteReader::readUInt(int size)
{
	int res = 0;
	for (int i = 0; i < size; i++) {
		res = res << 8 | this->data[this->offset++];
	}
	return res;
}

int ByteReader::readSShort(int size)
{
	int res = 0;
	for (int i = 0; i < size; i++) {
		res = res << 8 | this->data[this->offset++];
	}
	int sign_bit = 1 << (size * 8 - 1);
	if ((res & sign_bit) != 0) {
		res -= 1 << size * 8;
	}
	return res;
}

int ByteReader::readSInt(int size)
{
	int res = 0;
	for (int i = 0; i < size; i++) {
		res = res << 8 | this->data[this->offset++];
	}
	int sign_bit = 1 << (size * 8 - 1);
	if ((res & sign_bit) != 0) {
		res -= 1 << size * 8;
	}
	return res;
}

int64_t ByteReader::readSLong(int size)
{
	int64_t res = 0;
	for (int i = 0; i < size; i++) {
		res = res << 8 | this->data[this->offset++];
	}
	int sign_bit = 1 << (size * 8 - 1);
	if ((res & sign_bit) != 0) {
		res -= 1 << size * 8;
	}
	return res;
}

BitfieldReader ByteReader::getBitfield()
{
	BitfieldReader b;
	b.value = this->data[this->offset++];
	return b;
}

float ByteReader::readFloat()
{
	int raw = readUInt(4);
	return BitConverter::uIntToFloat(raw);
}

std::string ByteReader::readUTF8(int size)
{
	this->offset += size;
	return std::string(reinterpret_cast<const char *>(this->data.get() + (this->offset - size)), size);
}

void ByteReader::readRaw(int size, uint8_t * buffer)
{
	std::copy_n(this->data.get() + this->offset, size, buffer);
	this->offset += size;
}

void ZlibImpl::decompress(uint8_t const * input, uint8_t const * output, int windowBits, int originalSize)
{
	std::cout << "!! DEFAULT ZlibImpl DOES NOT DO ANYTHING !!\n";
	std::abort(); // "You're still using the default ZlibImpl, please override it!"
}

void ZlibImpl::compress(uint8_t const * input, uint8_t const * output, int level, int windowBits)
{
	std::cout << "!! DEFAULT ZlibImpl DOES NOT DO ANYTHING !!\n";
	std::abort(); // "You're still using the default ZlibImpl, please override it!"
}

void Vec3::fromByteReader(ByteReader data)
{
	this->x = data.readFloat();
	this->y = data.readFloat();
	this->z = data.readFloat();
}

void Vec3::setNaN()
{
	this->x = NAN;
	this->y = NAN;
	this->z = NAN;
}

void BoundingBox::fromByteReader(ByteReader data)
{
	this->min.fromByteReader(data);
	this->max.fromByteReader(data);
}

void BoundingBox::setNaN()
{
	this->min.setNaN();
	this->max.setNaN();
}

int WindowBitConverter::fFLiResourceWindowBitsToZlibWindowBits(int windowBits)
{
	if (windowBits <= 7) {
		return windowBits + 8;
	}
	if (windowBits >= 8 && windowBits <= 15) {
		return windowBits + 16;
	}
	if (windowBits == 16) {
		return 47;
	}
	return 15;
}

void FFLiPartData::fromByteReader(ByteReader bUtils, int size)
{
	for (int i = 0; i < 6; i++) {
		if (this->header->elementSize[i] <= 20000000 && this->header->elementSize[i] > 0) {
			bUtils.seek(this->header->elementOffset[i]);
			bUtils.readRaw(this->header->elementSize[i], this->data[i].data());
		}
	}
	bool a = true;
	for (int i : this->header->elementSize) {
		if (i <= 20000000 && i > 0) {
			a = false;
		}
	}
	if (a) {
		setUnused();
		return;
	}
	bUtils.seek(size - 16);
	this->footer->fromByteReader(bUtils);
}

ByteReader FFLiPartData::loadHeader(std::shared_ptr<uint8_t[]> data)
{
	ByteReader bUtils;
	bUtils.data = data;
	this->header->fromByteReader(bUtils);
	this->used = true;
	return bUtils;
}

void FFLiPartData::setUnused()
{
	this->used = false;
	this->header->setUnused();
}

void FFLiPartDataHeader::fromByteReader(ByteReader bUtils)
{
	for (int i = 0; i < 6; i++) {
		this->elementOffset[i] = bUtils.readSInt(4);
	}
	for (int i = 0; i < 6; i++) {
		this->elementSize[i] = bUtils.readSInt(4);
	}
	if (this->elementSize[static_cast<int>(FFLiResourceShapeElementType::index)] < 20000000) {
		this->elementSize[static_cast<int>(FFLiResourceShapeElementType::index)] *= 2;
	}
	this->boundingBox.fromByteReader(bUtils);
	for (int i = 0; i < 6; i++) {
		this->transform[i].fromByteReader(bUtils);
	}
}

void FFLiPartDataHeader::setUnused()
{
	this->boundingBox.setNaN();
}

void FFLiPartDataFooter::fromByteReader(ByteReader data)
{
	this->mipOffset = data.readUInt(4);
	this->width = data.readUShort(2);
	this->height = data.readUShort(2);
	int t = data.readByte();
	if (t < 3) {
		this->format = static_cast<FFLiTextureFormat>(t);
	}
	this->mipCount = data.readByte();
	data.padding(2);
}

void FFLiResourcePartsInfo::fromByteReader(ByteReader data, FFLiResourceLoaderObjects objects)
{
	this->offset = data.readUInt(4);
	this->uncompressedSize = data.readUInt(4);
	assert(this->uncompressedSize < 20000000 && this->uncompressedSize % 2 == 0 && "Uncompressed Size invalid (should pass UncompressedSize < 20000000 and (UncompressedSize % 2) == 0)");
	this->compressedSize = data.readUInt(4);
	assert(this->compressedSize <= 20000000 && "Compressed Size too large (should be <= 20000000)");
	this->compressionLevel = data.readByte();
	assert((this->uncompressedSize == 0 || this->compressionLevel < 11) && "Compression Level invalid (should pass UncompressedSize == 0 or CompressionLevel < 11)");
	this->windowBits = data.readByte();
	this->memoryLevel = data.readByte();
	assert((this->uncompressedSize == 0 || this->memoryLevel < 9) && "Memory Level invalid (should pass UncompressedSize == 0 or MemoryLevel < 9)");
	this->strategy = data.readByte();
	assert(this->strategy <= 6 && "Strategy too large (should be <= 6)");
}

void FFLiResourcePartsInfo::loadHeader(ByteReader data, std::shared_ptr<uint8_t[]> dataBuffer, uint8_t * compressedBuffer)
{
	if (this->uncompressedSize == 0) {
		this->partData->setUnused();
		return;
	}
	int oOffset = data.offset;
	data.seek(this->offset);
	if (this->strategy == 5) {
		data.readRaw(this->compressedSize, dataBuffer.get());
		this->bReader = this->partData->loadHeader(dataBuffer);
		data.seek(oOffset);
		return;
	}
	data.readRaw(this->compressedSize, compressedBuffer);
	ZlibImpl::decompress(compressedBuffer, dataBuffer.get(), WindowBitConverter::fFLiResourceWindowBitsToZlibWindowBits(this->windowBits), this->uncompressedSize);
	this->bReader = this->partData->loadHeader(dataBuffer);
	data.seek(oOffset);
}

void FFLiResourcePartsInfo::loadPart()
{
	if (this->partData->used) {
		this->partData->fromByteReader(this->bReader, this->uncompressedSize);
	}
}

void FFLiResourceHeader::fromByteReader(ByteReader data, FFLiResourceLoaderObjects objects)
{
	assert(data.readUTF8(4) == "FFRA" && "Magic Header invalid (should be FFRA)");
	assert(data.readUInt(4) == 458752 && "Version invalid (should be 0x00070000)");
	this->uncompressedBufferSize = data.readUInt(4);
	assert(this->uncompressedBufferSize >= 1024 && "Uncompressed Buffer Size too small (should be >=1024)");
	this->expandedBufferSize = data.readUInt(4);
	assert(this->expandedBufferSize >= 1 && "Expanded Buffer Size too small (should be >=1)");
	this->isExpand = data.readUInt(4) == 1;
}

void FFLiResourceTextureHeader::fromByteReader(ByteReader data, FFLiResourceLoaderObjects objects)
{
	for (int i = 0; i < 11; i++) {
		this->textureMaxSize[i] = data.readUInt(4);
		assert(this->textureMaxSize[i] < 20000000 && this->textureMaxSize[i] % 4 == 0 && "Texture Max Size invalid (should pass TextureMaxSize < 20000000 and (TextureMaxSize % 4) == 0)");
	}
	for (int i = 0; i < 3; i++) {
		objects.textureBeard[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 132; i++) {
		objects.textureCap[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 62; i++) {
		objects.textureEye[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 24; i++) {
		objects.textureEyebrow[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 12; i++) {
		objects.textureWrinkle[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 12; i++) {
		objects.textureMakeup[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 9; i++) {
		objects.textureGlasses[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 2; i++) {
		objects.textureMole[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 37; i++) {
		objects.textureMouth[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 6; i++) {
		objects.textureMustache[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 18; i++) {
		objects.textureNoseline[i]->fromByteReader(data, objects);
	}
}

void FFLiResourceShapeHeader::fromByteReader(ByteReader data, FFLiResourceLoaderObjects objects)
{
	for (int i = 0; i < 12; i++) {
		this->shapeMaxSize[i] = data.readUInt(4);
		assert(this->shapeMaxSize[i] < 20000000 && this->shapeMaxSize[i] % 2 == 0 && "Shape Max Size invalid (should pass ShapeMaxSize < 20000000 and (ShapeMaxSize % 2) == 0)");
	}
	for (int i = 0; i < 4; i++) {
		objects.shapeBeard[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 132; i++) {
		objects.shapeCapNormal[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 132; i++) {
		objects.shapeCapHat[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 12; i++) {
		objects.shapeFaceline[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 1; i++) {
		objects.shapeGlasses[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 12; i++) {
		objects.shapeMask[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 18; i++) {
		objects.shapeNoseline[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 18; i++) {
		objects.shapeNose[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 132; i++) {
		objects.shapeHairNormal[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 132; i++) {
		objects.shapeHairHat[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 132; i++) {
		objects.shapeForeheadNormal[i]->fromByteReader(data, objects);
	}
	for (int i = 0; i < 132; i++) {
		objects.shapeForeheadHat[i]->fromByteReader(data, objects);
	}
}

void FFLResource::fromByteReader(ByteReader data, FFLiResourceLoaderObjects objects)
{
	objects.resourceHeader->fromByteReader(data, objects);
	this->isAFL23 = objects.resourceHeader->expandedBufferSize == 38809056;
	this->isAFL = this->isAFL23 || objects.resourceHeader->expandedBufferSize == 37344736;
	objects.textureHeader->fromByteReader(data, objects);
	objects.shapeHeader->fromByteReader(data, objects);
	this->isLoaded = true;
}
