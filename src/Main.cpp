// Copied from godot-cpp/test/src and modified.

#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

#include "Main.h"

// Used to mark unused parameters to indicate intent and suppress warnings.
#define UNUSED( expr ) (void)( expr )

// GDFLMii base class
void GDFLMii::load_data(godot::PackedByteArray data) {
    godot::UtilityFunctions::push_warning(godot::String("Base GDFLMii cannot use load_data!"));
}

void GDFLMii::_bind_methods() {
    return;
};