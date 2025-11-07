target_sources(${PROJECT_NAME}
    PRIVATE
        All.hpp
        RegisterExtension.cpp
        Mii.cpp
        Mii.hpp
        MiiResource.hpp
        MiiResource.cpp
        Convert.hpp
        Convert.cpp
        CommonDefs.hpp
)

add_subdirectory(inflatecpp)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)
