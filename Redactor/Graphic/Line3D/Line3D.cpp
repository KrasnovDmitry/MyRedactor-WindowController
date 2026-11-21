#include "Line3D.h"

namespace G = Redactor::Graphic;

G::Line3D::Line3D(void)
{
    this->start = G::Vertex3D(0, 0, 0);
    this->end = G::Vertex3D(1, 1, 1);
}

G::Line3D::Line3D(double x1, double y1, double z1, double x2, double y2, double z2)
{
    this->start = G::Vertex3D(x1, y1, z1);
    this->end = G::Vertex3D(x2, y2, z2);
}

G::Line3D::Line3D(Vertex3D vert1, Vertex3D vert2)
{
    this->start = vert1;
    this->end = vert2;
}

G::Line3D::Line3D(const Line3D& other)
{
    this->start = other.start;
    this->end = other.end;
}

G::Line3D::Line3D(Line3D&& other) noexcept
{
    this->start = other.start;
    this->end = other.end;

    other.start = G::Vertex3D(0, 0, 0);
    other.end = G::Vertex3D(0, 0, 0);
}

G::Line3D& G::Line3D::operator=(const G::Line3D& other)
{
    if(this != &other)
    {
        this->start = other.start;
        this->end = other.end;
    }
    return *this;
}

G::Line3D& G::Line3D::operator=(G::Line3D&& other) noexcept
{
    if(this != &other)
    {
        this->start = other.start;
        this->end = other.end;

        other.start = G::Vertex3D(0, 0, 0);
        other.end = G::Vertex3D(0, 0, 0);
    }
    return *this;
}

G::Line3D::~Line3D(void)
{
    this->start = G::Vertex3D(0, 0, 0);
    this->end = G::Vertex3D(0, 0, 0);
}

G::Vertex3D G::Line3D::GetStart(void) const
{
    return this->start;
}

G::Vertex3D G::Line3D::GetEnd(void) const
{
    return this->end;
}

double G::Line3D::GetStartX(void) const
{
    return this->start.GetX();
}

double G::Line3D::GetStartY(void) const
{
    return this->start.GetY();
}

double G::Line3D::GetStartZ(void) const
{
    return this->start.GetZ();
}

double G::Line3D::GetEndX(void) const
{
    return this->end.GetX();
}

double G::Line3D::GetEndY(void) const
{
    return this->end.GetY();
}

double G::Line3D::GetEndZ(void) const
{
    return this->end.GetZ();
}

void G::Line3D::SetStart(G::Vertex3D vert)
{
    this->start = vert;
}

void G::Line3D::SetStart(double x, double y, double z)
{
    this->start = G::Vertex3D(x, y, z);
}

void G::Line3D::SetEnd(G::Vertex3D vert)
{
    this->end = vert;
}

void G::Line3D::SetEnd(double x, double y, double z)
{
    this->end = G::Vertex3D(x, y, z);
}

void G::Line3D::SetStartX(double a)
{
    this->start.SetX(a);
}

void G::Line3D::SetStartY(double a)
{
    this->start.SetY(a);
}

void G::Line3D::SetStartZ(double a)
{
    this->start.SetZ(a);
}

void G::Line3D::SetEndX(double a)
{
    this->end.SetX(a);
}

void G::Line3D::SetEndY(double a)
{
    this->end.SetY(a);
}

void G::Line3D::SetEndZ(double a)
{
    this->end.SetZ(a);
}
