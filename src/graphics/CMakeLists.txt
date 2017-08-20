
add_library(yna.framework.graphics
    graphicsdevice.cpp
    graphicsdevice.h
    graphicscontext.cpp
    graphicscontext.h
    )

target_compile_features(yna.framework.graphics
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )
