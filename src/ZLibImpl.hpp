#pragma once

#include "decompressor.h"
#include "FFLResource.hpp"

class CPPZlibImpl : miifu::ZlibImpl {
	// We have to use int rather than uint_32t here because unsigned data types are just a suggestion in fusion :)
	// but i suppose it is for the better, that way, we get javascript support
	
	void decompress(uint8_t const * input, uint8_t * output, int windowBits, int compressedSize, int originalSize) const override;
	void compress(uint8_t const * input, uint8_t * output, int level, int windowBits) const override;
};