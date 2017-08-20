#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

typedef struct
{
    HINSTANCE instance;
    HWND window;
    HDC deviceConext;
    HGLRC glRenderContext;

} WindowHandle;

typedef struct
{
    HDC deviceConext;
    HGLRC glRenderContext;

} ContextHandle;

#endif // _WIN32

#endif // PLATFORM_H
