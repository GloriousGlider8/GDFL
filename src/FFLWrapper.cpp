/* This file does all the heavy lifting!
   A lot of code was "borrowed" from other sources:
   https://github.com/ariankordi/ffl-raylib-samples
   https://github.com/ariankordi/FFLSharp
*/

#include "FFLWrapper.h"
#include "GDClassSTLConv.h"
#include "nn/ffl.h"
#include "godot_cpp/variant/utility_functions.hpp"
#include "godot_cpp/classes/global_constants.hpp"

#include <cstring>

FFLResourceDesc gResourceDesc;

FFLResult FFLWrapperInit(godot::PackedByteArray resHigh, godot::PackedByteArray resMiddle) {
    gResourceDesc.size[FFL_RESOURCE_TYPE_HIGH] = (size_t)resHigh.size();
    gResourceDesc.size[FFL_RESOURCE_TYPE_MIDDLE] = (size_t)resMiddle.size();

    FFLResult result = FFLInitRes(FFL_FONT_REGION_JP_US_EU, &gResourceDesc);

    if (result != FFL_RESULT_OK) {
        godot::UtilityFunctions::printerr(godot::String("FFLWrapperInit failed at FFLInitRes step (result "), (int)result, godot::String(")"));
        return result;
    };
};