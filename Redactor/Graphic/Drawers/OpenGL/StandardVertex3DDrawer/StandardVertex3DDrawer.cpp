#include "StandardVertex3DDrawer.h"
#include <GL/gl.h>

void Redactor::Graphic::Drawers::OpenGL::StandardVertex3DDrawer::Draw(const Redactor::Graphic::Vertex3D& object, const Redactor::Graphic::DrawContext::Vertex3DStandardContext& context) const
{
    if(context.IsVisible())
    {
        Redactor::Graphic::Colors::Color4B col = context.GetColor();
        Redactor::Graphic::UVs::UV2D uv = context.GetTextureCoords();

        glPointSize(context.GetSize());
        glColor4ub(col.GetR(), col.GetG(), col.GetB(), col.GetA());
        glTexCoord2d(uv.GetU(), uv.GetV());
        glBegin(GL_POINTS);
        glVertex3d(object.GetX(), object.GetY(), object.GetZ());
        glEnd();
    }
}
