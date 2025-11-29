#include "ZLibImpl.hpp"
#include "decompressor.h"

#include "godot_cpp/variant/utility_functions.hpp"

#include <stdint.h>

// https://github.com/Artexety/inflatecpp

void CPPZlibImpl::decompress(uint8_t const * input, uint8_t * output, int windowBits, int compressedSize, int originalSize) const {
	Decompressor decompressor;

	uint32_t decompressedDataSize = decompressor.Feed(input, compressedSize, output, originalSize, true);

	if (decompressedDataSize == -1) {
		godot::UtilityFunctions::printerr(godot::String("GDFL: CPPZlibImpl: Decompression Failed!"));
	}
}