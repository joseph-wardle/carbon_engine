add_library(core STATIC)

target_sources(core
    PUBLIC
        FILE_SET core_modules TYPE CXX_MODULES FILES
            types.cppm
            string.cppm
    PRIVATE
        string.cpp
)

target_include_directories(core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)