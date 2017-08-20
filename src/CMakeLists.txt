
add_subdirectory(content)
add_subdirectory(graphics)

find_package(OpenGL REQUIRED)

add_library(yna.framework
    game.cpp
    game.h
    gamecomponent.cpp
    gamecomponent.h
    gamecomponentcollection.cpp
    gamecomponentcollection.h
    gameplatform.cpp
    gameplatform.h
    gameservicecontainer.cpp
    gameservicecontainer.h
    gametime.cpp
    gametime.h
    gamewindow.cpp
    gamewindow.h
    graphicsdevicemanager.cpp
    graphicsdevicemanager.h
    platform.h
    property.h
    )

if (WIN32)
    target_sources(yna.framework
        PRIVATE gameplatform.win32.cpp
        )
endif (WIN32)

#target_include_directories(yna.framework
#    PRIVATE ../libs/glfw/include
#    )

target_link_libraries(yna.framework
    ${OPENGL_LIBRARIES}
#    glfw
    )

target_compile_features(yna.framework
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )
