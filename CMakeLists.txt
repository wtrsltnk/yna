cmake_minimum_required(VERSION 3.7)

project(yna)

option(YNA_BUILD_EXAMPLES "Build the YNA example programs" ON)
option(YNA_BUILD_TESTS "Build the YNA test programs" ON)

find_package(OpenGL REQUIRED)

add_library(yna.framework
    src/boundingbox.cpp
    include/boundingbox.h
    src/boundingfrustum.cpp
    include/boundingfrustum.h
    src/boundingsphere.cpp
    include/boundingsphere.h
    src/color.cpp
    include/color.h
    src/game.cpp
    include/game.h
    src/gamecomponent.cpp
    include/gamecomponent.h
    src/gamecomponentcollection.cpp
    include/gamecomponentcollection.h
    src/gameplatform.cpp
    src/gameplatform.h
    src/gameservicecontainer.cpp
    include/gameservicecontainer.h
    src/gametime.cpp
    include/gametime.h
    src/gamewindow.cpp
    include/gamewindow.h
    src/graphicsdevicemanager.cpp
    include/graphicsdevicemanager.h
    include/graphics/clearoptions.h
    src/matrix.cpp
    include/matrix.h
    src/plane.cpp
    include/plane.h
    include/planeintersectiontype.h
    include/platform.h
    src/point.cpp
    include/point.h
    include/property.h
    include/type.h
    include/stream.h
    src/quaternion.cpp
    include/quaternion.h
    src/rectangle.cpp
    include/rectangle.h
    src/vector2.cpp
    include/vector2.h
    src/vector3.cpp
    include/vector3.h
    src/vector4.cpp
    include/vector4.h
    include/containmenttype.h
    include/planeintersectiontype.h
    src/content/contentmanager.cpp
    include/content/contentmanager.h
    src/content/contentreader.cpp
    include/content/contentreader.h
    src/content/texture2dreader.cpp
    src/content/texture2dreader.h
    src/content/contenttypereadermanager.cpp
    include/content/contenttypereadermanager.h
    src/content/contenttypereader.cpp
    include/content/contenttypereader.h
    include/graphics/bufferusage.h
    src/graphics/effect.cpp
    include/graphics/effect.h
    include/graphics/igraphicsdeviceservice.h
    src/graphics/graphicsdevice.cpp
    include/graphics/graphicsdevice.h
    src/graphics/graphicsresource.cpp
    include/graphics/graphicsresource.h
    src/graphics/model.cpp
    include/graphics/model.h
    src/graphics/spritefont.cpp
    include/graphics/spritefont.h
    src/graphics/texture.cpp
    include/graphics/texture.h
    src/graphics/texture2D.cpp
    include/graphics/texture2D.h
    src/graphics/vertexbuffer.cpp
    include/graphics/vertexbuffer.h
    src/graphics/vertexdeclaration.cpp
    include/graphics/vertexdeclaration.h
    src/graphics/vertexelement.cpp
    include/graphics/vertexelement.h
    src/graphics/glextl.cpp
    )

if (WIN32)
    target_sources(yna.framework
        PRIVATE src/gameplatform.win32.cpp
        )
endif (WIN32)

target_include_directories(yna.framework
    PUBLIC include
    )

target_link_libraries(yna.framework
    ${OPENGL_LIBRARIES}
#    glfw
    )

target_compile_features(yna.framework
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )

if (YNA_BUILD_EXAMPLES)
    add_subdirectory(example)
endif (YNA_BUILD_EXAMPLES)

if (YNA_BUILD_TESTS)
    add_subdirectory(tests)
endif (YNA_BUILD_TESTS)
