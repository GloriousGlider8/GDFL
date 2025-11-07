target_sources(${PROJECT_NAME}
    PRIVATE
        adler32.cc
        adler32.h
        bit_reader.cc
        bit_reader.h
        crc32.cc
        crc32.h
        decompressor.cc
        decompressor.h
        huffman_decoder.cc
        huffman_decoder.h
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}"
)
