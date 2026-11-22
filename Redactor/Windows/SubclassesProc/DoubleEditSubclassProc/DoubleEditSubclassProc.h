#ifndef __DOUBLE_EDIT_SUBCLASS_PROC_H__
#define __DOUBLE_EDIT_SUBCLASS_PROC_H__
#include <windows.h>
#define _WIN32_WINNT 0x0601
#include <commctrl.h>

namespace Redactor
{

namespace Windows
{

namespace SubclassesProc
{
    LRESULT CALLBACK DoubleEditSubclassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData);
}

}

}

#endif // __DOUBLE_EDIT_SUBCLASS_PROC_H__
