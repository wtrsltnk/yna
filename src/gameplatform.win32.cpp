
#include "gameplatform.h"
#include "game.h"
#include "gamewindow.h"
#include "graphics/graphicsdevice.h"
#include "graphics/vertexelement.h"
#include "platform.h"

#include <glad/glad.h>
#include <iostream>
#include <map>

#include <GL/wglext.h>
#include <windows.h>

using namespace yna::framework;

class Win32OpenGLGraphicsDevice : public graphics::GraphicsDevice
{
public:
    Win32OpenGLGraphicsDevice();

    bool Create(
        WindowHandle handle);

    bool MakeCurrent();

    virtual void Clear(
        graphics::ClearOptions options,
        const Color &color,
        float depth,
        int stencil);

    virtual void Clear(
        graphics::ClearOptions options,
        const Vector4 &color,
        float depth,
        int stencil);

    virtual void Clear(
        const Color &color);

    virtual void DrawPrimitives(
        graphics::PrimitiveType primitiveType,
        int startVertex,
        int primitiveCount);

    virtual void Present();

    virtual void SetVertexBuffer(
        graphics::VertexBuffer &vertexBuffer);

    virtual void SetVertexBuffer(
        graphics::VertexBuffer &vertexBuffer,
        int vertexOffset);

private:
    WindowHandle _handle;
    HDC deviceConext;
    HGLRC renderContext;
    std::map<const graphics::VertexBuffer *, GLuint> _boundVertexBuffers;
    graphics::VertexBuffer *_currentVertexBuffer = nullptr;
};

Win32OpenGLGraphicsDevice::Win32OpenGLGraphicsDevice()
    : _currentVertexBuffer(nullptr)
{}

bool InitPixelFormat(
    HDC hDC)
{
    static PIXELFORMATDESCRIPTOR pfd =
        {
            sizeof(PIXELFORMATDESCRIPTOR), // Size Of This Pixel Format Descriptor
            1,                             // Version Number
            PFD_DRAW_TO_WINDOW |           // Format Must Support Window
                PFD_SUPPORT_OPENGL |       // Format Must Support CodeGL
                PFD_DOUBLEBUFFER,          // Must Support Double Buffering
            PFD_TYPE_RGBA,                 // Request An RGBA Format
            32,                            // Select Our Color Depth
            0, 0, 0, 0, 0, 0,              // Color Bits Ignored
            0,                             // No Alpha Buffer
            0,                             // Shift Bit Ignored
            0,                             // No Accumulation Buffer
            0, 0, 0, 0,                    // Accumulation Bits Ignored
            24,                            // 24Bit Z-Buffer (Depth Buffer)
            0,                             // No Stencil Buffer
            0,                             // No Auxiliary Buffer
            PFD_MAIN_PLANE,                // Main Drawing Layer
            0,                             // Reserved
            0, 0, 0                        // Layer Masks Ignored
        };

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

typedef HGLRC(WINAPI *PFNGLXCREATECONTEXTATTRIBS)(HDC hDC, HGLRC hShareContext, const int *attribList);

bool Win32OpenGLGraphicsDevice::Create(
    WindowHandle handle)
{
    this->_handle = handle;

    deviceConext = GetDC(handle.window);

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

    auto pfnGlxCreateContext = (PFNGLXCREATECONTEXTATTRIBS)wglGetProcAddress("wglCreateContextAttribsARB");
    if (pfnGlxCreateContext == nullptr)
    {
        renderContext = wglCreateContext(deviceConext);

        if (!renderContext)
        {
            std::cerr << "Unable to create Render Context\n";
            return false;
        }
    }
    else
    {
        GLint attribList[] =
            {
                WGL_CONTEXT_MAJOR_VERSION_ARB,
                4,
                WGL_CONTEXT_MINOR_VERSION_ARB,
                6,
                0,
            };

        renderContext = pfnGlxCreateContext(deviceConext, 0, attribList);

        if (!renderContext)
        {
            std::cerr << "Unable to create modern opengl (v4.6) Render Context\n";
            return false;
        }
    }

    MakeCurrent();

    if (!gladLoadGL())
    {
        std::cerr << "Unable to load opengl\n";
        return false;
    }

    std::cout << "GL_VERSION                  : " << glGetString(GL_VERSION) << "\n";
    std::cout << "GL_SHADING_LANGUAGE_VERSION : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << "\n";
    std::cout << "GL_RENDERER                 : " << glGetString(GL_RENDERER) << "\n";
    std::cout << "GL_VENDOR                   : " << glGetString(GL_VENDOR) << std::endl;

    return true;
}

bool Win32OpenGLGraphicsDevice::MakeCurrent()
{
    return wglMakeCurrent(deviceConext, renderContext);
}

void Win32OpenGLGraphicsDevice::Clear(
    yna::framework::graphics::ClearOptions options,
    const Color &color,
    float depth,
    int stencil)
{
    MakeCurrent();

    glClearColor(float(color.R) / 255.0f, float(color.G) / 255.0f, float(color.B) / 255.0f, float(color.A) / 255.0f);
    glClearDepth(depth);
    glClearStencil(stencil);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Win32OpenGLGraphicsDevice::Clear(
    yna::framework::graphics::ClearOptions options,
    const Vector4 &color,
    float depth,
    int stencil)
{
    MakeCurrent();

    glClearColor(float(color.X) / 255.0f, float(color.Y) / 255.0f, float(color.Z) / 255.0f, float(color.W) / 255.0f);
    glClearDepth(depth);
    glClearStencil(stencil);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Win32OpenGLGraphicsDevice::Clear(
    const Color &color)
{
    MakeCurrent();

    glClearColor(float(color.R) / 255.0f, float(color.G) / 255.0f, float(color.B) / 255.0f, float(color.A) / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

int VertexElementFormatSize(
    graphics::VertexElementFormats format)
{
    switch (format)
    {
        case graphics::VertexElementFormats::Byte4:
            return 4;
        case graphics::VertexElementFormats::Color:
            return 4;
        case graphics::VertexElementFormats::HalfVector2:
            return 2;
        case graphics::VertexElementFormats::HalfVector4:
            return 4;
        case graphics::VertexElementFormats::NormalizedShort2:
            return 2;
        case graphics::VertexElementFormats::NormalizedShort4:
            return 4;
        case graphics::VertexElementFormats::Short2:
            return 2;
        case graphics::VertexElementFormats::Short4:
            return 4;
        case graphics::VertexElementFormats::Single:
            return 1;
        case graphics::VertexElementFormats::Vector2:
            return 2;
        case graphics::VertexElementFormats::Vector3:
            return 3;
        case graphics::VertexElementFormats::Vector4:
            return 4;
    }
    return 4;
}

GLenum ComponentTypeFromVertexElementFormat(
    graphics::VertexElementFormats format)
{
    switch (format)
    {
        case graphics::VertexElementFormats::Byte4:
            return GL_BYTE;
        case graphics::VertexElementFormats::Color:
            return GL_BYTE;
        case graphics::VertexElementFormats::HalfVector2:
            return GL_FLOAT;
        case graphics::VertexElementFormats::HalfVector4:
            return GL_FLOAT;
        case graphics::VertexElementFormats::NormalizedShort2:
            return GL_SHORT;
        case graphics::VertexElementFormats::NormalizedShort4:
            return GL_SHORT;
        case graphics::VertexElementFormats::Short2:
            return GL_SHORT;
        case graphics::VertexElementFormats::Short4:
            return GL_SHORT;
        case graphics::VertexElementFormats::Single:
            return GL_INT;
        case graphics::VertexElementFormats::Vector2:
            return GL_FLOAT;
        case graphics::VertexElementFormats::Vector3:
            return GL_FLOAT;
        case graphics::VertexElementFormats::Vector4:
            return GL_FLOAT;
    }
    return GL_FLOAT;
}

void Win32OpenGLGraphicsDevice::DrawPrimitives(
    graphics::PrimitiveType primitiveType,
    int startVertex,
    int primitiveCount)
{
    if (this->_currentVertexBuffer == nullptr)
    {
        return;
    }

    graphics::VertexDeclaration vd = this->_currentVertexBuffer->VertexDeclaration;
    for (int i = 0; i < vd.GetVertexElements().size(); ++i)
    {
        auto element = vd.GetVertexElements()[i];
        glVertexAttribPointer(i, VertexElementFormatSize(element.VertexElementFormat),
                              ComponentTypeFromVertexElementFormat(element.VertexElementFormat),
                              GL_FALSE, 0, (void *)element.Offset);
        glEnableVertexAttribArray(i);
    }

    if (primitiveType == graphics::PrimitiveType::LineList)
    {
        glDrawArrays(GL_LINES, startVertex, primitiveCount);
    }

    if (primitiveType == graphics::PrimitiveType::LineStrip)
    {
        glDrawArrays(GL_LINE_STRIP, startVertex, primitiveCount);
    }

    if (primitiveType == graphics::PrimitiveType::TriangleList)
    {
        glDrawArrays(GL_TRIANGLES, startVertex, primitiveCount);
    }

    if (primitiveType == graphics::PrimitiveType::TriangleStrip)
    {
        glDrawArrays(GL_TRIANGLE_STRIP, startVertex, primitiveCount);
    }

    for (int i = 0; i < vd.GetVertexElements().size(); ++i)
    {
        glDisableVertexAttribArray(i);
    }
}

void Win32OpenGLGraphicsDevice::Present()
{
    SwapBuffers(this->deviceConext);
}

void Win32OpenGLGraphicsDevice::SetVertexBuffer(
    yna::framework::graphics::VertexBuffer &vertexBuffer)
{
    GLuint bufferIndex;

    if (_boundVertexBuffers.find(&vertexBuffer) == _boundVertexBuffers.end())
    {
        glGenBuffers(1, &bufferIndex);
        _boundVertexBuffers.insert(std::make_pair(&vertexBuffer, bufferIndex));
    }
    else
    {
        bufferIndex = _boundVertexBuffers.find(&vertexBuffer)->second;
    }

    byte *buffer;
    graphics::VertexDeclaration vdecl = vertexBuffer.VertexDeclaration.get();
    vertexBuffer.GetData(0, &buffer, 0, vertexBuffer.VertexCount.get(), vdecl.VertexStride.get());

    glBindBuffer(GL_ARRAY_BUFFER, bufferIndex);
    glBufferData(GL_ARRAY_BUFFER, vdecl.VertexStride, &buffer, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    _currentVertexBuffer = &vertexBuffer;
}

void Win32OpenGLGraphicsDevice::SetVertexBuffer(
    yna::framework::graphics::VertexBuffer &vertexBuffer,
    int vertexOffset)
{
    // todo
}

class Win32Window : public GameWindow
{
public:
    Win32Window(
        Game *game,
        Win32OpenGLGraphicsDevice *graphicsDevice);

    void Create();
    void HandleEvents();
    void Show();
    bool IsOpen();

    LRESULT WindowProc(
        UINT uMsg,
        WPARAM wParam,
        LPARAM lParam);

    static LRESULT StaticProc(
        HWND hWnd,
        UINT uMsg,
        WPARAM wParam,
        LPARAM lParam);

private:
    Game *_game = nullptr;
    Win32OpenGLGraphicsDevice *_graphicsDevice = nullptr;
};

Win32Window::Win32Window(
    Game *game,
    Win32OpenGLGraphicsDevice *graphicsDevice)
    : _game(game),
      _graphicsDevice(graphicsDevice)
{}

LRESULT Win32Window::StaticProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam)
{
    Win32Window *window = nullptr;

    if (uMsg == WM_NCCREATE)
    {
        window = reinterpret_cast<Win32Window *>(((LPCREATESTRUCT)lParam)->lpCreateParams);

        SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<long long>(window));

        if (window != nullptr)
        {
            window->_handle.window = hWnd;
        }
    }
    else
    {
        window = reinterpret_cast<Win32Window *>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
    }

    if (window != nullptr)
    {
        return window->WindowProc(uMsg, wParam, lParam);
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LRESULT InitWindowClass(
    const WindowHandle &handle,
    const char *className)
{
    WNDCLASSEX wcex;

    if (GetClassInfoEx(handle.instance, className, &wcex))
    {
        return TRUE;
    }

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
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

    if (!InitWindowClass(_handle, "YNAWin32Window"))
    {
        return;
    }

    _handle.window = CreateWindowEx(
        WS_EX_APPWINDOW,
        "YNAWin32Window", "YNA",
        WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL,
        _handle.instance,
        (VOID *)this);

    Show();

    _graphicsDevice->Create(_handle);
}

void Win32Window::Show()
{
    if (_handle.window == NULL)
    {
        return;
    }

    ShowWindow(_handle.window, SW_SHOW);
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

LRESULT Win32Window::WindowProc(
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
        {
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
public:
    Win32Platform(
        Game *game,
        Win32OpenGLGraphicsDevice *graphicsDevice);

    virtual bool BeforeDraw();
    virtual void AfterDraw();
    virtual void RunLoop();
    virtual void Exit();

private:
    Win32Window *_window = nullptr;
    Win32OpenGLGraphicsDevice *_graphicsDevice = nullptr;
    bool _isRunning;
};

Win32Platform::Win32Platform(
    Game *game,
    Win32OpenGLGraphicsDevice *graphicsDevice)
    : GamePlatform(game),
      _graphicsDevice(graphicsDevice),
      _isRunning(false)
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

GamePlatform *GamePlatform::PlatformCreate(
    Game *game)
{
    static Win32Platform instance(game, new Win32OpenGLGraphicsDevice());

    return &instance;
}
