#ifndef __COLOR_4_DOUBLE_H__
#define __COLOR_4_DOUBLE_H__

#include "../Color3D/Color3D.h"

namespace Redactor
{

namespace Graphic
{

namespace Colors
{
    class Color4D
    {
    public:
        Color4D(void);
        Color4D(double r, double g, double b, double a = 1.0);
        Color4D(double par);

        Color4D(const Color4D& other);
        Color4D(const Color3D& color3D, double a = 1.0);

        Color4D(Color4D&& other) noexcept;
        Color4D(Color3D&& color3D, double a = 1.0);

        Color4D& operator=(const Color4D& other);
        Color4D& operator=(const Color3D& other);

        Color4D& operator=(Color4D&& other) noexcept;
        Color4D& operator=(Color3D&& other) noexcept;
        ~Color4D(void);

        double GetR(void) const;
        double GetG(void) const;
        double GetB(void) const;
        double GetA(void) const;

        void SetR(double r);
        void SetG(double g);
        void SetB(double b);
        void SetA(double a);

        explicit operator Color3D() const;

        Color4D& operator+=(const Color4D& other);
        Color4D& operator+=(const Color3D& other);
        Color4D& operator-=(const Color4D& other);
        Color4D& operator-=(const Color3D& other);
        Color4D& operator/=(double num);
        Color4D& operator*=(double num);
        Color4D operator-() const;

        friend Color4D operator+(Color4D left, const Color4D& right);
        friend Color4D operator+(Color4D left, const Color3D& right);
        friend Color4D operator+(const Color3D& left, Color4D right);

        friend Color4D operator-(Color4D left, const Color4D& right);
        friend Color4D operator-(Color4D left, const Color3D& right);

        friend Color4D operator/(Color4D left, double right);
        friend Color4D operator*(Color4D left, double right);
        friend Color4D operator*(double left, Color4D right);

    protected:
        double r;
        double g;
        double b;
        double a;
    };
}

}

}

#endif // __COLOR_4_DOUBLE_H__
