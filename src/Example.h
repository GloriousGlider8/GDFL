#pragma once
// Copied from godot-cpp/test/src and modified.

#include "godot_cpp/classes/node3d.hpp"
#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/core/binder_common.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "ffl/include/nn/ffl.h"

class FFLMii : public godot::Object
{
    GDCLASS( FFLMii, godot::Object )

public:
    FFLMii();
    ~FFLMii() override;
    godot::PackedByteArray data;

protected:
    static void _bind_methods();

};

class FFLG2Mii : public FFLMii
{
    GDCLASS( FFLMii, FFLMii )

public:
    FFLG2Mii();
    ~FFLG2Mii() override;

protected:
    static void _bind_methods();
};

class FFLMiiHead : public godot::Node3D
{
    GDCLASS( FFLMiiHead, godot::Node3D )

public:

    FFLMiiHead();
    ~FFLMiiHead() override;

protected:
    static void _bind_methods();

    void _notification( int inWhat );
    bool _set( const godot::StringName &inName, const godot::Variant &inValue );
    bool _get( const godot::StringName &inName, godot::Variant &outReturn ) const;
    void _get_property_list( godot::List<godot::PropertyInfo> *outList ) const;
    bool _property_can_revert( const godot::StringName &inName ) const;
    bool _property_get_revert( const godot::StringName &inName, godot::Variant &outProperty ) const;
    void _validate_property( godot::PropertyInfo &inProperty ) const;

    godot::String _to_string() const;

private:
    godot::Vector2 mCustomPosition;
    godot::Vector3 mPropertyFromList;
    godot::Vector2 mDProp[3];

    int mLastRPCArg = 0;
};