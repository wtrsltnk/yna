#include "gameplatform.h"
#include "game.h"
#include "gamewindow.h"
#include "platform.h"

#include <iostream>

using namespace yna::framework;

class Win32Window : public GameWindow
{
    Game* _game;

public:
    Win32Window(Game* game);

    void HandleEvents();
    void Show();
    bool IsOpen();

    LRESULT WindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
    static LRESULT StaticProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

LRESULT Win32Window::StaticProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Win32Window* window = nullptr;

    if (uMsg == WM_NCCREATE)
    {
        window = reinterpret_cast <Win32Window*> (((LPCREATESTRUCT)lParam)->lpCreateParams);

        SetWindowLong(hWnd, GWLP_USERDATA, reinterpret_cast <long long> (window));

        if (window != nullptr)
        {
            window->_handle.window = hWnd;
        }
    }
    else
    {
        window = reinterpret_cast <Win32Window*> (GetWindowLong(hWnd, GWLP_USERDATA));
    }

    if (window != nullptr)
    {
        return window->WindowProc(uMsg, wParam, lParam);
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LRESULT InitWindowClass(const WindowHandle& handle, const char* className)
{
    WNDCLASSEX wcex;

    if (GetClassInfoEx(handle.instance, className, &wcex))
    {
        return TRUE;
    }

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = (WNDPROC)Win32Window::StaticProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.lpszMenuName = NULL;
    wcex.hIconSm = NULL;

    wcex.hInstance = handle.instance;
    wcex.hIcon = NULL;
    wcex.hbrBackground = ((HBRUSH)(COLOR_WINDOW) + 0);
    wcex.lpszClassName = className;
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);

    if (!RegisterClassEx(&wcex))
    {
        return FALSE;
    }

    return TRUE;
}

bool InitPixelFormat(HDC hDC)
{
    PIXELFORMATDESCRIPTOR pfd;

    ZeroMemory( &pfd, sizeof( pfd ) );
    pfd.nSize = sizeof( pfd );
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    auto pixelFormat = ChoosePixelFormat(hDC, &pfd);
    if (pixelFormat == 0)
    {
        std::cerr << "Error: " << GetLastError() << "\n";
        return false;
    }

    if (SetPixelFormat(hDC, pixelFormat, &pfd) == FALSE)
    {
        std::cerr << "Error: " << GetLastError() << "\n";
        return false;
    }

    return true;
}

Win32Window::Win32Window(Game* game)
    : _game(game)
{
    _handle.instance = GetModuleHandle(NULL);

    if (InitWindowClass(_handle, "YNAWin32Window"))
    {
        _handle.window =
                CreateWindowEx(WS_EX_WINDOWEDGE, "YNAWin32Window", "YNA", WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                               NULL, NULL, _handle.instance, (VOID*)this);
    }
}

void Win32Window::Show()
{
    if (_handle.window != NULL)
    {
        ShowWindow(_handle.window, SW_SHOW);
    }
}

void Win32Window::HandleEvents()
{
    MSG msg;

    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

LRESULT Win32Window::WindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
    {
        _handle.deviceConext = GetWindowDC(_handle.window);

        if (!_handle.deviceConext)
        {
            std::cerr << "Unable to get Window Device Context\n";
            break;
        }

        if (!InitPixelFormat(_handle.deviceConext))
        {
            std::cerr << "Unable to initialize pixel format\n";
            break;
        }

        _handle.glRenderContext = wglCreateContext(_handle.deviceConext);

        if (!_handle.glRenderContext)
        {
            std::cerr << "Unable to create Render Context\n";
            break;
        }

        wglMakeCurrent(_handle.deviceConext, _handle.glRenderContext);
        break;
    }
    case WM_SIZE:
    {
        _clientSizeWidth = LOWORD(lParam);
        _clientSizeHeight = HIWORD(lParam);
        OnClientSizeChanged();
        break;
    }
    }

    return DefWindowProc(_handle.window, uMsg, wParam, lParam);
}

bool Win32Window::IsOpen()
{
    return IsWindow(_handle.window);
}

class Win32Platform : public GamePlatform
{
    Game* _game;
    bool _isRunning;
public:
    Win32Platform(Game* game);

    virtual bool BeforeDraw();
    virtual void AfterDraw();
    virtual void RunLoop();
    virtual void Exit();
};

Win32Platform::Win32Platform(Game* game)
    : _game(game), _isRunning(false)
{
    Window = new Win32Window(game);
}

bool Win32Platform::BeforeDraw()
{
    auto handle = ((Win32Window*)Window.get())->Handle.get();

    return wglMakeCurrent(handle.deviceConext, handle.glRenderContext);
}

void Win32Platform::AfterDraw()
{
    auto handle = ((Win32Window*)Window.get())->Handle.get();

    SwapBuffers(handle.deviceConext);
}

void Win32Platform::RunLoop()
{
    _isRunning = true;

    auto wnd = (Win32Window*)Window.get();

    wnd->Show();

    while (this->_isRunning && wnd->IsOpen())
    {
        wnd->HandleEvents();

        _game->Tick();
    }
}

void Win32Platform::Exit()
{
    this->_isRunning = false;
}

GamePlatform* GamePlatform::PlatformCreate(Game* game)
{
    static Win32Platform instance(game);

    return &instance;
}
