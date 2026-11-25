#ifndef __HALF_EDGE_3D_H__
#define __HALF_EDGE_3D_H__

#include "../IDsTypedefs.h"

namespace Redactor
{

namespace Graphic
{
    class HalfEdge
    {
    public:
        HalfEdge(void);
        HalfEdge(VertexId vertex_id, HalfEdgeId next_id = 0, HalfEdgeId prev_id = 0, HalfEdgeId twin_id = 0, FaceId face_id = 0);

        HalfEdge(const HalfEdge& other);
        HalfEdge(HalfEdge&& other) noexcept;
        HalfEdge& operator=(const HalfEdge& other);
        HalfEdge& operator=(HalfEdge&& other) noexcept;

        ~HalfEdge(void);

        //Setters
        void SetVertexId(VertexId id);
        void SetNextHalfEdgeId(HalfEdgeId id);
        void SetPrevHalfEdgeId(HalfEdgeId id);
        void SetTwinHalfEdgeId(HalfEdgeId id);
        void SetFaceId(FaceId id);

        //Getters
        VertexId GetVertexId(void) const;
        HalfEdgeId GetNextHalfEdgeId(void) const;
        HalfEdgeId GetPrevHalfEdgeId(void) const;
        HalfEdgeId GetTwinHalfEdgeId(void) const;
        FaceId GetFaceId(void) const;

    protected:
        VertexId vertex_id;
        HalfEdgeId next_id;
        HalfEdgeId prev_id;
        HalfEdgeId twin_id;
        FaceId face_id;
    };
}

}

#endif // __HALF_EDGE_3D_H__
