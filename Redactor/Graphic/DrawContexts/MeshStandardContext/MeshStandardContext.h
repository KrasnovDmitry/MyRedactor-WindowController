#ifndef __MESH_STANDARD_DRAW_CONTEXT_H__
#define __MESH_STANDARD_DRAW_CONTEXT_H__

#include "../../Colors/Color4B/Color4B.h"
#include "../Vertex3DStandardContext/Vertex3DStandardContext.h"
#include "../Line3DStandardContext/Line3DStandardContext.h"

namespace Redactor
{

namespace Graphic
{

namespace DrawContext
{
    class MeshStandardContext
    {
    public:
        MeshStandardContext(void);
        MeshStandardContext(Vertex3DStandardContext vertexContext, Line3DStandardContext edgeContext);
        MeshStandardContext(const MeshStandardContext& other);
        MeshStandardContext(MeshStandardContext&& other) noexcept;
        MeshStandardContext& operator=(const MeshStandardContext& other);
        MeshStandardContext& operator=(MeshStandardContext&& other) noexcept;
        ~MeshStandardContext(void);

        //Getters
        bool IsVisible(void) const;

        Vertex3DStandardContext& VertexContext(void);
        const Vertex3DStandardContext& VertexContext(void) const;

        Line3DStandardContext& EdgeContext(void);
        const Line3DStandardContext& EdgeContext(void) const;

        //Setters
        void SetVisibility(bool visibility);

    protected:
        bool isVisible;
        Vertex3DStandardContext vertexContext;
        Line3DStandardContext edgeContext;
    };
}

}

}

#endif // __MESH_STANDARD_DRAW_CONTEXT_H__
