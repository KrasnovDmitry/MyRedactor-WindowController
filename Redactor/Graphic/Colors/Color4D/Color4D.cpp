#include "Color4D.h"
#include <stdexcept>

namespace G = Redactor::Graphic::Colors;

G::Color4D::Color4D(void): r(0.0), g(0.0), b(0.0), a(1.0) {}

G::Color4D::Color4D(double r, double g, double b, double a)
{
    if(r < 0 || r > 1)
        throw std::domain_error("Color4D Red parameter out of range (r < 0 or r > 1): domain error");
    if(g < 0 || g > 1)
        throw std::domain_error("Color4D Green parameter out of range (g < 0 or g > 1): domain error");
    if(b < 0 || b > 1)
        throw std::domain_error("Color4D Blue parameter out of range (b < 0 or b > 1): domain error");
    if(a < 0 || a > 1)
        throw std::domain_error("Color4D Alpha parameter out of range (a < 0 or a > 1): domain error");

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

G::Color4D::Color4D(double par)
{
    if(par < 0 || par > 1)
        throw std::domain_error("Color3D Red, Green and Blue parameters out of range (par < 0 or par > 1): domain error");
    this->r = par;
    this->g = par;
    this->b = par;
    this->a = 1.0;
}

G::Color4D::Color4D(const Color4D& other)
{
    this->r = other.r;
    this->g = other.g;
    this->b = other.b;
    this->a = other.a;
}

G::Color4D::Color4D(const G::Color3D& other, double a)
{
    if(a < 0 || a > 1)
        throw std::domain_error("Color4D Alpha parameter out of range (a < 0 or a > 1): domain error");
    this->r = other.GetR();
    this->g = other.GetG();
    this->b = other.GetB();
    this->a = a;
}

G::Color4D::Color4D(G::Color4D&& other) noexcept
{
    this->r = other.r;
    this->g = other.g;
    this->b = other.b;
    this->a = other.a;

    other.r = 0;
    other.g = 0;
    other.b = 0;
    other.a = 0;
}

G::Color4D::Color4D(G::Color3D&& other, double a)
{
    if(a < 0 || a > 1)
        throw std::domain_error("Color4D Alpha parameter out of range (a < 0 or a > 1): domain error");
    this->r = other.GetR();
    this->g = other.GetG();
    this->b = other.GetB();
    this->a = a;

    other.SetR(0);
    other.SetG(0);
    other.SetB(0);
}

G::Color4D& G::Color4D::operator=(const G::Color4D& other)
{
    if(this != &other)
    {
        this->r = other.r;
        this->g = other.g;
        this->b = other.b;
        this->a = other.a;
    }
    return *this;
}

G::Color4D& G::Color4D::operator=(const Color3D& other)
{
    this->r = other.GetR();
    this->g = other.GetG();
    this->b = other.GetB();
    return *this;
}

G::Color4D& G::Color4D::operator=(G::Color4D&& other) noexcept
{
    if(this != &other)
    {
        this->r = other.r;
        this->g = other.g;
        this->b = other.b;
        this->a = other.a;

        other.r = 0;
        other.g = 0;
        other.b = 0;
        other.a = 0;
    }
    return *this;
}

G::Color4D& G::Color4D::operator=(G::Color3D&& other) noexcept
{
    this->r = other.GetR();
    this->g = other.GetG();
    this->b = other.GetB();

    other.SetR(0);
    other.SetG(0);
    other.SetB(0);

    return *this;
}

G::Color4D::~Color4D(void)
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 0;
}

double G::Color4D::GetR(void) const
{
    return this->r;
}

double G::Color4D::GetG(void) const
{
    return this->g;
}

double G::Color4D::GetB(void) const
{
    return this->b;
}

double G::Color4D::GetA(void) const
{
    return this->a;
}

void G::Color4D::SetR(double a)
{
    if(a < 0 || a > 1)
        throw std::domain_error("SetR: parameter should be between 0 and 1: domain error");
    this->r = a;
}

void G::Color4D::SetG(double a)
{
    if(a < 0 || a > 1)
        throw std::domain_error("SetG: parameter should be between 0 and 1: domain error");
    this->g = a;
}

void G::Color4D::SetB(double a)
{
    if(a < 0 || a > 1)
        throw std::domain_error("SetB: parameter should be between 0 and 1: domain error");
    this->b = a;
}

void G::Color4D::SetA(double a)
{
    if(a < 0 || a > 1)
        throw std::domain_error("SetA: parameter should be between 0 and 1: domain error");
    this->a = a;
}

G::Color4D::operator G::Color3D() const
{
    return G::Color3D(this->r, this->g, this->b);
}

G::Color4D& G::Color4D::operator+=(const G::Color4D& other)
{
    this->r += other.r;
    this->g += other.g;
    this->b += other.b;
    this->a += other.a;

    if(this->r > 1)
        this->r = 1;
    if(this->g > 1)
        this->g = 1;
    if(this->b > 1)
        this->b = 1;
    if(this->a > 1)
        this->a = 1;

    return *this;
}

G::Color4D& G::Color4D::operator+=(const G::Color3D& other)
{
    this->r += other.GetR();
    this->g += other.GetG();
    this->b += other.GetB();

    if(this->r > 1)
        this->r = 1;
    if(this->g > 1)
        this->g = 1;
    if(this->b > 1)
        this->b = 1;

    return *this;
}

G::Color4D& G::Color4D::operator-=(const G::Color4D& other)
{
    this->r -= other.r;
    this->g -= other.g;
    this->b -= other.b;
    this->a -= other.a;

    if(this->r < 0)
        this->r = 0;
    if(this->g < 0)
        this->g = 0;
    if(this->b < 0)
        this->b = 0;
    if(this->a < 0)
        this->a = 0;

    return *this;
}

G::Color4D& G::Color4D::operator-=(const G::Color3D& other)
{
    this->r -= other.GetR();
    this->g -= other.GetG();
    this->b -= other.GetB();

    if(this->r < 0)
        this->r = 0;
    if(this->g < 0)
        this->g = 0;
    if(this->b < 0)
        this->b = 0;

    return *this;
}

G::Color4D& G::Color4D::operator/=(double num)
{
    if(num <= 0.0)
        throw std::domain_error("operator/=: division by 0 or less for color");
    this->r /= num;
    this->g /= num;
    this->b /= num;
    this->a /= num;
    return *this;
}

G::Color4D& G::Color4D::operator*=(double num)
{
    if(num < 0)
        throw std::domain_error("operator*=: multiplication by number less than 0 for color");
    this->r *= num;
    this->g *= num;
    this->b *= num;
    this->a *= num;
    return *this;
}

G::Color4D G::Color4D::operator-() const
{
    return G::Color4D(1 - this->r, 1 - this->g, 1 - this-> b, 1 - this->a);
}

G::Color4D operator+(G::Color4D left, const G::Color4D& right)
{
    left += right;
    return left;
}

G::Color4D operator+(G::Color4D left, const G::Color3D& right)
{
    left += right;
    return left;
}

G::Color4D operator+(const G::Color3D& left, G::Color4D right)
{
    right += left;
    return right;
}

G::Color4D operator-(G::Color4D left, const G::Color4D& right)
{
    left -= right;
    return left;
}

G::Color4D operator-(G::Color4D left, const G::Color3D& right)
{
    left -= right;
    return left;
}

G::Color4D operator/(G::Color4D left, double right)
{
    left /= right;
    return left;
}

G::Color4D operator*(G::Color4D left, double right)
{
    left *= right;
    return left;
}

G::Color4D operator*(double left, G::Color4D right)
{
    right *= left;
    return right;
}
