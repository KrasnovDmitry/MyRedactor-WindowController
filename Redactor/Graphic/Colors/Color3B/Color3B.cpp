#include "Color3B.h"
#include <stdexcept>

namespace G = Redactor::Graphic::Colors;

G::Color3B::Color3B(void): r(0), g(0), b(0) {}

G::Color3B::Color3B(BYTE r, BYTE g, BYTE b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

G::Color3B::Color3B(BYTE par)
{
    this->r = par;
    this->g = par;
    this->b = par;
}

G::Color3B::Color3B(const G::Color3B& other)
{
    this->r = other.r;
    this->g = other.g;
    this->b = other.b;
}

G::Color3B::Color3B(G::Color3B&& other) noexcept
{
    this->r = other.r;
    this->g = other.g;
    this->b = other.b;

    other.r = 0;
    other.g = 0;
    other.b = 0;
}

G::Color3B& G::Color3B::operator=(const G::Color3B& other)
{
    if(this != &other)
    {
        this->r = other.r;
        this->g = other.g;
        this->b = other.b;
    }
    return *this;
}

G::Color3B& G::Color3B::operator=(G::Color3B&& other) noexcept
{
    if(this != &other)
    {
        this->r = other.r;
        this->g = other.g;
        this->b = other.b;

        other.r = 0;
        other.g = 0;
        other.b = 0;
    }
    return *this;
}

G::Color3B::~Color3B(void)
{
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

BYTE G::Color3B::GetR(void) const
{
    return this->r;
}

BYTE G::Color3B::GetG(void) const
{
    return this->g;
}

BYTE G::Color3B::GetB(void) const
{
    return this->b;
}

void G::Color3B::SetR(BYTE a)
{
    this->r = a;
}

void G::Color3B::SetG(BYTE a)
{
    this->g = a;
}

void G::Color3B::SetB(BYTE a)
{
    this->b = a;
}

//Ебать я крут, защиты от переполнения для BYTE
//Надо не забыть отсосать себе, раз уж я такой ахуенный
G::Color3B& G::Color3B::operator+=(const G::Color3B& other)
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

    return *this;
}
G::Color3B& G::Color3B::operator-=(const G::Color3B& other)
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

    return *this;
}

G::Color3B& G::Color3B::operator/=(double num)
{
    if(num <= 0.0)
        throw std::domain_error("operator/=: division by 0 or less for color");
    this->r /= num;
    this->g /= num;
    this->b /= num;
    return *this;
}

G::Color3B& G::Color3B::operator*=(double num)
{
    if(num < 0)
        throw std::domain_error("operator*=: multiplication by number less than 0 for color");
    this->r *= num;
    this->g *= num;
    this->b *= num;
    return *this;
}

G::Color3B G::Color3B::operator-() const
{
    G::Color3B res = G::Color3B(255 - this->r, 255 - this->g, 255 - this->b);
    return res;
}

G::Color3B operator+(G::Color3B left, const G::Color3B& right)
{
    left += right;
    return left;
}

G::Color3B operator-(G::Color3B left, const G::Color3B& right)
{
    left -= right;
    return left;
}

G::Color3B operator/(G::Color3B left, double right)
{
    left /= right;
    return left;
}

G::Color3B operator*(G::Color3B left, double right)
{
    left *= right;
    return left;
}

G::Color3B operator*(double left, G::Color3B right)
{
    right *= left;
    return right;
}
