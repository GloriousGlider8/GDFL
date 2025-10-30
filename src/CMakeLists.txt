# SPDX-License-Identifier: Unlicense

target_sources( ${PROJECT_NAME}
    PRIVATE
        Main.h
        Main.cpp
        GDExtensionTemplate.h
        GDExtensionTemplate.cpp
        RegisterExtension.cpp
        FFLWrapper.cpp
        FFLWrapper.h
        GDClassSTLConv.h
        Types.h
        PantsColor.h
        DataUtils.cpp
)

add_subdirectory(kty)

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        "src"
)
