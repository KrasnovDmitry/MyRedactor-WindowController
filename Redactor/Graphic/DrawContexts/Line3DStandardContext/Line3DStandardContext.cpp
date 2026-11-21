#include "Line3DStandardContext.h"

namespace Z = Redactor::Graphic::DrawContext;

Z::Line3DStandardContext::Line3DStandardContext(void):
    Z::Line3DStandardContext(Redactor::Graphic::Colors::Color4B(255, 255, 255, 255)) {}


Z::Line3DStandardContext::Line3DStandardContext(Redactor::Graphic::Colors::Color4B color, double width):
    Z::Line3DStandardContext(color, color, width) {}

Z::Line3DStandardContext::Line3DStandardContext(Redactor::Graphic::Colors::Color4B start_color, Redactor::Graphic::Colors::Color4B end_color, double width):
     Z::Line3DStandardContext(start_color, Redactor::Graphic::UVs::UV2D(0, 0), end_color, Redactor::Graphic::UVs::UV2D(0, 0), true, false, 1, 0x00FF, width) {}

Z::Line3DStandardContext::Line3DStandardContext(const Vertex3DStandardContext& start_context, const Vertex3DStandardContext& end_context, double widht):
    Z::Line3DStandardContext(start_context.GetColor(), start_context.GetTextureCoords(), end_context.GetColor(), end_context.GetTextureCoords(), true, false, 1, 0x00FF, width) {}

Z::Line3DStandardContext::Line3DStandardContext(Redactor::Graphic::Colors::Color4B start_color,
                              Redactor::Graphic::UVs::UV2D start_textureCoords,
                              Redactor::Graphic::Colors::Color4B end_color,
                              Redactor::Graphic::UVs::UV2D end_textureCoords,
                              bool visibility,
                              bool isStripped,
                              int stripFactor,
                              unsigned short int stripPattern,
                              double width)
{
    this->start_color = start_color;
    this->end_color = end_color;
    this->start_textureCoords = start_textureCoords;
    this->end_textureCoords = end_textureCoords;
    this->visibility = visibility;
    this->isStripped = isStripped;
    this->stripPattern = stripPattern;
    this->width = width;
}

Z::Line3DStandardContext::Line3DStandardContext(const Z::Line3DStandardContext& other)
{
    this->start_color = other.start_color;
    this->end_color = other.end_color;
    this->start_textureCoords = other.start_textureCoords;
    this->end_textureCoords = other.end_textureCoords;
    this->visibility = other.visibility;
    this->isStripped = other.isStripped;
    this->stripPattern = other.stripPattern;
    this->width = other.width;
}

Z::Line3DStandardContext::Line3DStandardContext(Line3DStandardContext&& other) noexcept
{
    this->start_color = other.start_color;
    this->end_color = other.end_color;
    this->start_textureCoords = other.start_textureCoords;
    this->end_textureCoords = other.end_textureCoords;
    this->visibility = other.visibility;
    this->isStripped = other.isStripped;
    this->stripPattern = other.stripPattern;
    this->width = other.width;
}

Z::Line3DStandardContext& Z::Line3DStandardContext::operator=(const Z::Line3DStandardContext& other)
{
    if(this != &other)
    {
        this->start_color = other.start_color;
        this->end_color = other.end_color;
        this->start_textureCoords = other.start_textureCoords;
        this->end_textureCoords = other.end_textureCoords;
        this->visibility = other.visibility;
        this->isStripped = other.isStripped;
        this->stripPattern = other.stripPattern;
        this->width = other.width;
    }
    return *this;
}

Z::Line3DStandardContext& Z::Line3DStandardContext::operator=(Z::Line3DStandardContext&& other) noexcept
{
    if(this != &other)
    {
        this->start_color = other.start_color;
        this->end_color = other.end_color;
        this->start_textureCoords = other.start_textureCoords;
        this->end_textureCoords = other.end_textureCoords;
        this->visibility = other.visibility;
        this->isStripped = other.isStripped;
        this->stripPattern = other.stripPattern;
        this->width = other.width;
    }
    return *this;
}

Z::Line3DStandardContext::~Line3DStandardContext(void){}

Redactor::Graphic::Colors::Color4B Z::Line3DStandardContext::GetStartColor(void) const
{
    return this->start_color;
}

Redactor::Graphic::Colors::Color4B Z::Line3DStandardContext::GetEndColor(void) const
{
    return this->end_color;
}

Redactor::Graphic::UVs::UV2D Z::Line3DStandardContext::GetStartTextureCoords(void) const
{
    return this->start_textureCoords;
}

Redactor::Graphic::UVs::UV2D Z::Line3DStandardContext::GetEndTextureCoords(void) const
{
    return this->end_textureCoords;
}

bool Z::Line3DStandardContext::IsVisible(void) const
{
    return this->visibility;
}

bool Z::Line3DStandardContext::IsStripped(void) const
{
    return this->isStripped;
}

int Z::Line3DStandardContext::GetStripFactor(void) const
{
    return this->stripFactor;
}

unsigned short int Z::Line3DStandardContext::GetStripPattern(void) const
{
    return this->stripPattern;
}

double Z::Line3DStandardContext::GetWidth(void) const
{
    return this->width;
}

void Z::Line3DStandardContext::SetColor(Redactor::Graphic::Colors::Color4B color)
{
    this->start_color = color;
    this->end_color = color;
}

void Z::Line3DStandardContext::SetColor(BYTE r, BYTE g, BYTE b, BYTE a)
{
    this->start_color = Redactor::Graphic::Colors::Color4B(r, g, b, a);
    this->end_color = Redactor::Graphic::Colors::Color4B(r, g, b, a);
}

void Z::Line3DStandardContext::SetStartColor(Redactor::Graphic::Colors::Color4B color)
{
    this->start_color = color;
}

void Z::Line3DStandardContext::SetStartColor(BYTE r, BYTE g, BYTE b, BYTE a)
{
    this->start_color = Redactor::Graphic::Colors::Color4B(r, g, b, a);
}

void Z::Line3DStandardContext::SetEndColor(Redactor::Graphic::Colors::Color4B color)
{
    this->end_color = color;
}

void Z::Line3DStandardContext::SetEndColor(BYTE r, BYTE g, BYTE b, BYTE a)
{
    this->end_color = Redactor::Graphic::Colors::Color4B(r, g, b, a);
}

void Z::Line3DStandardContext::SetStartTextureCoords(Redactor::Graphic::UVs::UV2D textureCoords)
{
    this->start_textureCoords = textureCoords;
}

void Z::Line3DStandardContext::SetStartTextureCoords(double u, double v)
{
    this->start_textureCoords = Redactor::Graphic::UVs::UV2D(u, v);
}

void Z::Line3DStandardContext::SetEndTextureCoords(Redactor::Graphic::UVs::UV2D textureCoords)
{
    this->end_textureCoords = textureCoords;
}

void Z::Line3DStandardContext::SetEndTextureCoords(double u, double v)
{
    this->end_textureCoords = Redactor::Graphic::UVs::UV2D(u, v);
}

void Z::Line3DStandardContext::SetVisibility(bool isVisible)
{
    this->visibility = isVisible;
}

void Z::Line3DStandardContext::SetStripMode(bool isStripped)
{
    this->isStripped = isStripped;
}

void Z::Line3DStandardContext::SetStripFactor(int stripFactor)
{
    this->stripFactor = stripFactor;
}

void Z::Line3DStandardContext::SetStripPattern(unsigned short int stripPattern)
{
    this->stripPattern = stripPattern;
}

void Z::Line3DStandardContext::SetWidth(double width)
{
    this->width = width;
}
