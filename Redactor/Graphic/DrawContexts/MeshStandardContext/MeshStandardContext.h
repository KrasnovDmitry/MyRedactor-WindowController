<<<<<<< HEAD
#ifndef __MESH_STANDARD_CONTEXT_H__
#define __MESH_STANDARD_CONTEXT_H__

#include "../Line3DStandardContext/Line3DStandardContext.h"
#include "../Vertex3DStandardContext/Vertex3DStandardContext.h"
=======
#ifndef __MESH_STANDARD_DRAW_CONTEXT_H__
#define __MESH_STANDARD_DRAW_CONTEXT_H__

#include "../../Colors/Color4B/Color4B.h"
#include "../Vertex3DStandardContext/Vertex3DStandardContext.h"
#include "../Line3DStandardContext/Line3DStandardContext.h"
>>>>>>> ec5f8cca959bdc2e93115a7b6e5ce30430c822de

namespace Redactor
{

namespace Graphic
{

namespace DrawContext
{
<<<<<<< HEAD
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
=======
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
>>>>>>> ec5f8cca959bdc2e93115a7b6e5ce30430c822de
    };
}

}

}

<<<<<<< HEAD
#endif // __MESH_STANDARD_CONTEXT_H__
=======
#endif // __MESH_STANDARD_DRAW_CONTEXT_H__
>>>>>>> ec5f8cca959bdc2e93115a7b6e5ce30430c822de
