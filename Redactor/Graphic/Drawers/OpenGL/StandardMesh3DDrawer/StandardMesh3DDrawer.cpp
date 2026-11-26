#include "StandardMesh3DDrawer.h"
#include <GL/gl.h>

void Redactor::Graphic::Drawers::OpenGL::StandardMesh3DDrawer::Draw(const Redactor::Graphic::Mesh3D& object, const Redactor::Graphic::DrawContext::MeshStandardDrawContext& context) const
{
    if(context.IsVisible())
    {
        const Redactor::Graphic::DrawContext::Vertex3DStandardContext& vertexContext = context.VertexContext();
        const Redactor::Graphic::DrawContext::Line3DStandardContext& edgeContext = context.EdgeContext();

        glColor4ub(255, 255, 255, 255);
        for(unsigned int i = 0; i < object.GetFacesAmount(); i++)
        {
            HalfEdgeId he_id = object.FaceById(i+1).GetHalfEdgeId();
            HalfEdgeId he_next_id;
            HalfEdgeId he1_id = he_id;
            if(he_id)
            {
                glBegin(GL_POLYGON);
                do
                {
                    he_next_id = object.HalfEdgeById(he1_id).GetNextHalfEdgeId();
                    const Redactor::Graphic::Vertex3D& vert_ref = object.VertexById(object.HalfEdgeById(he1_id).GetVertexId());
                    glVertex3d(vert_ref.GetX(), vert_ref.GetY(), vert_ref.GetZ());
                    he1_id = he_next_id;
                }while(he1_id != he_id);
                glEnd();
            }
        }

        for(unsigned int i = 0; i < object.GetHalfEdgesAmount(); i++)
        {
            Redactor::Graphic::LinkedLine3D line = Redactor::Graphic::LinkedLine3D();
            line.SetDeallocFlags(true, true);

            HalfEdgeId prev_id = object.HalfEdgeById(i+1).GetPrevHalfEdgeId();
            HalfEdgeId next_id = object.HalfEdgeById(i+1).GetNextHalfEdgeId();

            if(prev_id)
            {
                VertexId vert_id = object.HalfEdgeById(prev_id).GetVertexId();
                if(vert_id)
                {
                    line.SetStart(object.VertexById(vert_id));
                }
            }

            if(next_id)
            {
                VertexId vert_id = object.HalfEdgeById(next_id).GetVertexId();
                if(vert_id)
                {
                    line.SetEnd(object.VertexById(vert_id));
                }
            }

            this->edgeDrawer.Draw(line, edgeContext);
        }

        for(unsigned int i = 0; i < object.GetVerticiesAmount(); i++)
        {
            const Redactor::Graphic::Vertex3D& vert_ref = object.VertexById(i+1);
            this->vertexDrawer.Draw(vert_ref, vertexContext);
        }
    }
}
