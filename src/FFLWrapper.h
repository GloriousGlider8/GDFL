#include <string>

#include "nn/ffl.h"
#include "nn/ffl/detail/FFLiCharInfo.h"
#include "godot_cpp/variant/utility_functions.hpp"

FFLResourceDesc gResourceDesc;

FFLResult FFLWrapperInit(std::string resHigh, std::string resMiddle);
FFLResult FFLWrapperCharModel(FFLCharModel* pCharModel, const void* pStoreDataBuffer);