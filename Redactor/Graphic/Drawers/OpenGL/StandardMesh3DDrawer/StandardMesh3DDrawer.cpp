#include "StandardMesh3DDrawer.h"
#include <GL/gl.h>

void Redactor::Graphic::Drawers::OpenGL::StandardMesh3DDrawer::Draw(const Redactor::Graphic::Mesh3D& object, const Redactor::Graphic::DrawContext::MeshStandardDrawContext& context) const
{
    if(context.IsVisible())
    {
        const Redactor::Graphic::DrawContext::Vertex3DStandardContext& vertexContext = context.VertexContext();
        const Redactor::Graphic::DrawContext::Line3DStandardContext& edgeContext = context.EdgeContext();

        for(unsigned int i = 0; i < object.GetVerticiesAmount(); i++)
        {
            const Redactor::Graphic::Vertex3D& vert_ref = object.VertexById(i+1);
            this->vertexDrawer.Draw(vert_ref, vertexContext);
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
    }
}
