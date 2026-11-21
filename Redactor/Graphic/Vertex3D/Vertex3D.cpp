#include "Vertex3D.h"
#include <stdexcept>

namespace G = Redactor::Graphic;

G::Vertex3D::Vertex3D(void): x(0.0), y(0.0), z(0.0) {}

G::Vertex3D::Vertex3D(double x, double y, double z): x(x), y(y), z(z) {}

G::Vertex3D::Vertex3D(const G::Vertex3D& other): x(other.x), y(other.y), z(other.z) {}

G::Vertex3D::Vertex3D(G::Vertex3D&& other) noexcept: x(other.x), y(other.y), z(other.z)
{
    other.x = 0;
    other.y = 0;
    other.z = 0;
}

G::Vertex3D& G::Vertex3D::operator=(const G::Vertex3D& other)
{
    if(this != &other)
    {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
    }
    return *this;
}

G::Vertex3D& G::Vertex3D::operator=(G::Vertex3D&& other) noexcept
{
    if(this != &other)
    {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;

        other.x = 0;
        other.y = 0;
        other.z = 0;
    }
    return *this;
}

G::Vertex3D::~Vertex3D(void)
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

double G::Vertex3D::GetX(void) const
{
    return this->x;
}

double G::Vertex3D::GetY(void) const
{
    return this->y;
}

double G::Vertex3D::GetZ(void) const
{
    return this->z;
}

void G::Vertex3D::SetX(double x)
{
    this->x = x;
}

void G::Vertex3D::SetY(double y)
{
    this->y = y;
}

void G::Vertex3D::SetZ(double z)
{
    this->z = z;
}

G::Vertex3D& G::Vertex3D::operator+=(const G::Vertex3D& other)
{
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return *this;
}

G::Vertex3D& G::Vertex3D::operator-=(const G::Vertex3D& other)
{
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return *this;
}

G::Vertex3D& G::Vertex3D::operator/=(double num)
{
    if(num == 0.0)
        throw std::domain_error("Vertex3D::operator/=: division by zero");
    this->x /= num;
    this->y /= num;
    this->z /= num;
    return *this;
}

G::Vertex3D& G::Vertex3D::operator*=(double num)
{
    this->x *= num;
    this->y *= num;
    this->z *= num;
    return *this;
}

G::Vertex3D G::Vertex3D::operator-() const
{
    G::Vertex3D result = G::Vertex3D(-this->x, -this->y, -this->z);
    return result;
}

G::Vertex3D operator+(G::Vertex3D left, const G::Vertex3D& right)
{
    left += right;
    return left;
}

G::Vertex3D operator-(G::Vertex3D left, const G::Vertex3D& right)
{
    left -= right;
    return left;
}

G::Vertex3D operator/(G::Vertex3D left, double right)
{
    if(right == 0.0)
        throw std::domain_error("operator/: division by zero");
    left /= right;
    return left;
}

G::Vertex3D operator*(G::Vertex3D left, double right)
{
    left *= right;
    return left;
}

G::Vertex3D operator*(double left, G::Vertex3D right)
{
    right *= left;
    return right;
}
