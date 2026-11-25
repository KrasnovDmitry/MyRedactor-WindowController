#ifndef __CONSOLE_STANDARD_LINKED_LINE_3D_DRAWER_H__
#define __CONSOLE_STANDARD_LINKED_LINE_3D_DRAWER_H__

#include "../../IDrawer.h"
#include "../../../LinkedLine3D/LinkedLine3D.h"
#include "../../../DrawContexts/Line3DStandardContext/Line3DStandardContext.h"

namespace Redactor
{

namespace Graphic
{

namespace Drawers
{

namespace Console
{
    class StandardLinkedLine3DDrawer: public Redactor::Graphic::Drawers::IDrawer<Redactor::Graphic::LinkedLine3D, Redactor::Graphic::DrawContext::Line3DStandardContext>
    {
    public:
        StandardLinkedLine3DDrawer(void) {}
        virtual ~StandardLinkedLine3DDrawer(void) {}

        void Draw(const Redactor::Graphic::LinkedLine3D& object, const Redactor::Graphic::DrawContext::Line3DStandardContext& context) const override;
    };
}

}

}

}

#endif // __CONSOLE_STANDARD_LINKED_LINE_3D_DRAWER_H__
