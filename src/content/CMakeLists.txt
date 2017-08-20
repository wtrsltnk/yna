
add_library(yna.framework.content
    contentmanager.cpp
    contentmanager.h
    )

target_compile_features(yna.framework.content
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )
