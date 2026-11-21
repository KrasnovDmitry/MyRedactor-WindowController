#ifndef __SIMPLE_RENDER_WINDOW_H__
#define __SIMPLE_RENDER_WINDOW_H__

#define SIMPLE_RENDER_WINDOW_CLASS "SimpleRenderWindowClass"
#include "../Window/Window.h"
#include <GL/gl.h>

namespace Redactor
{

namespace Windows
{
    class SimpleRenderWindow: public Window
    {
    public:
        SimpleRenderWindow(void);
        SimpleRenderWindow(LPCSTR title, DWORD style = WS_OVERLAPPEDWINDOW, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int width = 256, int height = 256, Window* parentWindow = nullptr, HMENU id = NULL, LPVOID data = NULL);

        bool Create(void) override;
        void Destroy(void) override;

        void SetCurrent(void);
        void SwapBuffer(void);

        void DrawByFunc(void (*draw_func)(void));

        virtual ~SimpleRenderWindow(void);

    protected:
        HDC hDC;
        HGLRC hRC;
    };

    bool RegisterSimpleRenderWindowClass(void);
    void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC);
    void DisableOpenGL(HWND hwnd, HDC hDC, HGLRC hRC);
}

}

#endif // __SIMPLE_RENDER_WINDOW_H__
