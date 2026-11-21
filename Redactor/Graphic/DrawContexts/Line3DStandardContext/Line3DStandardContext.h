#ifndef __LINE_3D_STANDARD_CONTEXT_H__
#define __LINE_3D_STANDARD_CONTEXT_H__

#include "../../Colors/Color4B/Color4B.h"
#include "../../UV/UV2D/UV2D.h"
#include "../Vertex3DStandardContext/Vertex3DStandardContext.h"

namespace Redactor
{

namespace Graphic
{

namespace DrawContext
{
    class Line3DStandardContext
    {
    public:
        Line3DStandardContext(void);
        Line3DStandardContext(Redactor::Graphic::Colors::Color4B color, double width = 1);
        Line3DStandardContext(Redactor::Graphic::Colors::Color4B start_color, Redactor::Graphic::Colors::Color4B end_color, double width = 1);
        Line3DStandardContext(const Vertex3DStandardContext& start_context, const Vertex3DStandardContext& end_context, double widht = 1);
        Line3DStandardContext(Redactor::Graphic::Colors::Color4B start_color,
                              Redactor::Graphic::UVs::UV2D start_textureCoords,
                              Redactor::Graphic::Colors::Color4B end_color,
                              Redactor::Graphic::UVs::UV2D end_textureCoords,
                              bool visibility = true,
                              bool isStripped = false,
                              int stripFactor = 1,
                              unsigned short int stripPattern = 0x00FF,
                              double width = 1);
        Line3DStandardContext(const Line3DStandardContext& other);
        Line3DStandardContext(Line3DStandardContext&& other) noexcept;
        Line3DStandardContext& operator=(const Line3DStandardContext& other);
        Line3DStandardContext& operator=(Line3DStandardContext&& other) noexcept;

        ~Line3DStandardContext(void);

        Redactor::Graphic::Colors::Color4B GetStartColor(void) const;
        Redactor::Graphic::Colors::Color4B GetEndColor(void) const;
        Redactor::Graphic::UVs::UV2D GetStartTextureCoords(void) const;
        Redactor::Graphic::UVs::UV2D GetEndTextureCoords(void) const;
        bool IsVisible(void) const;
        bool IsStripped(void) const;
        int GetStripFactor(void) const;
        unsigned short int GetStripPattern(void) const;
        double GetWidth(void) const;

        void SetColor(Redactor::Graphic::Colors::Color4B color);
        void SetColor(BYTE r, BYTE g, BYTE b, BYTE a = 255);
        void SetStartColor(Redactor::Graphic::Colors::Color4B color);
        void SetStartColor(BYTE r, BYTE g, BYTE b, BYTE a = 255);
        void SetEndColor(Redactor::Graphic::Colors::Color4B color);
        void SetEndColor(BYTE r, BYTE g, BYTE b, BYTE a = 255);
        void SetStartTextureCoords(Redactor::Graphic::UVs::UV2D textureCoords);
        void SetStartTextureCoords(double u, double v);
        void SetEndTextureCoords(Redactor::Graphic::UVs::UV2D textureCoords);
        void SetEndTextureCoords(double u, double v);
        void SetVisibility(bool isVisible);
        void SetStripMode(bool isStripped);
        void SetStripFactor(int stripFactor);
        void SetStripPattern(unsigned short int stripPattern);
        void SetWidth(double width);

    protected:
        Redactor::Graphic::Colors::Color4B start_color;
        Redactor::Graphic::UVs::UV2D start_textureCoords;
        Redactor::Graphic::Colors::Color4B end_color;
        Redactor::Graphic::UVs::UV2D end_textureCoords;
        bool visibility;
        bool isStripped;
        int stripFactor;
        unsigned short int stripPattern;
        double width;
    };
}

}

}

#endif // __LINE_3D_STANDARD_CONTEXT_H__
