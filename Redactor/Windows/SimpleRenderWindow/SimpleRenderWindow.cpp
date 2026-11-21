#include "SimpleRenderWindow.h"

using namespace Redactor::Windows;

LRESULT CALLBACK SimpleRenderWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

bool Redactor::Windows::RegisterSimpleRenderWindowClass(void)
{
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.lpfnWndProc = SimpleRenderWindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = GetModuleHandle(nullptr);
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = SIMPLE_RENDER_WINDOW_CLASS;
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wcex.style = CS_OWNDC;
    return RegisterClassEx(&wcex);
}

LRESULT CALLBACK SimpleRenderWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);
        break;

        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                case VK_ESCAPE:
                    PostQuitMessage(0);
                break;
            }
        }
        break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}


SimpleRenderWindow::SimpleRenderWindow(void):SimpleRenderWindow("Simple Render Window")
{

}

SimpleRenderWindow::SimpleRenderWindow(LPCSTR title, DWORD style, int x, int y, int width, int height, Window* parentWindow, HMENU id, LPVOID data): Window(title, style, x, y, width, height, parentWindow, id, data)
{
    this->hDC = NULL;
    this->hRC = NULL;
}

bool SimpleRenderWindow::Create(void)
{
    bool result = Window::Create();
    if(result)
        EnableOpenGL(this->hwnd, &this->hDC, &this->hRC);
    return result;
}

void SimpleRenderWindow::Destroy(void)
{
    Redactor::Windows::DisableOpenGL(this->hwnd, this->hDC, this->hRC);
    Window::Destroy();
}

SimpleRenderWindow::~SimpleRenderWindow(void)
{
    DisableOpenGL(this->hwnd, this->hDC, this->hRC);
}

void SimpleRenderWindow::SetCurrent(void)
{
    wglMakeCurrent(this->hDC, this->hRC);
}

void SimpleRenderWindow::SwapBuffer(void)
{
    SwapBuffers(this->hDC);
}

void Redactor::Windows::EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);
}

void Redactor::Windows::DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}

void SimpleRenderWindow::DrawByFunc(void (*draw_func)(void))
{
    this->SetCurrent();
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_func();
    this->SwapBuffer();
    wglMakeCurrent(NULL, NULL);
}
