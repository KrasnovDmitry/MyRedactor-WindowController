#ifndef __LINKED_LINE_3D_WINDOW_H__
#define __LINKED_LINE_3D_WINDOW_H__

#include "../IGraphicObjectWindow.h"
#include "../../../../Graphic/LinkedLine3D/LinkedLine3D.h"

#define LINKED_LINE_3D_WINDOW_CLASS "LinkedLine3DWindowClass"
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
    LRESULT CALLBACK LinkedLine3DWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    class LinkedLine3DWindow: public IGraphicObjectWindow<Redactor::Graphic::LinkedLine3D>
    {
    public:
        LinkedLine3DWindow(void);
        LinkedLine3DWindow(LPCSTR title, DWORD style = WS_OVERLAPPEDWINDOW, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int width = 300, int height = 165, Window* parentWindow = nullptr, HMENU id = NULL, Redactor::Graphic::LinkedLine3D* line_ptr = nullptr);
        virtual ~LinkedLine3DWindow(void);

        bool Create(void) override;

        friend LRESULT CALLBACK LinkedLine3DWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    protected:
        HWND x0_input;
        HWND y0_input;
        HWND z0_input;

        HWND x1_input;
        HWND y1_input;
        HWND z1_input;

    };

    bool RegisterLinkedLine3DWindowClass(void);
}

}

}

}

#endif // __LINKED_LINE_3D_WINDOW_H__
