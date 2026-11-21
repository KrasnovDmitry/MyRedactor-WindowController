#ifndef __COLOR_4_BYTE_H__
#define __COLOR_4_BYTE_H__

#include "../Color3B/Color3B.h"

namespace Redactor
{

namespace Graphic
{

namespace Colors
{
    class Color4B
    {
    public:
        Color4B(void);
        Color4B(BYTE r, BYTE g, BYTE b, BYTE a = 255);
        Color4B(BYTE par);

        Color4B(const Color4B& other);
        Color4B(const Color3B& color3B, BYTE a = 255);

        Color4B(Color4B&& other) noexcept;
        Color4B(Color3B&& color3B, BYTE a = 255);

        Color4B& operator=(const Color4B& other);
        Color4B& operator=(const Color3B& other);

        Color4B& operator=(Color4B&& other) noexcept;
        Color4B& operator=(Color3B&& other) noexcept;
        ~Color4B(void);

        BYTE GetR(void) const;
        BYTE GetG(void) const;
        BYTE GetB(void) const;
        BYTE GetA(void) const;

        void SetR(BYTE r);
        void SetG(BYTE g);
        void SetB(BYTE b);
        void SetA(BYTE a);

        explicit operator Color3B() const;

        Color4B& operator+=(const Color4B& other);
        Color4B& operator+=(const Color3B& other);
        Color4B& operator-=(const Color4B& other);
        Color4B& operator-=(const Color3B& other);
        Color4B& operator/=(double num);
        Color4B& operator*=(double num);
        Color4B operator-() const;

        friend Color4B operator+(Color4B left, const Color4B& right);
        friend Color4B operator+(Color4B left, const Color3B& right);
        friend Color4B operator+(const Color3B& left, Color4B right);

        friend Color4B operator-(Color4B left, const Color4B& right);
        friend Color4B operator-(Color4B left, const Color3B& right);

        friend Color4B operator/(Color4B left, double right);
        friend Color4B operator*(Color4B left, double right);
        friend Color4B operator*(double left, Color4B right);

    protected:
        BYTE r;
        BYTE g;
        BYTE b;
        BYTE a;
    };
}

}

}

#endif // __COLOR_4_BYTE_H__

