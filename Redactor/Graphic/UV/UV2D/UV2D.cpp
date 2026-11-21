#include "UV2D.h"
#include <stdexcept>

namespace G = Redactor::Graphic::UVs;

G::UV2D::UV2D(void): u(0.0), v(0.0) {}

G::UV2D::UV2D(double u, double v): u(u), v(v) {}

G::UV2D::UV2D(const G::UV2D& other): u(other.u), v(other.v) {}

G::UV2D::UV2D(G::UV2D&& other) noexcept
{
    this->u = other.u;
    this->v = other.v;

    other.u = 0;
    other.v = 0;
}

G::UV2D& G::UV2D::operator=(const G::UV2D& other)
{
    if(this != &other)
    {
        this->u = other.u;
        this->v = other.v;
    }
    return *this;
}

G::UV2D& G::UV2D::operator=(UV2D&& other) noexcept
{
    if(this != &other)
    {
        this->u = other.u;
        this->v = other.v;

        other.u = 0;
        other.v = 0;
    }
    return *this;
}

G::UV2D::~UV2D(void)
{
    this->u = 0;
    this->v = 0;
}

double G::UV2D::GetU(void) const
{
    return this->u;
}

double G::UV2D::GetV(void) const
{
    return this->v;
}

void G::UV2D::SetU(double u)
{
    this->u = u;
}

void G::UV2D::SetV(double v)
{
    this->v = v;
}

G::UV2D& G::UV2D::operator+=(const G::UV2D& other)
{
    this->u += other.u;
    this->v += other.v;
    return *this;
}

G::UV2D& G::UV2D::operator-=(const G::UV2D& other)
{
    this->u -= other.u;
    this->v -= other.v;
    return *this;
}

G::UV2D& G::UV2D::operator*=(double num)
{
    this->u *= num;
    this->v *= num;
    return *this;
}

G::UV2D& G::UV2D::operator/=(double num)
{
    if(num == 0.0)
        throw std::domain_error("operator/=: division by 0");
    this->u /= num;
    this->v /= num;
    return *this;
}

G::UV2D G::UV2D::operator-() const
{
    return G::UV2D(-this->u, -this->v);
}

G::UV2D operator+(G::UV2D left, const G::UV2D& right)
{
    left += right;
    return left;
}

G::UV2D operator-(G::UV2D left, const G::UV2D& right)
{
    left -= right;
    return left;
}

G::UV2D operator/(G::UV2D left, double right)
{
    left /= right;
    return left;
}

G::UV2D operator*(G::UV2D left, double right)
{
    left *= right;
    return left;
}

G::UV2D operator*(double left, G::UV2D right)
{
    right *= left;
    return right;
}
