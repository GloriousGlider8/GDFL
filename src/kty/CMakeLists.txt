target_sources( ${PROJECT_NAME}
    PRIVATE
        g1.cpp
        g1.h
        g2.cpp
        g2.h
        g3.cpp
        g3.h
        g4.cpp
        g4.h
)

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        "src/kty"
)
