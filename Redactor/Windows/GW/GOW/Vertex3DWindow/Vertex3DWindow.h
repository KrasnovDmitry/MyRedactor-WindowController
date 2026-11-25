#ifndef __VERTEX_3D_WINDOW_H__
#define __VERTEX_3D_WINDOW_H__

#include "../IGraphicObjectWindow.h"
#include "../../../../Graphic/Vertex3D/Vertex3D.h"

#define VERTEX_3D_WINDOW_CLASS "Vertex3DWindowClass"
#define X_INPUT 101
#define Y_INPUT 102
#define Z_INPUT 103

namespace Redactor
{

namespace Windows
{

namespace GW
{

namespace GOW
{
    LRESULT CALLBACK Vertex3DWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    class Vertex3DWindow: public IGraphicObjectWindow<Redactor::Graphic::Vertex3D>
    {
    public:
        Vertex3DWindow(void);
        Vertex3DWindow(LPCSTR title, DWORD style = WS_OVERLAPPEDWINDOW, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int width = 185, int height = 140, Window* parentWindow = nullptr, HMENU id = NULL, Redactor::Graphic::Vertex3D* vert_ptr = nullptr);
        virtual ~Vertex3DWindow(void);

        bool Create(void) override;

        friend LRESULT CALLBACK Vertex3DWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    protected:
        HWND x_input;
        HWND y_input;
        HWND z_input;
    };

    bool RegisterVertex3DWindowClass(void);
}

}

}

}

#endif // __VERTEX_3D_WINDOW_H__
