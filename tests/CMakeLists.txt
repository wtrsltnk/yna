
add_executable(yna.tests
    doctest-main.cpp
    doctest.h
    test-gamewindow.cpp
    test-property.cpp
    test-vector2.cpp
    test-vector3.cpp
    test-vector4.cpp
    test-quaternion.cpp
    )

target_include_directories(yna.tests
    PRIVATE ../src
    )

target_link_libraries(yna.tests
    yna.framework
    )

target_compile_features(yna.tests
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )

target_compile_definitions(yna.tests
    PRIVATE CATCH_CONFIG_FAST_COMPILE
    PRIVATE CATCH_CONFIG_CPP11_NULLPTR
    )
