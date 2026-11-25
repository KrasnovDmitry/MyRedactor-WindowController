#ifndef __FACE_H__
#define __FACE_H__

#include "../IDsTypedefs.h"

namespace Redactor
{

namespace Graphic
{
    class Face
    {
    public:
        Face(void);
        Face(HalfEdgeId half_edge_id);

        Face(const Face& other);
        Face(Face&& other) noexcept;
        Face& operator=(const Face& other);
        Face& operator=(Face&& other) noexcept;

        ~Face(void);

        void SetHalfEdgeId(HalfEdgeId id);

        HalfEdgeId GetHalfEdgeId(void) const;

    protected:
        HalfEdgeId half_edge_id;
    };
}

}

#endif // __FACE_H__
