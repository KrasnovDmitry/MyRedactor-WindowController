#ifndef __CONSOLE_STANDARD_MESH_3D_DRAWER_H__
#define __CONSOLE_STANDARD_MESH_3D_DRAWER_H__

#include "../../IDrawer.h"
#include "../../../LinkedLine3D/LinkedLine3D.h"
#include "../../../DrawContexts/Line3DStandardContext/Line3DStandardContext.h"
#include "../StandardLinkedLine3DDrawer/StandardLinkedLine3DDrawer.h"
#include "../StandardVertex3DDrawer/StandardVertex3DDrawer.h"
#include "../../../Mesh/Mesh/Mesh3D.h"
#include "../../../DrawContexts/MeshStandardContext/MeshStandardContext.h"

namespace Redactor
{

namespace Graphic
{

namespace Drawers
{

namespace Console
{
    class StandardMesh3DDrawer: public Redactor::Graphic::Drawers::IDrawer<Redactor::Graphic::Mesh3D, Redactor::Graphic::DrawContext::MeshStandardDrawContext>
    {
    public:
        StandardMesh3DDrawer(void) {this->vertexDrawer = Redactor::Graphic::Drawers::Console::StandardVertex3DDrawer(); this->edgeDrawer = Redactor::Graphic::Drawers::Console::StandardLinkedLine3DDrawer();}
        virtual ~StandardMesh3DDrawer(void) {}

        void Draw(const Redactor::Graphic::Mesh3D& object, const Redactor::Graphic::DrawContext::MeshStandardDrawContext& context) const override;

    protected:
        Redactor::Graphic::Drawers::Console::StandardLinkedLine3DDrawer edgeDrawer;
        Redactor::Graphic::Drawers::Console::StandardVertex3DDrawer vertexDrawer;
    };
}

}

}

}

#endif // __CONSOLE_STANDARD_MESH_3D_DRAWER_H__
