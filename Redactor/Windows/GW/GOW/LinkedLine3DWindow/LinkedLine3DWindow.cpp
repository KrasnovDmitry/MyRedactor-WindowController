#include "LinkedLine3DWindow.h"
#include "../../../SubclassesProc/DoubleEditSubclassProc/DoubleEditSubclassProc.h"
#include <string>
#include <stdexcept>

namespace Z = Redactor::Windows::GW::GOW;

LRESULT CALLBACK Z::LinkedLine3DWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

bool Z::RegisterLinkedLine3DWindowClass(void)
{
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.lpfnWndProc = Z::LinkedLine3DWindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = GetModuleHandle(nullptr);
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = LINKED_LINE_3D_WINDOW_CLASS;
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    return RegisterClassEx(&wcex);
}

LRESULT CALLBACK Z::LinkedLine3DWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Z::LinkedLine3DWindow* self = nullptr;
    if (uMsg == WM_NCCREATE) {
        auto cs = reinterpret_cast<CREATESTRUCT*>(lParam);
        self = reinterpret_cast<Z::LinkedLine3DWindow*>(cs->lpCreateParams);
        SetWindowLongPtrW(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(self));
    } else {
        self = reinterpret_cast<Z::LinkedLine3DWindow*>(GetWindowLongPtrW(hwnd, GWLP_USERDATA));
    }

    switch (uMsg)
    {
    case WM_CLOSE:
        self->Destroy();
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_COMMAND:
        if (self && self->objectPtr && self->isCreated)
        {
            int id = LOWORD(wParam);
            int code = HIWORD(wParam);
            if (id == X0_INPUT && code == EN_CHANGE) {
                wchar_t buf[64];
                GetWindowTextW(self->x0_input, buf, 64);
                wchar_t* end = nullptr;
                double d = std::wcstod(buf, &end);
                self->objectPtr->SetStartX(d);
            }
            else if (id == Y0_INPUT && code == EN_CHANGE) {
                wchar_t buf[64];
                GetWindowTextW(self->y0_input, buf, 64);
                wchar_t* end = nullptr;
                double d = std::wcstod(buf, &end);
                self->objectPtr->SetStartY(d);
            }
            else if (id == Z0_INPUT && code == EN_CHANGE) {
                wchar_t buf[64];
                GetWindowTextW(self->z0_input, buf, 64);
                wchar_t* end = nullptr;
                double d = std::wcstod(buf, &end);
                self->objectPtr->SetStartZ(d);
            }
            else if (id == X1_INPUT && code == EN_CHANGE) {
                wchar_t buf[64];
                GetWindowTextW(self->x1_input, buf, 64);
                wchar_t* end = nullptr;
                double d = std::wcstod(buf, &end);
                self->objectPtr->SetEndX(d);
            }
            else if (id == Y1_INPUT && code == EN_CHANGE) {
                wchar_t buf[64];
                GetWindowTextW(self->y1_input, buf, 64);
                wchar_t* end = nullptr;
                double d = std::wcstod(buf, &end);
                self->objectPtr->SetEndY(d);
            }
            else if (id == Z1_INPUT && code == EN_CHANGE) {
                wchar_t buf[64];
                GetWindowTextW(self->z1_input, buf, 64);
                wchar_t* end = nullptr;
                double d = std::wcstod(buf, &end);
                self->objectPtr->SetEndZ(d);
            }
        }
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

Z::LinkedLine3DWindow::LinkedLine3DWindow(void): Z::LinkedLine3DWindow("Linked Line Edit Window (LLEW)") {}

Z::LinkedLine3DWindow::LinkedLine3DWindow(LPCSTR title, DWORD style, int x, int y, int width, int height, Window* parentWindow, HMENU id, Redactor::Graphic::LinkedLine3D* line_ptr)
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
    this->data = static_cast<LPVOID>(this);
    this->x0_input = 0;
    this->y0_input = 0;
    this->z0_input = 0;
    this->x1_input = 0;
    this->y1_input = 0;
    this->z1_input = 0;
    this->objectPtr = line_ptr;
    this->childs.clear();
}

Z::LinkedLine3DWindow::~LinkedLine3DWindow(void)
{
    DestroyWindow(this->hwnd);
}

bool Z::LinkedLine3DWindow::Create(void)
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
                                LINKED_LINE_3D_WINDOW_CLASS,
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


    int x_shift = 150;
    int x_size = 130;

    HWND main_lable = CreateWindowEx(0, "STATIC", "Linked Line Edit Window (LEW)", WS_CHILD | WS_VISIBLE, 0, 0, 225, 20, this->hwnd, 0, GetModuleHandle(nullptr), NULL);
    HWND start_label = CreateWindowEx(0, "STATIC", "Start (Vertex 1):", WS_CHILD | WS_VISIBLE, 0, 25, x_size, 20, this->hwnd, 0, GetModuleHandle(nullptr), NULL);
    HWND X0_lable = CreateWindowEx(0, "STATIC", "X", WS_CHILD | WS_VISIBLE, 0, 50, 15, 20, this->hwnd, 0, GetModuleHandle(nullptr), NULL);
    this->x0_input = CreateWindowEx(0, "EDIT", "", WS_CHILD | WS_BORDER | WS_VISIBLE, 15, 50, 100, 20, this->hwnd, HMENU(X0_INPUT), GetModuleHandle(nullptr), NULL);

    HWND Y0_lable = CreateWindowEx(0, "STATIC", "Y", WS_CHILD | WS_VISIBLE, 0, 75, 15, 20, this->hwnd, 0, GetModuleHandle(nullptr), NULL);
    this->y0_input = CreateWindowEx(0, "EDIT", "", WS_CHILD | WS_BORDER | WS_VISIBLE, 15, 75, 100, 20, this->hwnd, HMENU(Y0_INPUT), GetModuleHandle(nullptr), NULL);

    HWND Z0_lable = CreateWindowEx(0, "STATIC", "Z", WS_CHILD | WS_VISIBLE, 0, 100, 15, 20, this->hwnd, 0, GetModuleHandle(nullptr), NULL);
    this->z0_input = CreateWindowEx(0, "EDIT", "", WS_CHILD | WS_BORDER | WS_VISIBLE, 15, 100, 100, 20, this->hwnd, HMENU(Z0_INPUT), GetModuleHandle(nullptr), NULL);



    HWND end_label = CreateWindowEx(0, "STATIC", "End (Vertex 2):", WS_CHILD | WS_VISIBLE, x_shift, 25, x_size, 20, this->hwnd, 0, GetModuleHandle(nullptr), NULL);
    HWND X1_lable = CreateWindowEx(0, "STATIC", "X", WS_CHILD | WS_VISIBLE, x_shift, 50, 15, 20, this->hwnd, 0, GetModuleHandle(nullptr), NULL);
    this->x1_input = CreateWindowEx(0, "EDIT", "", WS_CHILD | WS_BORDER | WS_VISIBLE, x_shift + 15, 50, 100, 20, this->hwnd, HMENU(X1_INPUT), GetModuleHandle(nullptr), NULL);
    SetWindowSubclass(this->x1_input, Redactor::Windows::SubclassesProc::DoubleEditSubclassProc, 1, 0);

    HWND Y1_lable = CreateWindowEx(0, "STATIC", "Y", WS_CHILD | WS_VISIBLE, x_shift, 75, 15, 20, this->hwnd, 0, GetModuleHandle(nullptr), NULL);
    this->y1_input = CreateWindowEx(0, "EDIT", "", WS_CHILD | WS_BORDER | WS_VISIBLE, x_shift + 15, 75, 100, 20, this->hwnd, HMENU(Y1_INPUT), GetModuleHandle(nullptr), NULL);
    SetWindowSubclass(this->y1_input, Redactor::Windows::SubclassesProc::DoubleEditSubclassProc, 1, 0);

    HWND Z1_lable = CreateWindowEx(0, "STATIC", "Z", WS_CHILD | WS_VISIBLE, x_shift, 100, 15, 20, this->hwnd, 0, GetModuleHandle(nullptr), NULL);
    this->z1_input = CreateWindowEx(0, "EDIT", "", WS_CHILD | WS_BORDER | WS_VISIBLE, x_shift + 15, 100, 100, 20, this->hwnd, HMENU(Z1_INPUT), GetModuleHandle(nullptr), NULL);
    SetWindowSubclass(this->z1_input, Redactor::Windows::SubclassesProc::DoubleEditSubclassProc, 1, 0);

    if (this->objectPtr)
    {
        wchar_t buf[64];
        if(this->objectPtr->GetStartPtr())
        {
            swprintf((wchar_t*)buf, L"%.10g", objectPtr->GetStartX());
            SetWindowTextW(x0_input, buf);
            swprintf((wchar_t*)buf, L"%.10g", objectPtr->GetStartY());
            SetWindowTextW(y0_input, buf);
            swprintf((wchar_t*)buf, L"%.10g", objectPtr->GetStartZ());
            SetWindowTextW(z0_input, buf);
        }
        else
        {
            swprintf((wchar_t*)buf, L"nullptr");
            SetWindowTextW(x0_input, buf);
            swprintf((wchar_t*)buf, L"nullptr");
            SetWindowTextW(y0_input, buf);
            swprintf((wchar_t*)buf, L"nullptr");
            SetWindowTextW(z0_input, buf);
        }
        SetWindowSubclass(this->x0_input, Redactor::Windows::SubclassesProc::DoubleEditSubclassProc, 1, 0);
        SetWindowSubclass(this->y0_input, Redactor::Windows::SubclassesProc::DoubleEditSubclassProc, 1, 0);
        SetWindowSubclass(this->z0_input, Redactor::Windows::SubclassesProc::DoubleEditSubclassProc, 1, 0);

        if(this->objectPtr->GetEndPtr())
        {
            swprintf((wchar_t*)buf, L"%.10g", objectPtr->GetEndX());
            SetWindowTextW(x1_input, buf);
            swprintf((wchar_t*)buf, L"%.10g", objectPtr->GetEndY());
            SetWindowTextW(y1_input, buf);
            swprintf((wchar_t*)buf, L"%.10g", objectPtr->GetEndZ());
            SetWindowTextW(z1_input, buf);
        }
        else
        {
            swprintf((wchar_t*)buf, L"nullptr");
            SetWindowTextW(x1_input, buf);
            swprintf((wchar_t*)buf, L"nullptr");
            SetWindowTextW(y1_input, buf);
            swprintf((wchar_t*)buf, L"nullptr");
            SetWindowTextW(z1_input, buf);
        }

        SetWindowSubclass(this->x1_input, Redactor::Windows::SubclassesProc::DoubleEditSubclassProc, 1, 0);
        SetWindowSubclass(this->y1_input, Redactor::Windows::SubclassesProc::DoubleEditSubclassProc, 1, 0);
        SetWindowSubclass(this->z1_input, Redactor::Windows::SubclassesProc::DoubleEditSubclassProc, 1, 0);
    }

    if(hwnd)
        this->isCreated = true;
    else
        throw std::runtime_error("Неизвестная ошибка создания окна");
    return this->isCreated;
}

