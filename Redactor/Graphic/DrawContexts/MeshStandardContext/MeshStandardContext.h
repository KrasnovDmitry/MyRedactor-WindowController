#ifndef __MESH_STANDARD_CONTEXT_H__
#define __MESH_STANDARD_CONTEXT_H__

#include "../Line3DStandardContext/Line3DStandardContext.h"
#include "../Vertex3DStandardContext/Vertex3DStandardContext.h"

namespace Redactor
{

namespace Graphic
{

namespace DrawContext
{
    class MeshStandardDrawContext
    {
    public:
        MeshStandardDrawContext(void);
        MeshStandardDrawContext(const MeshStandardDrawContext& other);
        MeshStandardDrawContext(MeshStandardDrawContext&& other) noexcept;
        MeshStandardDrawContext& operator=(const MeshStandardDrawContext& other);
        MeshStandardDrawContext& operator=(MeshStandardDrawContext&& other) noexcept;
        ~MeshStandardDrawContext(void);

        bool IsVisible(void) const;

        void SetVisibility(bool visibility);

        Redactor::Graphic::DrawContext::Vertex3DStandardContext& VertexContext(void);
        const Redactor::Graphic::DrawContext::Vertex3DStandardContext& VertexContext(void) const;

        Redactor::Graphic::DrawContext::Line3DStandardContext& EdgeContext(void);
        const Redactor::Graphic::DrawContext::Line3DStandardContext& EdgeContext(void) const;

    protected:
        Redactor::Graphic::DrawContext::Vertex3DStandardContext vertexContext;
        Redactor::Graphic::DrawContext::Line3DStandardContext edgeContext;
        bool isVisible;
    };
}

}

}

#endif // __MESH_STANDARD_CONTEXT_H__
