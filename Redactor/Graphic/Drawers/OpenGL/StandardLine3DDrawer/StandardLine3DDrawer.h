#ifndef __OPENGL_STANDARD_LINE_3D_DRAWER_H__
#define __OPENGL_STANDARD_LINE_3D_DRAWER_H__

#include "../../IDrawer.h"
#include "../../../Line3D/Line3D.h"
#include "../../../DrawContexts/Line3DStandardContext/Line3DStandardContext.h"

namespace Redactor
{

namespace Graphic
{

namespace Drawers
{

namespace OpenGL
{
    class StandardLine3DDrawer: public Redactor::Graphic::Drawers::IDrawer<Redactor::Graphic::Line3D, Redactor::Graphic::DrawContext::Line3DStandardContext>
    {
    public:
        StandardLine3DDrawer(void) {}
        virtual ~StandardLine3DDrawer(void) {}

        void Draw(const Redactor::Graphic::Line3D& object, const Redactor::Graphic::DrawContext::Line3DStandardContext& context) const override;
    };
}

}

}

}

#endif // __OPENGL_STANDARD_VERTEX_3D_DRAWER_H__
