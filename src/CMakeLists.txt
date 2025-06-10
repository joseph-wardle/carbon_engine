set(PRJ_APP_NAME "carbon_engine")


add_subdirectory(core)
add_subdirectory(math)

add_executable(${PRJ_APP_NAME})
target_compile_features(${PRJ_APP_NAME} PRIVATE cxx_std_23)


target_sources(${PRJ_APP_NAME}
    PRIVATE
        main.cpp
)


target_link_libraries(${PRJ_APP_NAME}
    PRIVATE
        core
        math
)