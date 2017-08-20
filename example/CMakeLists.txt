
add_executable(yna.example
    program.cpp
    )

target_include_directories(yna.example
    PRIVATE ../src
    )

target_link_libraries(yna.example
    yna.framework
    )

target_compile_features(yna.example
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )
