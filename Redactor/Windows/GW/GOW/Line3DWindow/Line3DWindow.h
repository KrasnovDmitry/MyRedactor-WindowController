#ifndef __LINE_3D_WINDOW_H__
#define __LINE_3D_WINDOW_H__

#include "../IGraphicObjectWindow.h"
#include "../../../../Graphic/Line3D/Line3D.h"

#define LINE_3D_WINDOW_CLASS "Line3DWindowClass"
#define X0_INPUT 101
#define Y0_INPUT 102
#define Z0_INPUT 103
#define X1_INPUT 104
#define Y1_INPUT 105
#define Z1_INPUT 106

namespace Redactor
{

namespace Windows
{

namespace GW
{

namespace GOW
{
    LRESULT CALLBACK Line3DWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    class Line3DWindow: public IGraphicObjectWindow<Redactor::Graphic::Line3D>
    {
    public:
        Line3DWindow(void);
        Line3DWindow(LPCSTR title, DWORD style = WS_OVERLAPPEDWINDOW, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int width = 256, int height = 256, Window* parentWindow = nullptr, HMENU id = NULL, Redactor::Graphic::Line3D* line_ptr = nullptr);
        virtual ~Line3DWindow(void);

        bool Create(void) override;

        friend LRESULT CALLBACK Line3DWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    protected:
        HWND x0_input;
        HWND y0_input;
        HWND z0_input;

        HWND x1_input;
        HWND y1_input;
        HWND z1_input;
    };

    bool RegisterLine3DWindowClass(void);
}

}

}

}

#endif // __LINE_3D_WINDOW_H__
