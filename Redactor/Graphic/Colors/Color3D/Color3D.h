#ifndef __COLOR_3_DOUBLE_H__
#define __COLOR_3_DOUBLE_H__

namespace Redactor
{

namespace Graphic
{

namespace Colors
{
    class Color3D
    {
    public:
        Color3D(void);
        Color3D(double r, double g, double b);
        Color3D(double par);

        Color3D(const Color3D& other);
        Color3D(Color3D&& other) noexcept;
        Color3D& operator=(const Color3D& other);
        Color3D& operator=(Color3D&& other) noexcept;
        ~Color3D(void);

        double GetR(void) const;
        double GetG(void) const;
        double GetB(void) const;

        void SetR(double r);
        void SetG(double g);
        void SetB(double b);

        Color3D& operator+=(const Color3D& other);
        Color3D& operator-=(const Color3D& other);
        Color3D& operator/=(double num);
        Color3D& operator*=(double num);
        Color3D operator-() const;

        friend Color3D operator+(Color3D left, const Color3D& right);
        friend Color3D operator-(Color3D left, const Color3D& right);
        friend Color3D operator/(Color3D left, double right);
        friend Color3D operator*(Color3D left, double right);
        friend Color3D operator*(double left, Color3D right);

    protected:
        double r;
        double g;
        double b;
    };
}

}

}

#endif // __COLOR_3_DOUBLE_H__
