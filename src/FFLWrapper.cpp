/* This file does all the heavy lifting!
   A lot of code was "borrowed" from other sources:
   https://github.com/ariankordi/ffl-raylib-samples
   https://github.com/ariankordi/FFLSharp
*/

#include "FFLWrapper.h"
#include "nn/ffl.h"
#include "nn/ffl/detail/FFLiCharInfo.h"
#include "godot_cpp/variant/utility_functions.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

FFLResourceDesc gResourceDesc;

FFLResult FFLWrapperInit(std::string resHigh = "ignore", std::string resMiddle = "ignore") {
    gResourceDesc.size[FFL_RESOURCE_TYPE_HIGH] = 0;
    gResourceDesc.size[FFL_RESOURCE_TYPE_MIDDLE] = 0;

    // Resource High Loading
    if (resHigh != "ignore") {
        FILE* file = fopen(resHigh.c_str(), "rb");
        if (!file) {
            std::string errStr = "(FFLWrapper.cpp) [FFLWrapperInit] Cannot open file " + resHigh;
            godot::UtilityFunctions::printerr(godot::String(errStr.c_str()));
            return FFL_RESULT_FS_ERROR;
        }

        // read file
        fseek(file, 0, SEEK_END);
        unsigned long fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);
        if (fileSize <= 0) {
            std::string errStr = "(FFLWrapper.cpp) [FFLWrapperInit] Invalid file size for " + resHigh;
            godot::UtilityFunctions::printerr(godot::String(errStr.c_str()));
            return FFL_RESULT_FS_ERROR;
        }
        void* fileData = malloc((size_t)fileSize);
        size_t bytesRead = fread(fileData, 1, (size_t)fileSize, file);
        if (bytesRead == fileSize) {
            gResourceDesc.pData[FFL_RESOURCE_TYPE_HIGH] = fileData;
            gResourceDesc.size[FFL_RESOURCE_TYPE_HIGH] = (size_t)fileSize;
        } else {
            std::string errStr = "(FFLWrapper.cpp) [FFLWrapperInit] Cannot read file " + resHigh;
            godot::UtilityFunctions::printerr(godot::String(errStr.c_str()));
            return FFL_RESULT_FS_ERROR;
        }
        fclose(file);
    };

    if (resMiddle != "ignore") {
        FILE* file = fopen(resMiddle.c_str(), "rb");
        if (!file) {
            std::string errStr = "(FFLWrapper.cpp) [FFLWrapperInit] Cannot open file " + resMiddle;
            godot::UtilityFunctions::printerr(godot::String(errStr.c_str()));
            return FFL_RESULT_FS_ERROR;
        }

        // read file
        fseek(file, 0, SEEK_END);
        unsigned long fileSize = ftell(file);
        fseek(file, 0, SEEK_SET);
        if (fileSize <= 0) {
            std::string errStr = "(FFLWrapper.cpp) [FFLWrapperInit] Invalid file size for " + resMiddle;
            godot::UtilityFunctions::printerr(godot::String(errStr.c_str()));
            return FFL_RESULT_FS_ERROR;
        }
        void* fileData = malloc((size_t)fileSize);
        size_t bytesRead = fread(fileData, 1, (size_t)fileSize, file);
        if (bytesRead == fileSize) {
            gResourceDesc.pData[FFL_RESOURCE_TYPE_MIDDLE] = fileData;
            gResourceDesc.size[FFL_RESOURCE_TYPE_MIDDLE] = (size_t)fileSize;
        } else {
            std::string errStr = "(FFLWrapper.cpp) [FFLWrapperInit] Cannot read file " + resMiddle;
            godot::UtilityFunctions::printerr(godot::String(errStr.c_str()));
            return FFL_RESULT_FS_ERROR;
        }
        fclose(file);
    };

    FFLResult result;
    result = FFLInitRes(FFL_FONT_REGION_JP_US_EU, &gResourceDesc);

    if (result != FFL_RESULT_OK) {
        godot::UtilityFunctions::printerr("(FFLWrapper.cpp) [FFLWrapperInit] result != FFL_RESULT_OK");
        return result;
    }

    if (!FFLIsAvailable()) {
        godot::UtilityFunctions::printerr("(FFLWrapper.cpp) [FFLWrapperInit] FFL is not available");
        return result;
    }

    FFLInitResGPUStep();

    godot::UtilityFunctions::print("(FFLWrapper.cpp) [FFLWrapperInit] Exiting FFLWrapperInit");

    return result;
};

FFLResult FFLWrapperCharModel(FFLCharModel* pCharModel, const void* pStoreDataBuffer, const u32 expressionFlag = (1 << FFL_EXPRESSION_NORMAL | 1 << FFL_EXPRESSION_BLINK), FFLResourceType resType = FFL_RESOURCE_TYPE_HIGH, FFLModelFlag mdlType = FFL_MODEL_FLAG_NORMAL) {
    FFLCharModelSource modelSource;
    modelSource.dataSource = FFL_DATA_SOURCE_STORE_DATA;
    modelSource.pBuffer = pStoreDataBuffer;
    modelSource.index = 0;

    FFLCharModelDesc modelDesc;
    modelDesc.resolution = (FFLResolution)512;
    modelDesc.expressionFlag = expressionFlag;
    modelDesc.modelFlag = mdlType;
    modelDesc.resourceType = resType;

    FFLResult result;

    result = FFLInitCharModelCPUStep(pCharModel, &modelSource, &modelDesc);

    if (result != FFL_RESULT_OK) {
        godot::UtilityFunctions::printerr("(FFLWrapper.cpp) [FFLWrapperCharModel] result != FFL_RESULT_OK");
        return result;
    }
    godot::UtilityFunctions::printerr("NOT IMPLEMENTED!");
    return FFL_RESULT_OK;
};