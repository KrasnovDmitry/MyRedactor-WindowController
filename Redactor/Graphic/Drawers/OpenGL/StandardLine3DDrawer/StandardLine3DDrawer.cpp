#include "StandardLine3DDrawer.h"
#include <GL/gl.h>

void Redactor::Graphic::Drawers::OpenGL::StandardLine3DDrawer::Draw(const Redactor::Graphic::Line3D& object, const Redactor::Graphic::DrawContext::Line3DStandardContext& context) const
{
    if(context.IsVisible())
    {
        if(context.IsStripped())
        {
            glEnable(GL_LINE_STIPPLE);
            glLineStipple(context.GetStripFactor(), context.GetStripPattern());
        }
        glLineWidth(context.GetWidth());

        glBegin(GL_LINES);

            glColor4ub(context.GetStartColor().GetR(), context.GetStartColor().GetG(), context.GetStartColor().GetB(), context.GetStartColor().GetA());
            glTexCoord2d(context.GetStartTextureCoords().GetU(), context.GetStartTextureCoords().GetV());
            glVertex3d(object.GetStartX(), object.GetStartY(), object.GetStartZ());

            glColor4ub(context.GetEndColor().GetR(), context.GetEndColor().GetG(), context.GetEndColor().GetB(), context.GetEndColor().GetA());
            glTexCoord2d(context.GetEndTextureCoords().GetU(), context.GetEndTextureCoords().GetV());
            glVertex3d(object.GetEndX(), object.GetEndY(), object.GetEndZ());

        glEnd();

        if(context.IsStripped())
            glDisable(GL_LINE_STIPPLE);
    }
}
