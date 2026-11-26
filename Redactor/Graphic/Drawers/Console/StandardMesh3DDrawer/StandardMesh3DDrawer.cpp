#include "StandardMesh3DDrawer.h"
#include <iostream>

void Redactor::Graphic::Drawers::Console::StandardMesh3DDrawer::Draw(const Redactor::Graphic::Mesh3D& object, const Redactor::Graphic::DrawContext::MeshStandardDrawContext& context) const
{
    const Redactor::Graphic::DrawContext::Vertex3DStandardContext& vertexContext = context.VertexContext();
    const Redactor::Graphic::DrawContext::Line3DStandardContext& edgeContext = context.EdgeContext();

    std::cout << "Mesh3D:" << std::endl;
    std::cout << "Verticies\n{\n";
    for(unsigned int i = 0; i < object.GetVerticiesAmount(); i++)
    {
        std::cout << i+1 << ":" << std::endl;
        const Redactor::Graphic::Vertex3D& vert_ref = object.VertexById(i+1);
        this->vertexDrawer.Draw(vert_ref, vertexContext);
    }

    std::cout << "HalfEdges\n{\n";
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

    std::cout << "Visibility: " << context.IsVisible() << std::endl;
}
