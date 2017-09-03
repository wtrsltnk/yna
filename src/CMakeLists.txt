
find_package(OpenGL REQUIRED)

add_library(yna.framework
    boundingbox.cpp
    boundingbox.h
    boundingfrustum.cpp
    boundingfrustum.h
    boundingsphere.cpp
    boundingsphere.h
    color.cpp
    color.h
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
    matrix.cpp
    matrix.h
    plane.cpp
    plane.h
    platform.h
    point.cpp
    point.h
    property.h
    quaternion.cpp
    quaternion.h
    rectangle.cpp
    rectangle.h
    vector2.cpp
    vector2.h
    vector3.cpp
    vector3.h
    vector4.cpp
    vector4.h
    containmenttype.h
    planeintersectiontype.h
    content/contentmanager.cpp
    content/contentmanager.h
    content/contentreader.cpp
    content/contentreader.h
    content/pipline/graphics/texturecontent.cpp
    content/pipline/graphics/texturecontent.h
    content/pipline/textureimporter.cpp
    content/pipline/textureimporter.h
    content/pipline/contentitem.cpp
    content/pipline/contentitem.h
    graphics/effect.cpp
    graphics/effect.h
    graphics/igraphicsdeviceservice.h
    graphics/graphicsdevice.cpp
    graphics/graphicsdevice.h
    graphics/graphicsresource.cpp
    graphics/graphicsresource.h
    graphics/model.cpp
    graphics/model.h
    graphics/spritefont.cpp
    graphics/spritefont.h
    graphics/texture.cpp
    graphics/texture.h
    graphics/texture2D.cpp
    graphics/texture2D.h
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
