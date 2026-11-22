#include "Vertex3DWindow.h"
#include "../../../SubclassesProc/DoubleEditSubclassProc/DoubleEditSubclassProc.h"
#include <string>
#include <iostream>

namespace Z = Redactor::Windows::GW::GOW;

LRESULT CALLBACK Z::Vertex3DWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

bool Z::RegisterVertex3DWindowClass(void)
{
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.lpfnWndProc = Z::Vertex3DWindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = GetModuleHandle(nullptr);
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = VERTEX_3D_WINDOW_CLASS;
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    return RegisterClassEx(&wcex);
}

LRESULT CALLBACK Z::Vertex3DWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Z::Vertex3DWindow* self = nullptr;
    if (uMsg == WM_NCCREATE) {
        auto cs = reinterpret_cast<CREATESTRUCT*>(lParam);
        self = reinterpret_cast<Z::Vertex3DWindow*>(cs->lpCreateParams);
        SetWindowLongPtrW(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(self));
    } else {
        self = reinterpret_cast<Z::Vertex3DWindow*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));
    }

    switch (uMsg)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_COMMAND:
        if (self && self->objectPtr && self->isCreated)
        {
            int id = LOWORD(wParam);
            int code = HIWORD(wParam);
            if (id == X_INPUT && code == EN_CHANGE) {
                wchar_t buf[64];
                GetWindowTextW(self->x_input, buf, 64);
                wchar_t* end = nullptr;
                double d = std::wcstod(buf, &end);
                self->objectPtr->SetX(d);
            }
            else if (id == Y_INPUT && code == EN_CHANGE) {
                wchar_t buf[64];
                GetWindowTextW(self->y_input, buf, 64);
                wchar_t* end = nullptr;
                double d = std::wcstod(buf, &end);
                self->objectPtr->SetY(d);
            }
            else if (id == Z_INPUT && code == EN_CHANGE) {
                wchar_t buf[64];
                GetWindowTextW(self->z_input, buf, 64);
                wchar_t* end = nullptr;
                double d = std::wcstod(buf, &end);
                self->objectPtr->SetZ(d);
            }
        }
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

Z::Vertex3DWindow::Vertex3DWindow(void): Z::Vertex3DWindow("Vertex Edit Window (VEW)") {}

Z::Vertex3DWindow::Vertex3DWindow(LPCSTR title, DWORD style, int x, int y, int width, int height, Window* parentWindow, HMENU id, Redactor::Graphic::Vertex3D* vert_ptr)
{
    this->hwnd = 0;
    this->isCreated = false;
    this->title = title;
    this->style = style;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->parentWindow = parentWindow;
    this->id = id;
    this->data = static_cast<void*>(this);
    this->x_input = 0;
    this->y_input = 0;
    this->z_input = 0;
    this->objectPtr = nullptr;
    this->childs.clear();
}

Z::Vertex3DWindow::~Vertex3DWindow(void)
{
    DestroyWindow(this->hwnd);
}

bool Z::Vertex3DWindow::Create(void)
{
    if(this->IsCreated())
    {
        throw std::logic_error("Невозможно создать два окна в одном экземпляре окна (multi-creation error)");
        return false;
    }
    HWND parentHWND = NULL;
    if(this->parentWindow != nullptr)
    {
        if(!this->parentWindow->IsCreated())
        {
            throw std::logic_error("Невозможно создать дочернее окно несозданного окна (child before parent creation)");
            return false;
        }
        parentHWND = this->parentWindow->GetHWND();
    }

    this->hwnd = CreateWindowEx(0,
                                VERTEX_3D_WINDOW_CLASS,
                                this->title,
                                this->style,
                                this->x,
                                this->y,
                                this->width,
                                this->height,
                                parentHWND,
                                this->id,
                                GetModuleHandle(nullptr),
                                this->data);


    HWND X_lable = CreateWindowEx(0, "STATIC", "X", WS_CHILD | WS_VISIBLE, 0, 0, 15, 20, this->hwnd, 0, GetModuleHandle(nullptr), NULL);
    this-> x_input = CreateWindowEx(0, "EDIT", "", WS_CHILD | WS_BORDER | WS_VISIBLE, 15, 0, 100, 20, this->hwnd, HMENU(X_INPUT), GetModuleHandle(nullptr), NULL);
    SetWindowSubclass(this->x_input, Redactor::Windows::SubclassesProc::DoubleEditSubclassProc, 1, 0);

    HWND Y_lable = CreateWindowEx(0, "STATIC", "Y", WS_CHILD | WS_VISIBLE, 0, 25, 15, 20, this->hwnd, 0, GetModuleHandle(nullptr), NULL);
    this-> y_input = CreateWindowEx(0, "EDIT", "", WS_CHILD | WS_BORDER | WS_VISIBLE, 15, 25, 100, 20, this->hwnd, HMENU(Y_INPUT), GetModuleHandle(nullptr), NULL);
    SetWindowSubclass(this->y_input, Redactor::Windows::SubclassesProc::DoubleEditSubclassProc, 1, 0);

    HWND Z_lable = CreateWindowEx(0, "STATIC", "Z", WS_CHILD | WS_VISIBLE, 0, 50, 15, 20, this->hwnd, 0, GetModuleHandle(nullptr), NULL);
    this-> z_input = CreateWindowEx(0, "EDIT", "", WS_CHILD | WS_BORDER | WS_VISIBLE, 15, 50, 100, 20, this->hwnd, HMENU(Z_INPUT), GetModuleHandle(nullptr), NULL);
    SetWindowSubclass(this->z_input, Redactor::Windows::SubclassesProc::DoubleEditSubclassProc, 1, 0);

    if (objectPtr) {
        wchar_t buf[64];
        swprintf((wchar_t*)buf, L"%.10g", objectPtr->GetX());
        SetWindowTextW(x_input, buf);
        swprintf((wchar_t*)buf, L"%.10g", objectPtr->GetY());
        SetWindowTextW(y_input, buf);
        swprintf((wchar_t*)buf, L"%.10g", objectPtr->GetZ());
        SetWindowTextW(z_input, buf);
    }

    if(hwnd)
        this->isCreated = true;
    else
        throw std::runtime_error("Неизвестная ошибка создания окна");
    return this->isCreated;
}

