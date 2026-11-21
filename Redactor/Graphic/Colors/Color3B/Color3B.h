#ifndef __COLOR_3_BYTE_H__
#define __COLOR_3_BYTE_H__

#include <windows.h>

namespace Redactor
{

namespace Graphic
{

namespace Colors
{
    class Color3B
    {
    public:
        Color3B(void);
        Color3B(BYTE r, BYTE g, BYTE b);
        Color3B(BYTE par);

        Color3B(const Color3B& other);
        Color3B(Color3B&& other) noexcept;
        Color3B& operator=(const Color3B& other);
        Color3B& operator=(Color3B&& other) noexcept;
        ~Color3B(void);

        BYTE GetR(void) const;
        BYTE GetG(void) const;
        BYTE GetB(void) const;

        void SetR(BYTE r);
        void SetG(BYTE g);
        void SetB(BYTE b);

        Color3B& operator+=(const Color3B& other);
        Color3B& operator-=(const Color3B& other);
        Color3B& operator/=(double num);
        Color3B& operator*=(double num);
        Color3B operator-() const;

        friend Color3B operator+(Color3B left, const Color3B& right);
        friend Color3B operator-(Color3B left, const Color3B& right);
        friend Color3B operator/(Color3B left, double right);
        friend Color3B operator*(Color3B left, double right);
        friend Color3B operator*(double left, Color3B right);

    protected:
        BYTE r;
        BYTE g;
        BYTE b;
    };
}

}

}

#endif // __COLOR_3_BYTE_H__
