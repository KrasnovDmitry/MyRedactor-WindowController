#include "Window.h"
#include <stdexcept>
#include <algorithm>

using namespace Redactor::Windows;

LRESULT CALLBACK SimpleWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

bool Redactor::Windows::RegisterSimpleWindowClass(void)
{
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.lpfnWndProc = SimpleWindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = GetModuleHandle(nullptr);
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = SIMPLE_WINDOW_CLASS;
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    return RegisterClassEx(&wcex);
}

LRESULT CALLBACK SimpleWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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

Window::Window(LPCSTR title, DWORD style, int x, int y, int width, int height, Window* parentWindow, HMENU id, LPVOID data)
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
    this->data = data;
    this->childs.clear();
}

Window::Window(void): Window("SimpleWindow")
{

}

HWND Window::GetHWND(void) const
{
    return this->hwnd;
}

bool Window::IsCreated(void) const
{
    return this->isCreated;
}

LPCSTR Window::GetTitle(void) const
{
    return this->title;
}

void Window::SetTitle(LPCSTR title)
{
    if(this->IsCreated())
        throw std::logic_error("Нельзя изменить заголовок уже созданного окна (post-creation read-only violation)");
    else
        this->title = title;
}

DWORD Window::GetStyle(void) const
{
    return this->style;
}

void Window::SetStyle(DWORD style)
{
    if(this->IsCreated())
        throw std::logic_error("Нельзя изменить стиль уже созданного окна (post-creation read-only violation)");
    else
        this->style = style;
}

int Window::GetX(void) const
{
    return this->x;
}

void Window::SetX(int x)
{
    if(this->IsCreated())
        throw std::logic_error("Нельзя изменить положение по x уже созданного окна (post-creation read-only violation)");
    else
        this->x = x;
}

int Window::GetY(void) const
{
    return this->y;
}

void Window::SetY(int y)
{
    if(this->IsCreated())
        throw std::logic_error("Нельзя изменить положение по y уже созданного окна (post-creation read-only violation)");
    else
        this->y = y;
}

int Window::GetWidth(void) const
{
    return this->width;
}

void Window::SetWidth(int width)
{
    if(this->IsCreated())
        throw std::logic_error("Нельзя изменить ширину уже созданного простого окна (попробуйте использовать класс c инкапсуляцией IHasOnSizeHook) (post-creation read-only violation)");
    else
        this->width = width;
}

int Window::GetHeight(void) const
{
    return this->height;
}

void Window::SetHeight(int height)
{
    if(this->IsCreated())
        throw std::logic_error("Нельзя изменить высоту уже созданного простого окна (попробуйте использовать класс c инкапсуляцией IHasOnSizeHook) (post-creation read-only violation)");
    else
        this->height = height;
}

Window* Window::GetParentWindow(void) const
{
    return this->parentWindow;
}

void Window::SetParentWindow(Window* parentWindow)
{
    if(this->IsCreated())
        throw std::logic_error("Нельзя сделать окно дочерним после его создания (post-creation read-only violation)");
    else
        this->parentWindow = parentWindow;
}

HMENU Window::GetId(void) const
{
    return this->id;
}

void Window::SetId(HMENU id)
{
    if(this->IsCreated())
        throw std::logic_error("Нельзя изменять идентификатор после создания окна (post-creation read-only violation)");
    else
        this->id = id;
}

LPVOID Window::GetDataPtr(void) const
{
    return this->data;
}

void Window::SetDataPtr(LPVOID data)
{
    if(this->IsCreated())
        throw std::logic_error("Нельзя изменять указатель на привязанные данные после создания окна (post-creation read-only violation)");
    else
        this->data= data;
}

bool Window::Create(void)
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
                                SIMPLE_WINDOW_CLASS,
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
    if(hwnd)
        this->isCreated = true;
    else
        throw std::runtime_error("Неизвестная ошибка создания окна");
    return this->isCreated;
}

void Window::Show(int nCmdShow)
{
    if(!this->IsCreated())
        throw std::logic_error("Невозможно показать несозданное окно (show before creation)");
    else
        ShowWindow(this->hwnd, nCmdShow);
}

void Window::Hide(void)
{
    if(!this->IsCreated())
        throw std::logic_error("Невозможно спрятать несозданное окно (hide before creation)");
    else
        ShowWindow(this->hwnd, SW_HIDE);
}

void Window::Destroy(void)
{
    if(this->IsCreated())
    {
        DestroyWindow(this->hwnd);
        this->isCreated = false;
    }
}

void Window::AddChildWindow(Window* window)
{
    if(window->IsCreated())
        throw std::logic_error("Невозможно назначить окно дочерним, если оно уже создано");

    this->childs.push_back(window);
    window->SetParentWindow(this);
}

void Window::RemoveChildWindow(Window* window)
{
    if(window->IsCreated())
        throw std::logic_error("Невозможно назначить окно не дочерним (отвязать), если оно уже создано. Сначала уничтожте окно");
    this->childs.erase(std::remove(this->childs.begin(), this->childs.end(), window), this->childs.end());
    window->SetParentWindow(nullptr);
}

void Window::ClearChildWindows(void)
{

    for(size_t i = 0; i < this->childs.size(); i++)
    {
        if(this->childs[i]->IsCreated())
            throw std::logic_error("Невозможно назначить окно не дочерним (отвязать), если оно уже создано. Сначала уничтожте окно");
    }
    for(size_t i = 0; i < this->childs.size(); i++)
    {
        this->childs[i]->SetParentWindow(nullptr);
    }
    this->childs.clear();
}

Window::~Window(void)
{
    if(this->IsCreated())
        this->Destroy();
    this->ClearChildWindows();
}
