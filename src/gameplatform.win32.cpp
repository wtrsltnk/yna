#include "gameplatform.h"
#include "game.h"
#include "gamewindow.h"
#include "graphics/graphicsdevice.h"
#include "platform.h"

#include <iostream>
#include <GL/gl.h>

using namespace yna::framework;

class Win32OpenGLGraphicsDevice : public graphics::GraphicsDevice
{
    WindowHandle _handle;
    HDC deviceConext;
    HGLRC renderContext;

public:
    Win32OpenGLGraphicsDevice();

    bool Create(WindowHandle handle);
    bool MakeCurrent();

    virtual void Clear(graphics::ClearOptions options, const Color& color, float depth, int stencil);
    virtual void Clear(graphics::ClearOptions options, const Vector4& color, float depth, int stencil);
    virtual void Clear(const Color& color);

    virtual void DrawPrimitives(graphics::PrimitiveType primitiveType, int startVertex, int primitiveCount);

    virtual void Present();

    virtual void SetVertexBuffer(const graphics::VertexBuffer& vertexBuffer);
    virtual void SetVertexBuffer(const graphics::VertexBuffer& vertexBuffer, int vertexOffset);
};

Win32OpenGLGraphicsDevice::Win32OpenGLGraphicsDevice()
{ }

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

bool Win32OpenGLGraphicsDevice::Create(WindowHandle handle)
{
    this->_handle = handle;

    deviceConext = GetWindowDC(handle.window);

    if (!deviceConext)
    {
        std::cerr << "Unable to get Window Device Context\n";
        return false;
    }

    if (!InitPixelFormat(deviceConext))
    {
        std::cerr << "Unable to initialize pixel format\n";
        return false;
    }

    renderContext = wglCreateContext(deviceConext);

    if (!renderContext)
    {
        std::cerr << "Unable to create Render Context\n";
        return false;
    }

    MakeCurrent();

    return true;
}

bool Win32OpenGLGraphicsDevice::MakeCurrent()
{
    return wglMakeCurrent(deviceConext, renderContext);
}

void Win32OpenGLGraphicsDevice::Clear(yna::framework::graphics::ClearOptions options, const Color& color, float depth, int stencil)
{
    MakeCurrent();

    glClearColor(float(color.R) / 255.0f, float(color.G) / 255.0f, float(color.B) / 255.0f, float(color.A) / 255.0f);
    glClearDepth(depth);
    glClearStencil(stencil);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Win32OpenGLGraphicsDevice::Clear(yna::framework::graphics::ClearOptions options, const Vector4& color, float depth, int stencil)
{
    MakeCurrent();

    glClearColor(float(color.X) / 255.0f, float(color.Y) / 255.0f, float(color.Z) / 255.0f, float(color.W) / 255.0f);
    glClearDepth(depth);
    glClearStencil(stencil);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Win32OpenGLGraphicsDevice::Clear(const Color& color)
{
    MakeCurrent();

    glClearColor(float(color.R) / 255.0f, float(color.G) / 255.0f, float(color.B) / 255.0f, float(color.A) / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Win32OpenGLGraphicsDevice::DrawPrimitives(graphics::PrimitiveType primitiveType, int startVertex, int primitiveCount)
{
    // todo
}

void Win32OpenGLGraphicsDevice::Present()
{
    SwapBuffers(this->deviceConext);
}

void Win32OpenGLGraphicsDevice::SetVertexBuffer(const yna::framework::graphics::VertexBuffer& vertexBuffer)
{
    // todo
}

void Win32OpenGLGraphicsDevice::SetVertexBuffer(const yna::framework::graphics::VertexBuffer& vertexBuffer, int vertexOffset)
{
    // todo
}













class Win32Window : public GameWindow
{
    Game* _game;
    Win32OpenGLGraphicsDevice* _graphicsDevice;

public:
    Win32Window(Game* game, Win32OpenGLGraphicsDevice* graphicsDevice);

    void Create();
    void HandleEvents();
    void Show();
    bool IsOpen();

    LRESULT WindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
    static LRESULT StaticProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};

Win32Window::Win32Window(Game* game, Win32OpenGLGraphicsDevice* graphicsDevice)
    : _game(game), _graphicsDevice(graphicsDevice)
{ }

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

void Win32Window::Create()
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
        _graphicsDevice->Create(_handle);
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
    Win32Window* _window;
    Win32OpenGLGraphicsDevice* _graphicsDevice;
    bool _isRunning;
public:
    Win32Platform(Game* game, Win32OpenGLGraphicsDevice* graphicsDevice);

    virtual bool BeforeDraw();
    virtual void AfterDraw();
    virtual void RunLoop();
    virtual void Exit();
};

Win32Platform::Win32Platform(Game* game, Win32OpenGLGraphicsDevice* graphicsDevice)
    : GamePlatform(game), _graphicsDevice(graphicsDevice), _isRunning(false)
{
    _window = new Win32Window(game, graphicsDevice);
    _window->Create();

    SetGraphicsDevice(graphicsDevice);
    SetGameWindow(_window);
}

bool Win32Platform::BeforeDraw()
{
    if (!_graphicsDevice->MakeCurrent())
    {
        return false;
    }

    glViewport(0, 0, _window->ClientSizeWidth, _window->ClientSizeHeight);

    return true;
}

void Win32Platform::AfterDraw()
{
    _graphicsDevice->Present();
}

void Win32Platform::RunLoop()
{
    _isRunning = true;

    _window->Show();

    while (this->_isRunning && _window->IsOpen())
    {
        _window->HandleEvents();

        _game->Tick();
    }
}

void Win32Platform::Exit()
{
    this->_isRunning = false;
}

GamePlatform* GamePlatform::PlatformCreate(Game* game)
{
    static Win32Platform instance(game, new Win32OpenGLGraphicsDevice());

    return &instance;
}
