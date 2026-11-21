#include "Color4B.h"
#include <stdexcept>

namespace G = Redactor::Graphic::Colors;

G::Color4B::Color4B(void): r(0), g(0), b(0), a(255) {}

G::Color4B::Color4B(BYTE r, BYTE g, BYTE b, BYTE a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

G::Color4B::Color4B(BYTE par)
{
    this->r = par;
    this->g = par;
    this->b = par;
    this->a = 255;
}

G::Color4B::Color4B(const Color4B& other)
{
    this->r = other.r;
    this->g = other.g;
    this->b = other.b;
    this->a = other.a;
}

G::Color4B::Color4B(const G::Color3B& other, BYTE a)
{
    this->r = other.GetR();
    this->g = other.GetG();
    this->b = other.GetB();
    this->a = a;
}

G::Color4B::Color4B(G::Color4B&& other) noexcept
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

G::Color4B::Color4B(G::Color3B&& other, BYTE a)
{
    this->r = other.GetR();
    this->g = other.GetG();
    this->b = other.GetB();
    this->a = a;

    other.SetR(0);
    other.SetG(0);
    other.SetB(0);
}

G::Color4B& G::Color4B::operator=(const G::Color4B& other)
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

G::Color4B& G::Color4B::operator=(const Color3B& other)
{
    this->r = other.GetR();
    this->g = other.GetG();
    this->b = other.GetB();
    return *this;
}

G::Color4B& G::Color4B::operator=(G::Color4B&& other) noexcept
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

G::Color4B& G::Color4B::operator=(G::Color3B&& other) noexcept
{
    this->r = other.GetR();
    this->g = other.GetG();
    this->b = other.GetB();

    other.SetR(0);
    other.SetG(0);
    other.SetB(0);

    return *this;
}

G::Color4B::~Color4B(void)
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->a = 0;
}

BYTE G::Color4B::GetR(void) const
{
    return this->r;
}

BYTE G::Color4B::GetG(void) const
{
    return this->g;
}

BYTE G::Color4B::GetB(void) const
{
    return this->b;
}

BYTE G::Color4B::GetA(void) const
{
    return this->a;
}

void G::Color4B::SetR(BYTE a)
{
    this->r = a;
}

void G::Color4B::SetG(BYTE a)
{
    this->g = a;
}

void G::Color4B::SetB(BYTE a)
{
    this->b = a;
}

void G::Color4B::SetA(BYTE a)
{
    this->a = a;
}

G::Color4B::operator G::Color3B() const
{
    return G::Color3B(this->r, this->g, this->b);
}

G::Color4B& G::Color4B::operator+=(const G::Color4B& other)
{
    if(255 - this->r < other.r)
        this->r = 255;
    else
        this->r += other.r;

    if(255 - this->g < other.g)
        this->g = 255;
    else
        this->g += other.g;

    if(255 - this->b < other.b)
        this->b = 255;
    else
        this->b += other.b;

    if(255 - this->a < other.a)
        this->a = 255;
    else
        this->a += other.a;

    return *this;
}

G::Color4B& G::Color4B::operator+=(const G::Color3B& other)
{
    if(255 - this->r < other.GetR())
        this->r = 255;
    else
        this->r += other.GetR();

    if(255 - this->g < other.GetG())
        this->g = 255;
    else
        this->g += other.GetG();

    if(255 - this->b < other.GetB())
        this->b = 255;
    else
        this->b += other.GetB();

    return *this;
}

G::Color4B& G::Color4B::operator-=(const G::Color4B& other)
{
    if(other.r > this->r)
        this->r = 0;
    else
        this->r -= other.r;

    if(other.g > this->g)
        this->g = 0;
    else
        this->g -= other.g;

    if(other.b > this->b)
        this->b = 0;
    else
        this->b -= other.b;

    if(other.a > this->a)
        this->a = 0;
    else
        this->a -= other.a;

    return *this;
}

G::Color4B& G::Color4B::operator-=(const G::Color3B& other)
{
    if(other.GetR() > this->r)
        this->r = 0;
    else
        this->r -= other.GetR();

    if(other.GetG() > this->g)
        this->g = 0;
    else
        this->g -= other.GetG();

    if(other.GetB() > this->b)
        this->b = 0;
    else
        this->b -= other.GetB();

    return *this;
}

G::Color4B& G::Color4B::operator/=(double num)
{
    if(num <= 0.0)
        throw std::domain_error("operator/=: division by 0 or less for color");
    this->r /= num;
    this->g /= num;
    this->b /= num;
    this->a /= num;
    return *this;
}

G::Color4B& G::Color4B::operator*=(double num)
{
    if(num < 0)
        throw std::domain_error("operator*=: multiplication by number less than 0 for color");
    this->r *= num;
    this->g *= num;
    this->b *= num;
    this->a *= num;
    return *this;
}

G::Color4B G::Color4B::operator-() const
{
    return G::Color4B(255 - this->r, 255 - this->g, 255 - this-> b, 255 - this->a);
}

G::Color4B operator+(G::Color4B left, const G::Color4B& right)
{
    left += right;
    return left;
}

G::Color4B operator+(G::Color4B left, const G::Color3B& right)
{
    left += right;
    return left;
}

G::Color4B operator+(const G::Color3B& left, G::Color4B right)
{
    right += left;
    return right;
}

G::Color4B operator-(G::Color4B left, const G::Color4B& right)
{
    left -= right;
    return left;
}

G::Color4B operator-(G::Color4B left, const G::Color3B& right)
{
    left -= right;
    return left;
}

G::Color4B operator/(G::Color4B left, double right)
{
    left /= right;
    return left;
}

G::Color4B operator*(G::Color4B left, double right)
{
    left *= right;
    return left;
}

G::Color4B operator*(double left, G::Color4B right)
{
    right *= left;
    return right;
}
