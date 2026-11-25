#include "Face3D.h"

Redactor::Graphic::Face::Face(void): Redactor::Graphic::Face(0) {}

Redactor::Graphic::Face::Face(HalfEdgeId id)
{
    this->half_edge_id = id;
}

Redactor::Graphic::Face::Face(const Redactor::Graphic::Face& other)
{
    this->half_edge_id = other.half_edge_id;
}

Redactor::Graphic::Face::Face(Redactor::Graphic::Face&& other) noexcept
{
    this->half_edge_id = other.half_edge_id;
    other.half_edge_id = 0;
}

Redactor::Graphic::Face& Redactor::Graphic::Face::operator=(const Redactor::Graphic::Face& other)
{
    if(this != &other)
    {
        this->half_edge_id = other.half_edge_id;
    }
    return *this;
}

Redactor::Graphic::Face& Redactor::Graphic::Face::operator=(Redactor::Graphic::Face&& other) noexcept
{
    if(this != &other)
    {
        this->half_edge_id = other.half_edge_id;
        other.half_edge_id = 0;
    }
    return *this;
}

Redactor::Graphic::Face::~Face(void)
{
    this->half_edge_id = 0;
}

void Redactor::Graphic::Face::SetHalfEdgeId(HalfEdgeId id)
{
    this->half_edge_id = id;
}

HalfEdgeId Redactor::Graphic::Face::GetHalfEdgeId(void) const
{
    return this->half_edge_id;
}
