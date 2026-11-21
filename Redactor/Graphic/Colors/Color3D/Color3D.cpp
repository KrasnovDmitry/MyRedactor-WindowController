#include "Color3D.h"
#include <stdexcept>

namespace G = Redactor::Graphic::Colors;

G::Color3D::Color3D(void): r(0.0), g(0.0), b(0.0) {}

G::Color3D::Color3D(double r, double g, double b)
{
    if(r < 0 || r > 1)
        throw std::domain_error("Color3D Red parameter out of range (r < 0 or r > 1): domain error");
    if(g < 0 || g > 1)
        throw std::domain_error("Color3D Green parameter out of range (g < 0 or g > 1): domain error");
    if(b < 0 || b > 1)
        throw std::domain_error("Color3D Blue parameter out of range (b < 0 or b > 1): domain error");
    this->r = r;
    this->g = g;
    this->b = b;
}

G::Color3D::Color3D(double par)
{
    if(par < 0 || par > 1)
        throw std::domain_error("Color3D Red, Green and Blue parameters out of range (par < 0 or par > 1): domain error");
    this->r = par;
    this->g = par;
    this->b = par;
}

G::Color3D::Color3D(const G::Color3D& other)
{
    this->r = other.r;
    this->g = other.g;
    this->b = other.b;
}

G::Color3D::Color3D(G::Color3D&& other) noexcept
{
    this->r = other.r;
    this->g = other.g;
    this->b = other.b;

    other.r = 0;
    other.g = 0;
    other.b = 0;
}

G::Color3D& G::Color3D::operator=(const G::Color3D& other)
{
    if(this != &other)
    {
        this->r = other.r;
        this->g = other.g;
        this->b = other.b;
    }
    return *this;
}

G::Color3D& G::Color3D::operator=(G::Color3D&& other) noexcept
{
    if(this != &other)
    {
        this->r = other.r;
        this->g = other.g;
        this->b = other.b;

        other.r = 0;
        other.g = 0;
        other.b = 0;;
    }
    return *this;
}

G::Color3D::~Color3D(void)
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

double G::Color3D::GetR(void) const
{
    return this->r;
}

double G::Color3D::GetG(void) const
{
    return this->g;
}

double G::Color3D::GetB(void) const
{
    return this->b;
}

void G::Color3D::SetR(double a)
{
    if(a < 0 || a > 1)
        throw std::domain_error("SetR: parameter should be between 0 and 1: domain error");
    this->r = a;
}

void G::Color3D::SetG(double a)
{
    if(a < 0 || a > 1)
        throw std::domain_error("SetG: parameter should be between 0 and 1: domain error");
    this->g = a;
}

void G::Color3D::SetB(double a)
{
    if(a < 0 || a > 1)
        throw std::domain_error("SetB: parameter should be between 0 and 1: domain error");
    this->b = a;
}

G::Color3D& G::Color3D::operator+=(const G::Color3D& other)
{
    this->r += other.GetR();
    this->g += other.g;
    this->b += other.b;

    if(this->r > 1)
        this->r = 1;
    if(this->g > 1)
        this->g = 1;
    if(this->b > 1)
        this->b = 1;

    return *this;
}
G::Color3D& G::Color3D::operator-=(const G::Color3D& other)
{
    this->r -= other.GetR();
    this->g -= other.g;
    this->b -= other.b;

    if(this->r < 0)
        this->r = 0;
    if(this->g < 0)
        this->g = 0;
    if(this->b < 0)
        this->b = 0;

    return *this;
}

G::Color3D& G::Color3D::operator/=(double num)
{
    if(num <= 0.0)
        throw std::domain_error("operator/=: division by 0 or less for color");
    this->r /= num;
    this->g /= num;
    this->b /= num;
    return *this;
}

G::Color3D& G::Color3D::operator*=(double num)
{
    if(num < 0)
        throw std::domain_error("operator*=: multiplication by number less than 0 for color");
    this->r *= num;
    this->g *= num;
    this->b *= num;
    return *this;
}

G::Color3D G::Color3D::operator-() const
{
    G::Color3D res = G::Color3D(1 - this->r, 1 - this->g, 1 - this->b);
    return res;
}

G::Color3D operator+(G::Color3D left, const G::Color3D& right)
{
    left += right;
    return left;
}

G::Color3D operator-(G::Color3D left, const G::Color3D& right)
{
    left -= right;
    return left;
}

G::Color3D operator/(G::Color3D left, double right)
{
    left /= right;
    return left;
}

G::Color3D operator*(G::Color3D left, double right)
{
    left *= right;
    return left;
}

G::Color3D operator*(double left, G::Color3D right)
{
    right *= left;
    return right;
}
