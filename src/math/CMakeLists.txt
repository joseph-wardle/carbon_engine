add_library(math STATIC)

target_sources(math
    PUBLIC
        FILE_SET math_modules TYPE CXX_MODULES FILES
            algebra.cppm
            align.cppm
            comparison.cppm
            concepts.cppm
            constants.cppm
            vec2.cppm
)

target_sources(math
    PUBLIC
        algebra.cpp)


target_include_directories(math
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(math
    PRIVATE
        core
)