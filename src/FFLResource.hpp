// Generated automatically with "fut". Do not edit.
#pragma once
#include <array>
#include <cmath>
#include <cstdint>
#include <memory>
#include <string>
class BitConverter;
class BitfieldReader;
class ByteReader;
class ZlibImpl;

enum class FFLiTextureFormat
{
	greyscale = 0,
	greyscaleAlpha = 1,
	rGBA = 2
};

/**
 * The index that each shape element is stored at.
 * Exmaple: <code>data[FFLiResourceShapeElementType.Position.ToInt()]</code> would get vertex position data.
 */
enum class FFLiResourceShapeElementType
{
	position = 0,
	normal = 1,
	texcoord = 2,
	tangent = 3,
	color = 4,
	index = 5,
	transformHair = 6,
	transformFaceline = 7,
	boundingBox = 8
};
class Vec3;
class BoundingBox;
class WindowBitConverter;
class FFLiResourceLoaderObjects;
class FFLiPartData;
class FFLiPartDataHeader;
class FFLiPartDataFooter;
class FFLiResourcePartsInfo;
class FFLiResourceHeader;
class FFLiResourceTextureHeader;
class FFLiResourceShapeHeader;
class FFLResource;

class BitConverter
{
public:
	/**
	 * Converts packed 10_10_10_2 SNORM (signed normalized) to float[3]
	 */
	static void convert1010102ToFloat(int packed, float * outVec, int offset);
	/**
	 * Converts packed 8_8_8_8 SNORM (signed normalized) to float[4]
	 */
	static void convert8888SnormToFloat(int packed, float * outVec);
	/**
	 * Converts 16-bit half-float to 32-bit float (IEEE754)
	 */
	static float halfToFloat(int half);
	/**
	 * Convert 32-bit unsigned integer to floating point.
	 * As of 3.2.10, Fusion does not include any method to
	 * convert bits to float, so native implementations are provided
	 * along with a generic slow and terrible but functional fallback.
	 */
	static float uIntToFloat(int bits);
	static int floatToInt(float v);
private:
	BitConverter() = delete;
};

/**
 * Convenience class to read values from bitfields
 */
class BitfieldReader
{
public:
	BitfieldReader() = default;
	int value;
	/**
	 * Move the bit pointer to <code>where</code> bits
	 */
	void seek(int where);
	/**
	 * Move the bit pointer ahead by <code>size</code> bit
	 * This is prefered in place of <code>Seek</code>
	 */
	void padding(int size);
	/**
	 * Reads 1 bit and returns it as a <code>bool</code>
	 */
	bool readBool();
	/**
	 * Reads <code>size</code> bits into a <code>byte</code>
	 */
	int readBits(int size);
private:
	int offset;
};

/**
 * Convenience class to read values from bytes.
 * All methods assume big-endian byte order.
 */
class ByteReader
{
public:
	ByteReader() = default;
	std::shared_ptr<uint8_t[]> data;
	/**
	 * Move the file pointer to <code>where</code> bytes.
	 */
	void seek(int where);
	/**
	 * Move the file pointer ahead by <code>size</code> bytes.
	 * This is prefered in place of <code>Seek</code>.
	 */
	void padding(int size);
	/**
	 * Reads 1 byte into a <code>byte</code>.
	 * Range: <code>0 .. 255</code>.
	 */
	int readByte();
	/**
	 * Reads <code>size</code> bytes and stores them in a <code>ushort</code>.
	 * Range: <code>0 .. 65535</code>.
	 */
	int readUShort(int size);
	/**
	 * Reads <code>size</code> bytes and stores them in a <code>uint</code>.
	 * Range: <code>0 .. 2147483647</code>.
	 */
	int readUInt(int size);
	/**
	 * Reads <code>size</code> bytes and stores them in a <code>short</code>.
	 * Range: <code>-32768 .. 32767</code>.
	 */
	int readSShort(int size);
	/**
	 * Reads <code>size</code> bytes and stores them in an <code>int</code>.
	 * Range: <code>-2147483648 .. 2147483647</code>.
	 */
	int readSInt(int size);
	/**
	 * Reads <code>size</code> bytes and stores them in a <code>long</code>.
	 * Range <code>-9223372036854775808 .. 9223372036854775807</code>.
	 */
	int64_t readSLong(int size);
	/**
	 * Reads 1 byte into a <code>BitfieldReader</code>.
	 * This serves as a convenience method and still advances the pointer.
	 */
	BitfieldReader getBitfield();
	/**
	 * Reads 4 bytes and stores them in a <code>float</code>.
	 * Uses the IEEE 754 format.
	 */
	float readFloat();
	/**
	 * Reads <code>size</code> bytes and interprets them as a UTF8 string.
	 */
	std::string readUTF8(int size);
	/**
	 * Reads <code>size</code> bytes and stores them in <code>buffer</code>.
	 */
	void readRaw(int size, uint8_t * buffer);
private: // internal
	int offset = 0;
	friend FFLiResourcePartsInfo;
};

/**
 * ZLib compression implementation.
 * Must be overrided using a library for your target language!
 */
class ZlibImpl
{
public:
	/**
	 * Write the decompressed contents of <code>input</code> into <code>output</code>.
	 * <code>windowBits</code> and <code>originalSize</code> must also be specified.
	 */
	static void decompress(uint8_t const * input, uint8_t const * output, int windowBits, int originalSize);
	/**
	 * Write the Compressed contents of <code>input</code> into <code>output</code>.
	 * <code>level</code> and <code>windowBits</code> must also be specified.
	 */
	static void compress(uint8_t const * input, uint8_t const * output, int level, int windowBits);
private:
	ZlibImpl() = delete;
};

class Vec3
{
public:
	Vec3() = default;
	float x = NAN;
	float y = NAN;
	float z = NAN;
	/**
	 * Reads 3 IEEE 754 4-byte floats into <code>x</code>, <code>y</code> and <code>z</code> respectively.
	 */
	void fromByteReader(ByteReader data);
	/**
	 * Convenience function to set <code>x</code>, <code>y</code> and <code>z</code> to <code>Math.NaN</code>.
	 */
	void setNaN();
};

/**
 * Represents the minimum and maximum values of vertex positions in shapes.
 */
class BoundingBox
{
public:
	BoundingBox() = default;
	Vec3 min;
	Vec3 max;
	/**
	 * Reads 2 <code>Vec3</code>s into <code>min</code> and <code>max</code> respectively.
	 */
	void fromByteReader(ByteReader data);
	/**
	 * Convenience function to set the <code>x</code>, <code>y</code> and <code>z</code> values of <code>min</code> and <code>max</code> to <code>Math.NaN</code>.
	 */
	void setNaN();
};

/**
 * Convenience class containing 1 function to convert <code>FFLiResourcePartsInfo.WindowBits</code> to ZLib <code>windowBits</code>.
 */
class WindowBitConverter
{
public:
	/**
	 * Converts <code>FFLiResourcePartsInfo.WindowBits</code> to ZLib <code>windowBits</code>.
	 */
	static int fFLiResourceWindowBitsToZlibWindowBits(int windowBits);
private:
	WindowBitConverter() = delete;
};

/**
 * Passed to <code>FFLResource.FromByteReader</code> to provide more options for memory-management.
 */
class FFLiResourceLoaderObjects
{
public:
	FFLiResourceLoaderObjects() = default;
	FFLiResourceHeader * resourceHeader;
	FFLiResourceTextureHeader * textureHeader;
	FFLiResourceShapeHeader * shapeHeader;
	std::array<FFLiResourcePartsInfo *, 3> textureBeard;
	std::array<FFLiResourcePartsInfo *, 132> textureCap;
	std::array<FFLiResourcePartsInfo *, 62> textureEye;
	std::array<FFLiResourcePartsInfo *, 24> textureEyebrow;
	std::array<FFLiResourcePartsInfo *, 12> textureWrinkle;
	std::array<FFLiResourcePartsInfo *, 12> textureMakeup;
	std::array<FFLiResourcePartsInfo *, 9> textureGlasses;
	std::array<FFLiResourcePartsInfo *, 2> textureMole;
	std::array<FFLiResourcePartsInfo *, 37> textureMouth;
	std::array<FFLiResourcePartsInfo *, 6> textureMustache;
	std::array<FFLiResourcePartsInfo *, 18> textureNoseline;
	std::array<FFLiResourcePartsInfo *, 4> shapeBeard;
	std::array<FFLiResourcePartsInfo *, 132> shapeCapNormal;
	std::array<FFLiResourcePartsInfo *, 132> shapeCapHat;
	std::array<FFLiResourcePartsInfo *, 12> shapeFaceline;
	std::array<FFLiResourcePartsInfo *, 1> shapeGlasses;
	std::array<FFLiResourcePartsInfo *, 12> shapeMask;
	std::array<FFLiResourcePartsInfo *, 18> shapeNoseline;
	std::array<FFLiResourcePartsInfo *, 18> shapeNose;
	std::array<FFLiResourcePartsInfo *, 132> shapeHairNormal;
	std::array<FFLiResourcePartsInfo *, 132> shapeHairHat;
	std::array<FFLiResourcePartsInfo *, 132> shapeForeheadNormal;
	std::array<FFLiResourcePartsInfo *, 132> shapeForeheadHat;
};

class FFLiPartData
{
public:
	FFLiPartData() = default;
	bool used = false;
	FFLiPartDataHeader * header;
	FFLiPartDataFooter * footer;
	std::unique_ptr<std::array<uint8_t, 6>[]> data;
	void fromByteReader(ByteReader bUtils, int size);
	ByteReader loadHeader(std::shared_ptr<uint8_t[]> data);
	void setUnused();
};

class FFLiPartDataHeader
{
public:
	FFLiPartDataHeader() = default;
	std::array<int, 6> elementOffset;
	std::array<int, 6> elementSize;
	BoundingBox boundingBox;
	std::array<Vec3, 6> transform;
	void fromByteReader(ByteReader bUtils);
	void setUnused();
};

class FFLiPartDataFooter
{
public:
	FFLiPartDataFooter() = default;
	int mipOffset;
	int width;
	int height;
	FFLiTextureFormat format;
	int mipCount;
	void fromByteReader(ByteReader data);
};

class FFLiResourcePartsInfo
{
public:
	FFLiResourcePartsInfo() = default;
	int offset;
	int uncompressedSize;
	int compressedSize;
	int compressionLevel;
	int windowBits;
	int memoryLevel;
	int strategy;
	FFLiPartData * partData;
	void fromByteReader(ByteReader data, FFLiResourceLoaderObjects objects);
	void loadHeader(ByteReader data, std::shared_ptr<uint8_t[]> dataBuffer, uint8_t * compressedBuffer);
	void loadPart();
private:
	ByteReader bReader;
};

class FFLiResourceHeader
{
public:
	FFLiResourceHeader() = default;
	int uncompressedBufferSize;
	int expandedBufferSize;
	bool isExpand;
	void fromByteReader(ByteReader data, FFLiResourceLoaderObjects objects);
};

class FFLiResourceTextureHeader
{
public:
	FFLiResourceTextureHeader() = default;
	std::array<int, 11> textureMaxSize;
	void fromByteReader(ByteReader data, FFLiResourceLoaderObjects objects);
};

class FFLiResourceShapeHeader
{
public:
	FFLiResourceShapeHeader() = default;
	std::array<int, 12> shapeMaxSize;
	void fromByteReader(ByteReader data, FFLiResourceLoaderObjects objects);
};

/**
 * ## FFLResource
 * <code>FFLResource</code> is used for the loading of FFL / AFL Resource files.
 * ### Loading a Resource
 * Use <code>FFLResource.FromByteReader</code> to load a resource from a <code>ByteReader</code>, storing objects in a <code>FFLiResourceLoaderObjects</code> object.
 */
class FFLResource
{
public:
	FFLResource() = default;
	/**
	 * Contains <code>true</code> if the resource has been loaded successfully.
	 */
	bool isLoaded = false;
	/**
	 * Contains <code>true</code> if the resource has been detected as <code>AFLResHigh_2_3.dat</code>.
	 * (<code>objects.ResourceHeader.ExpandedBufferSize == 0x2502DE0</code>)
	 */
	bool isAFL23 = false;
	/**
	 * Contains <code>true</code> if the resource has been detected as an <code>AFLRes*.dat</code> file.
	 * (<code>IsAFL23 || objects.ResourceHeader.ExpandedBufferSize == 0x239D5E0</code>)
	 */
	bool isAFL = false;
	/**
	 * Loads a resource from a <code>ByteReader</code>, storing objects in a <code>FFLiResourceLoaderObjects</code> object.
	 */
	void fromByteReader(ByteReader data, FFLiResourceLoaderObjects objects);
};
