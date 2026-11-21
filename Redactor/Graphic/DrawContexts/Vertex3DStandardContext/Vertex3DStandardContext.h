#ifndef __VERTEX_3D_STANDARD_CONTEXT_H__
#define __VERTEX_3D_STANDARD_CONTEXT_H__

#include "../../Colors/Color4B/Color4B.h"
#include "../../UV/UV2D/UV2D.h"

namespace Redactor
{

namespace Graphic
{

namespace DrawContext
{
    class Vertex3DStandardContext
    {
    public:
        Vertex3DStandardContext(void);
        Vertex3DStandardContext(Redactor::Graphic::Colors::Color4B color, Redactor::Graphic::UVs::UV2D text_coords = Redactor::Graphic::UVs::UV2D(0, 0), double size = 1, bool visibility = true);
        Vertex3DStandardContext(const Vertex3DStandardContext& other);
        Vertex3DStandardContext(Vertex3DStandardContext&& other) noexcept;
        Vertex3DStandardContext& operator=(const Vertex3DStandardContext& other);
        Vertex3DStandardContext& operator=(Vertex3DStandardContext&& other) noexcept;
        ~Vertex3DStandardContext();

        Redactor::Graphic::Colors::Color4B GetColor(void) const;
        Redactor::Graphic::UVs::UV2D GetTextureCoords(void) const;
        bool IsVisible(void) const;
        double GetSize(void) const;

        void SetColor(Redactor::Graphic::Colors::Color4B color);
        void SetTextureCoords(Redactor::Graphic::UVs::UV2D textureCoords);
        void SetVisibility(bool visibility);
        void SetSize(double size);

    protected:
        Redactor::Graphic::Colors::Color4B color;
        Redactor::Graphic::UVs::UV2D textureCoords;
        bool visibility;
        double size;
    };
}

}

}

#endif // __VERTEX_3D_STANDARD_CONTEXT_H__
