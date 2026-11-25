#ifndef __MESH_3D_H__
#define __MESH_3D_H__

#include <vector>
#include "../IDsTypedefs.h"
#include "../Face3D/Face3D.h"
#include "../HalfEdge3D/HalfEdge3D.h"

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

            //Adding vertices
            VERTEX_ID add_vertex(void);
            VERTEX_ID add_vertex(vertex_2d vertex);
            VERTEX_ID add_vertex(double x, double y);

            //Adding half_edges
            HALF_EDGE_ID add_half_edge(void);
            HALF_EDGE_ID add_half_edge(half_edge_2d half_edge);
            HALF_EDGE_ID add_half_edge(VERTEX_ID vertex_id, HALF_EDGE_ID next_id, HALF_EDGE_ID prev_id, HALF_EDGE_ID twin_id, FACE_ID face_id);

            //Adding faces
            FACE_ID add_face(void);
            FACE_ID add_face(face_2d face);

            //Addings to mesh

            FACE_ID add_triangle(void);
    };
}

}

#endif // __MESH_3D_H__
