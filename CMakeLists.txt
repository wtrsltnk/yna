cmake_minimum_required(VERSION 3.7)

include(cmake/get_cpm.cmake)

project(yna)

option(YNA_BUILD_EXAMPLES "Build the YNA example programs" ON)
option(YNA_BUILD_TESTS "Build the YNA test programs" ON)

find_package(OpenGL REQUIRED)

add_library(yna.framework
    include/boundingbox.h
    include/boundingfrustum.h
    include/boundingsphere.h
    include/color.h
    include/containmenttype.h
    include/content/contentmanager.h
    include/content/contentreader.h
    include/content/contenttypereader.h
    include/content/contenttypereadermanager.h
    include/game.h
    include/gamecomponent.h
    include/gamecomponentcollection.h
    include/gameservicecontainer.h
    include/gametime.h
    include/gamewindow.h
    include/graphics/bufferusage.h
    include/graphics/clearoptions.h
    include/graphics/effect.h
    include/graphics/graphicsdevice.h
    include/graphics/graphicsresource.h
    include/graphics/igraphicsdeviceservice.h
    include/graphics/model.h
    include/graphics/spritefont.h
    include/graphics/texture.h
    include/graphics/texture2D.h
    include/graphics/vertexbuffer.h
    include/graphics/vertexdeclaration.h
    include/graphics/vertexelement.h
    include/graphicsdevicemanager.h
    include/matrix.h
    include/plane.h
    include/planeintersectiontype.h
    include/planeintersectiontype.h
    include/platform.h
    include/point.h
    include/property.h
    include/quaternion.h
    include/rectangle.h
    include/stream.h
    include/type.h
    include/vector2.h
    include/vector3.h
    include/vector4.h
    src/boundingbox.cpp
    src/boundingfrustum.cpp
    src/boundingsphere.cpp
    src/color.cpp
    src/content/contentmanager.cpp
    src/content/contentreader.cpp
    src/content/contenttypereader.cpp
    src/content/contenttypereadermanager.cpp
    src/content/texture2dreader.cpp
    src/content/texture2dreader.h
    src/game.cpp
    src/gamecomponent.cpp
    src/gamecomponentcollection.cpp
    src/gameplatform.cpp
    src/gameplatform.h
    src/gameservicecontainer.cpp
    src/gametime.cpp
    src/gamewindow.cpp
    src/graphics/effect.cpp
    src/graphics/glad.c
    src/graphics/graphicsdevice.cpp
    src/graphics/graphicsresource.cpp
    src/graphics/model.cpp
    src/graphics/spritefont.cpp
    src/graphics/texture.cpp
    src/graphics/texture2D.cpp
    src/graphics/vertexbuffer.cpp
    src/graphics/vertexdeclaration.cpp
    src/graphics/vertexelement.cpp
    src/graphicsdevicemanager.cpp
    src/matrix.cpp
    src/plane.cpp
    src/point.cpp
    src/quaternion.cpp
    src/rectangle.cpp
    src/vector2.cpp
    src/vector3.cpp
    src/vector4.cpp
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
