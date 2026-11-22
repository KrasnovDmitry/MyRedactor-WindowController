#include "DoubleEditSubclassProc.h"
#include <cwchar>
#include <string>

bool IsAllowed(wchar_t ch)
{
    if( (ch >= '0' && ch <= '9') || ch == '.' || ch == '-' || ch == '+')
        return true;
    return false;
}

bool IsOnlyOnePoint(const std::wstring& text)
{
    bool result = true;
    unsigned short int times = 0;
    for(unsigned int i = 0; i < text.size() && result; i++)
    {
        if(text[i] == '.')
        {
            times++;
            if(times > 1)
                result = false;
        }
    }
    return result;
}

bool SignOnlyAtStart(const std::wstring& text)
{
    if(text.size() < 2)
        return true;
    bool result = true;
    for(unsigned int i = 1; i < text.size() && result; i++)
    {
        if(text[i] == '-' || text[i] == '+')
            result = false;
    }
    return result;
}

bool IsTextValid(const std::wstring& text)
{
    return IsOnlyOnePoint(text) && SignOnlyAtStart(text);
}


LRESULT CALLBACK Redactor::Windows::SubclassesProc::DoubleEditSubclassProc(HWND hWnd,
                                                                           UINT uMsg,
                                                                           WPARAM wParam,
                                                                           LPARAM lParam,
                                                                           UINT_PTR uIdSubclass,
                                                                           DWORD_PTR dwRefData)
{
    switch (uMsg)
    {
    case WM_CHAR:
    {
        wchar_t ch = static_cast<wchar_t>(wParam);

        if (ch < 32 || ch == 127) break;

        if (!IsAllowed(ch)) return 0;

        // Виртуальная проверка: текущий текст + новый символ
        int len = GetWindowTextLengthW(hWnd);
        std::wstring text(len, L'\0');
        if (len > 0) GetWindowTextW(hWnd, &text[0], len + 1);

        DWORD selStart = 0, selEnd = 0;
        SendMessageW(hWnd, EM_GETSEL,
                     reinterpret_cast<WPARAM>(&selStart),
                     reinterpret_cast<LPARAM>(&selEnd));

        std::wstring candidate =
            text.substr(0, selStart) + ch + text.substr(selEnd);

        if (!IsTextValid(candidate)) return 0;  // блокируем
        break;
    }


    case WM_NCDESTROY:
        RemoveWindowSubclass(hWnd, Redactor::Windows::SubclassesProc::DoubleEditSubclassProc, uIdSubclass);
        break;
    }

    return DefSubclassProc(hWnd, uMsg, wParam, lParam);
}
