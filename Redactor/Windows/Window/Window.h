#ifndef __WINDOW_H__
#define __WINDOW_H__

#define SIMPLE_WINDOW_CLASS "SimpleWindowClass"
#include <windows.h>
#include <vector>

namespace Redactor
{

namespace Windows
{
    class Window
    {
    public:
        Window(void);
        Window(LPCSTR title, DWORD style = WS_OVERLAPPEDWINDOW, int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int width = 256, int height = 256, Window* parentWindow = nullptr, HMENU id = NULL, LPVOID data = NULL);

        HWND GetHWND(void) const;

        bool IsCreated(void) const;

        LPCSTR GetTitle(void) const;
        virtual void SetTitle(LPCSTR title);

        DWORD GetStyle(void) const;
        virtual void SetStyle(DWORD style);

        int GetX(void) const;
        virtual void SetX(int x);

        int GetY(void) const;
        virtual void SetY(int y);

        int GetWidth(void) const;
        virtual void SetWidth(int width);

        int GetHeight(void) const;
        virtual void SetHeight(int height);

        Window* GetParentWindow(void) const;
        virtual void SetParentWindow(Window* parentWindow);

        HMENU GetId(void) const;
        void SetId(HMENU id);

        LPVOID GetDataPtr(void) const;
        void SetDataPtr(LPVOID data);

        virtual bool Create(void);
        void Show(int nCmdShow = SW_SHOW);
        void Hide(void);

        virtual void Destroy(void);

        void AddChildWindow(Window* window);
        void RemoveChildWindow(Window* window);
        void ClearChildWindows(void);

        virtual ~Window(void);

    protected:
        HWND hwnd;
        bool isCreated;
        LPCSTR title;
        DWORD style;
        int x;
        int y;
        int width;
        int height;
        Window* parentWindow;
        HMENU id;
        LPVOID data;
        std::vector<Window*> childs;
    };

    bool RegisterSimpleWindowClass(void);
}

}

#endif // __WINDOW_H__
