#include "HalfEdge3D.h"

Redactor::Graphic::HalfEdge::HalfEdge(void): Redactor::Graphic::HalfEdge(0) {}

Redactor::Graphic::HalfEdge::HalfEdge(VertexId vertex_id, HalfEdgeId next_id, HalfEdgeId prev_id, HalfEdgeId twin_id, FaceId face_id)
{
    this->vertex_id = vertex_id;
    this->prev_id = prev_id;
    this->next_id = next_id;
    this->twin_id = twin_id;
    this->face_id = face_id;
}

Redactor::Graphic::HalfEdge::HalfEdge(const Redactor::Graphic::HalfEdge& other)
{
    this->vertex_id = other.vertex_id;
    this->prev_id = other.prev_id;
    this->next_id = other.next_id;
    this->twin_id = other.twin_id;
    this->face_id = other.face_id;
}

Redactor::Graphic::HalfEdge::HalfEdge(Redactor::Graphic::HalfEdge&& other) noexcept
{
    this->vertex_id = other.vertex_id;
    this->prev_id = other.prev_id;
    this->next_id = other.next_id;
    this->twin_id = other.twin_id;
    this->face_id = other.face_id;

    other.vertex_id = 0;
    other.prev_id = 0;
    other.next_id = 0;
    other.twin_id = 0;
    other.face_id = 0;
}

Redactor::Graphic::HalfEdge& Redactor::Graphic::HalfEdge::operator=(const Redactor::Graphic::HalfEdge& other)
{
    if(this != &other)
    {
        this->vertex_id = other.vertex_id;
        this->prev_id = other.prev_id;
        this->next_id = other.next_id;
        this->twin_id = other.twin_id;
        this->face_id = other.face_id;
    }
    return *this;
}

Redactor::Graphic::HalfEdge& Redactor::Graphic::HalfEdge::operator=(Redactor::Graphic::HalfEdge&& other) noexcept
{
    if(this != &other)
    {
        this->vertex_id = other.vertex_id;
        this->prev_id = other.prev_id;
        this->next_id = other.next_id;
        this->twin_id = other.twin_id;
        this->face_id = other.face_id;

        other.vertex_id = 0;
        other.prev_id = 0;
        other.next_id = 0;
        other.twin_id = 0;
        other.face_id = 0;
    }
    return *this;
}

Redactor::Graphic::HalfEdge::~HalfEdge(void)
{
    this->vertex_id = 0;
    this->prev_id = 0;
    this->next_id = 0;
    this->twin_id = 0;
    this->face_id = 0;
}

void Redactor::Graphic::HalfEdge::SetVertexId(VertexId id)
{
    this->vertex_id = id;
}

void Redactor::Graphic::HalfEdge::SetNextHalfEdgeId(HalfEdgeId id)
{
    this->next_id = id;
}

void Redactor::Graphic::HalfEdge::SetPrevHalfEdgeId(HalfEdgeId id)
{
    this->prev_id = id;
}

void Redactor::Graphic::HalfEdge::SetTwinHalfEdgeId(HalfEdgeId id)
{
    this->twin_id = id;
}

void Redactor::Graphic::HalfEdge::SetFaceId(FaceId id)
{
    this->face_id = id;
}

VertexId Redactor::Graphic::HalfEdge::GetVertexId(void) const
{
    return this->vertex_id;
}

HalfEdgeId Redactor::Graphic::HalfEdge::GetNextHalfEdgeId(void) const
{
    return this->next_id;
}

HalfEdgeId Redactor::Graphic::HalfEdge::GetPrevHalfEdgeId(void) const
{
    return this->prev_id;
}

HalfEdgeId Redactor::Graphic::HalfEdge::GetTwinHalfEdgeId(void) const
{
    return this->twin_id;
}

FaceId Redactor::Graphic::HalfEdge::GetFaceId(void) const
{
    return this->face_id;
}
