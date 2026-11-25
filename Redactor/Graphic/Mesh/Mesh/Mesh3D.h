#ifndef __MESH_3D_H__
#define __MESH_3D_H__

#include "../../Vertex3D/Vertex3D.h"
#include "../Face3D/Face3D.h"
#include "../HalfEdge3D/HalfEdge3D.h"
#include <vector>

namespace Redactor
{

namespace Graphic
{
    class Mesh3D
    {
    public:
        Mesh3D(void);
        Mesh3D(const Mesh3D& other);
        Mesh3D(Mesh3D&& other) noexcept;

        Mesh3D& operator=(const Mesh3D& other);
        Mesh3D& operator=(Mesh3D&& other) noexcept;
        ~Mesh3D(void);

        //Getters
        Redactor::Graphic::Vertex3D& VertexById(VertexId id);
        const Redactor::Graphic::Vertex3D& VertexById(VertexId id) const;

        Redactor::Graphic::HalfEdge& HalfEdgeById(HalfEdgeId id);
        const Redactor::Graphic::HalfEdge& HalfEdgeById(HalfEdgeId id) const;

        Redactor::Graphic::Face& FaceById(FaceId id);
        const Redactor::Graphic::Face& FaceById(FaceId id) const;

        unsigned int GetVerticiesAmount(void) const;
        unsigned int GetHalfEdgesAmount(void) const;
        unsigned int GetFacesAmount(void) const;
        bool IsOptimized(void) const;

        //funcs
        VertexId AddVertex(void);
        VertexId AddVertex(Redactor::Graphic::Vertex3D vertex);
        VertexId AddVertex(double x, double y, double z);

        HalfEdgeId AddEdge(void);
        HalfEdgeId AddEdge(VertexId vert1_id, VertexId vert2_id);
        HalfEdgeId AddEdge(Redactor::Graphic::Vertex3D vert1, Redactor::Graphic::Vertex3D vert2);
        HalfEdgeId AddEdge(double x0, double y0, double z0, double x1, double y1, double z1);
        HalfEdgeId AddEdge(VertexId vert1_id, Redactor::Graphic::Vertex3D vert2);
        HalfEdgeId AddEdge(Redactor::Graphic::Vertex3D vert1, VertexId vert2_id);

        FaceId AddFace(void);
        FaceId AddFace(HalfEdgeId halfEdge_id);
        FaceId AddFace(VertexId vert1_id, VertexId vert2_id, VertexId vert3_id);
        FaceId AddFace(Redactor::Graphic::Vertex3D vert1, Redactor::Graphic::Vertex3D vert2, Redactor::Graphic::Vertex3D vert3);
        FaceId AddFace(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2);

        bool RestructToOptimumSize(void);

    protected:
        std::vector<Redactor::Graphic::Vertex3D> verticies;
        std::vector<Face> faces;
        std::vector<HalfEdge> halfEdges;
        bool isOptimized;
    };

    namespace SimpleMesh
    {
        Redactor::Graphic::Mesh3D CreateTriangle3D(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2);
        Redactor::Graphic::Mesh3D CreateTriangle3D(Redactor::Graphic::Vertex3D vert1, Redactor::Graphic::Vertex3D vert2, Redactor::Graphic::Vertex3D vert3);

        Redactor::Graphic::Mesh3D CreateRectangle3D(double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
        Redactor::Graphic::Mesh3D CreateRectangle3D(Redactor::Graphic::Vertex3D vert1, Redactor::Graphic::Vertex3D vert2, Redactor::Graphic::Vertex3D vert3, Redactor::Graphic::Vertex3D vert4);
    }
}

}

#endif // __MESH_3D_H__
