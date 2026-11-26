#include "Mesh3D.h"
#include <stdexcept>
#include <iostream>

Redactor::Graphic::Mesh3D::Mesh3D(void)
{
    this->verticies.clear();
    this->halfEdges.clear();
    this->faces.clear();
    this->isOptimized = true;
}

Redactor::Graphic::Mesh3D::Mesh3D(const Redactor::Graphic::Mesh3D& other)
{
    this->verticies = other.verticies;
    this->halfEdges = other.halfEdges;
    this->faces = other.faces;
    this->isOptimized = other.isOptimized;
}

Redactor::Graphic::Mesh3D::Mesh3D(Redactor::Graphic::Mesh3D&& other) noexcept
{
    this->verticies = std::move(other.verticies);
    this->halfEdges = std::move(other.halfEdges);
    this->faces = std::move(other.faces);
    this->isOptimized = other.isOptimized;
}

Redactor::Graphic::Mesh3D& Redactor::Graphic::Mesh3D::operator=(const Redactor::Graphic::Mesh3D& other)
{
    if(this != &other)
    {
        this->verticies = other.verticies;
        this->halfEdges = other.halfEdges;
        this->faces = other.faces;
        this->isOptimized = other.isOptimized;
    }
    return *this;
}

Redactor::Graphic::Mesh3D& Redactor::Graphic::Mesh3D::operator=(Redactor::Graphic::Mesh3D&& other) noexcept
{
    if(this != &other)
    {
        this->verticies = std::move(other.verticies);
        this->halfEdges = std::move(other.halfEdges);
        this->faces = std::move(other.faces);
        this->isOptimized = other.isOptimized;
    }
    return *this;
}

Redactor::Graphic::Mesh3D::~Mesh3D(void)
{
    this->verticies.clear();
    this->halfEdges.clear();
    this->faces.clear();
    this->isOptimized = false;
}

Redactor::Graphic::Vertex3D& Redactor::Graphic::Mesh3D::VertexById(VertexId id)
{
    if(id-1 < this->verticies.size())
        return this->verticies[id-1];
    else
        throw std::out_of_range("ID of Vertex is out of range");
}

const Redactor::Graphic::Vertex3D& Redactor::Graphic::Mesh3D::VertexById(VertexId id) const
{
    if(id-1 < this->verticies.size())
        return this->verticies[id-1];
    else
        throw std::out_of_range("ID of Vertex is out of range");
}

Redactor::Graphic::HalfEdge& Redactor::Graphic::Mesh3D::HalfEdgeById(HalfEdgeId id)
{
    if(id-1 < this->halfEdges.size())
        return this->halfEdges[id-1];
    else
        throw std::out_of_range("ID of HalfEdge is out of range");
}

const Redactor::Graphic::HalfEdge& Redactor::Graphic::Mesh3D::HalfEdgeById(HalfEdgeId id) const
{
    if(id-1 < this->halfEdges.size())
        return this->halfEdges[id-1];
    else
        throw std::out_of_range("ID of HalfEdge is out of range");
}

Redactor::Graphic::Face& Redactor::Graphic::Mesh3D::FaceById(FaceId id)
{
    if(id-1 < this->faces.size())
        return this->faces[id-1];
    else
        throw std::out_of_range("ID of Face is out of range");
}

const Redactor::Graphic::Face& Redactor::Graphic::Mesh3D::FaceById(FaceId id) const
{
    if(id-1 < this->faces.size())
        return this->faces[id-1];
    else
        throw std::out_of_range("ID of Face is out of range");
}

unsigned int Redactor::Graphic::Mesh3D::GetVerticiesAmount(void) const
{
    return this->verticies.size();
}

unsigned int Redactor::Graphic::Mesh3D::GetHalfEdgesAmount(void) const
{
    return this->halfEdges.size();
}

unsigned int Redactor::Graphic::Mesh3D::GetFacesAmount(void) const
{
    return this->faces.size();
}

bool Redactor::Graphic::Mesh3D::IsOptimized(void) const
{
    return this->isOptimized;
}

VertexId Redactor::Graphic::Mesh3D::AddVertex(void)
{
    this->verticies.push_back(Redactor::Graphic::Vertex3D(0, 0, 0));
    return this->verticies.size();
}

VertexId Redactor::Graphic::Mesh3D::AddVertex(Redactor::Graphic::Vertex3D vertex)
{
    this->verticies.push_back(vertex);
    return this->verticies.size();
}

VertexId Redactor::Graphic::Mesh3D::AddVertex(double x, double y, double z)
{
    this->verticies.push_back(Redactor::Graphic::Vertex3D(x, y, z));
    return this->verticies.size();
}

HalfEdgeId Redactor::Graphic::Mesh3D::AddEdge(void)
{
    this->halfEdges.push_back(Redactor::Graphic::HalfEdge());
    return this->halfEdges.size();
}

//
// NEED TO BE IMPLEMENTED
//

HalfEdgeId Redactor::Graphic::Mesh3D::AddEdge(VertexId vert1_id, VertexId vert2_id)
{
    return this->halfEdges.size();
}

HalfEdgeId Redactor::Graphic::Mesh3D::AddEdge(Redactor::Graphic::Vertex3D vert1, Redactor::Graphic::Vertex3D vert2)
{
    return this->halfEdges.size();
}

HalfEdgeId Redactor::Graphic::Mesh3D::AddEdge(double x0, double y0, double z0, double x1, double y1, double z1)
{
    return this->halfEdges.size();
}

HalfEdgeId Redactor::Graphic::Mesh3D::AddEdge(VertexId vert1_id, Redactor::Graphic::Vertex3D vert2)
{
    return this->halfEdges.size();
}

HalfEdgeId Redactor::Graphic::Mesh3D::AddEdge(Redactor::Graphic::Vertex3D vert1, VertexId vert2_id)
{
    return this->halfEdges.size();
}

//
//
//

FaceId Redactor::Graphic::Mesh3D::AddFace(void)
{
    this->faces.push_back(Redactor::Graphic::Face());
    return this->faces.size();
}

FaceId Redactor::Graphic::Mesh3D::AddFace(HalfEdgeId halfEdge_id)
{
    this->faces.push_back(Redactor::Graphic::Face(halfEdge_id));
    return this->faces.size();
}

FaceId Redactor::Graphic::Mesh3D::AddFace(VertexId vert1_id, VertexId vert2_id, VertexId vert3_id)
{
    FaceId result = this->AddFace();

    HalfEdgeId he1_id = this->AddEdge();
    this->FaceById(result).SetHalfEdgeId(he1_id);
    HalfEdgeId he2_id = this->AddEdge();
    HalfEdgeId he3_id = this->AddEdge();

    this->HalfEdgeById(he1_id).SetFaceId(result);
    this->HalfEdgeById(he2_id).SetFaceId(result);
    this->HalfEdgeById(he3_id).SetFaceId(result);

    this->HalfEdgeById(he1_id).SetVertexId(vert2_id);
    this->HalfEdgeById(he2_id).SetVertexId(vert3_id);
    this->HalfEdgeById(he3_id).SetVertexId(vert1_id);

    this->HalfEdgeById(he1_id).SetNextHalfEdgeId(he2_id);
    this->HalfEdgeById(he2_id).SetNextHalfEdgeId(he3_id);
    this->HalfEdgeById(he3_id).SetNextHalfEdgeId(he1_id);

    this->HalfEdgeById(he1_id).SetPrevHalfEdgeId(he3_id);
    this->HalfEdgeById(he2_id).SetPrevHalfEdgeId(he1_id);
    this->HalfEdgeById(he3_id).SetPrevHalfEdgeId(he2_id);

    return result;
}

FaceId Redactor::Graphic::Mesh3D::AddFace(Redactor::Graphic::Vertex3D vert1, Redactor::Graphic::Vertex3D vert2, Redactor::Graphic::Vertex3D vert3)
{
    VertexId vert1_id = this->AddVertex(vert1);
    VertexId vert2_id = this->AddVertex(vert2);
    VertexId vert3_id = this->AddVertex(vert3);

    return this->AddFace(vert1_id, vert2_id, vert3_id);
}

FaceId Redactor::Graphic::Mesh3D::AddFace(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2)
{
    VertexId vert1_id = this->AddVertex(Redactor::Graphic::Vertex3D(x0, y0, z0));
    VertexId vert2_id = this->AddVertex(Redactor::Graphic::Vertex3D(x1, y1, z1));
    VertexId vert3_id = this->AddVertex(Redactor::Graphic::Vertex3D(x2, y2, z2));

    return this->AddFace(vert1_id, vert2_id, vert3_id);
}

bool Redactor::Graphic::Mesh3D::RestructToOptimumSize(void)
{
    if(this->isOptimized)
        return true;
    return true;
}

Redactor::Graphic::Mesh3D Redactor::Graphic::SimpleMesh::CreateTriangle3D(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2)
{
    Redactor::Graphic::Mesh3D result = Redactor::Graphic::Mesh3D();
    result.AddFace(x0, y0, z0, x1, y1, z1, x2, y2, z2);
    return result;
}

Redactor::Graphic::Mesh3D Redactor::Graphic::SimpleMesh::CreateTriangle3D(Redactor::Graphic::Vertex3D vert1, Redactor::Graphic::Vertex3D vert2, Redactor::Graphic::Vertex3D vert3)
{
    Redactor::Graphic::Mesh3D result = Redactor::Graphic::Mesh3D();
    result.AddFace(vert1, vert2, vert3);
    return result;
}

Redactor::Graphic::Mesh3D Redactor::Graphic::SimpleMesh::CreateRectangle3D(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3)
{
    Redactor::Graphic::Mesh3D result = Redactor::Graphic::Mesh3D();
    VertexId vert1_id = result.AddVertex(x0, y0, z0);
    VertexId vert2_id = result.AddVertex(x1, y1, z1);
    VertexId vert3_id = result.AddVertex(x2, y2, z2);
    VertexId vert4_id = result.AddVertex(x3, y3, z3);

    result.AddFace(vert1_id, vert2_id, vert3_id);
    HalfEdgeId twin1_id = result.GetHalfEdgesAmount() - 1;
    result.AddFace(vert4_id, vert2_id, vert3_id);
    HalfEdgeId twin2_id = result.GetHalfEdgesAmount() - 1;

    result.HalfEdgeById(twin1_id).SetTwinHalfEdgeId(twin2_id);
    result.HalfEdgeById(twin2_id).SetTwinHalfEdgeId(twin1_id);

    return result;
}

Redactor::Graphic::Mesh3D Redactor::Graphic::SimpleMesh::CreateRectangle3D(Redactor::Graphic::Vertex3D vert1, Redactor::Graphic::Vertex3D vert2, Redactor::Graphic::Vertex3D vert3, Redactor::Graphic::Vertex3D vert4)
{
    Redactor::Graphic::Mesh3D result = Redactor::Graphic::Mesh3D();
    VertexId vert1_id = result.AddVertex(vert1);
    VertexId vert2_id = result.AddVertex(vert2);
    VertexId vert3_id = result.AddVertex(vert3);
    VertexId vert4_id = result.AddVertex(vert4);

    result.AddFace(vert1_id, vert2_id, vert3_id);
    HalfEdgeId twin1_id = result.GetHalfEdgesAmount() - 1;
    result.AddFace(vert4_id, vert2_id, vert3_id);
    HalfEdgeId twin2_id = result.GetHalfEdgesAmount() - 1;

    result.HalfEdgeById(twin1_id).SetTwinHalfEdgeId(twin2_id);
    result.HalfEdgeById(twin2_id).SetTwinHalfEdgeId(twin1_id);

    return result;
}
