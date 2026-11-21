#ifndef __OPENGL_STANDARD_VERTEX_3D_DRAWER_H__
#define __OPENGL_STANDARD_VERTEX_3D_DRAWER_H__

#include "../../IDrawer.h"
#include "../../../Vertex3D/Vertex3D.h"
#include "../../../DrawContexts/Vertex3DStandardContext/Vertex3DStandardContext.h"

namespace Redactor
{

namespace Graphic
{

namespace Drawers
{

namespace OpenGL
{
    class StandardVertex3DDrawer: public Redactor::Graphic::Drawers::IDrawer<Redactor::Graphic::Vertex3D, Redactor::Graphic::DrawContext::Vertex3DStandardContext>
    {
    public:
        StandardVertex3DDrawer(void) {}
        virtual ~StandardVertex3DDrawer(void) {}

        void Draw(const Redactor::Graphic::Vertex3D& object, const Redactor::Graphic::DrawContext::Vertex3DStandardContext& context) const override;
    };
}

}

}

}

#endif // __OPENGL_STANDARD_VERTEX_3D_DRAWER_H__
