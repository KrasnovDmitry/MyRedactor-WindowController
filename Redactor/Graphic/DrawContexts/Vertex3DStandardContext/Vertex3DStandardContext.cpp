#include "Vertex3DStandardContext.h"
#include <stdexcept>

namespace G = Redactor::Graphic::DrawContext;
namespace Colors = Redactor::Graphic::Colors;
namespace UVs = Redactor::Graphic::UVs;

G::Vertex3DStandardContext::Vertex3DStandardContext(void)
{
    this->color = Colors::Color4B(255, 255, 255, 255);
    this->textureCoords = UVs::UV2D(0, 0);
    this->visibility = true;
    this->size = 1;
}

G::Vertex3DStandardContext::Vertex3DStandardContext(Colors::Color4B color, UVs::UV2D text_coords, double size, bool visibility)
{
    this->color = color;
    this->textureCoords = text_coords;
    this->size = size;
    this->visibility = visibility;

}

G::Vertex3DStandardContext::Vertex3DStandardContext(const G::Vertex3DStandardContext& other)
{
    this->color = other.color;
    this->textureCoords = other.textureCoords;
    this->visibility = other.visibility;
    this->size = other.size;
}

G::Vertex3DStandardContext::Vertex3DStandardContext(Vertex3DStandardContext&& other) noexcept
{
    this->color = other.color;
    this->textureCoords = other.textureCoords;
    this->visibility = other.visibility;
    this->size = other.size;

    other.color = Colors::Color4B(0, 0, 0, 0);
    other.textureCoords = UVs::UV2D(0, 0);
    other.visibility = false;
    other.size = 0;
}

G::Vertex3DStandardContext& G::Vertex3DStandardContext::operator=(const G::Vertex3DStandardContext& other)
{
    if(this != &other)
    {
        this->color = other.color;
        this->textureCoords = other.textureCoords;
        this->visibility = other.visibility;
        this->size = other.size;
    }
    return *this;
}

G::Vertex3DStandardContext& G::Vertex3DStandardContext::operator=(G::Vertex3DStandardContext&& other) noexcept
{
    if(this != &other)
    {
        this->color = other.color;
        this->textureCoords = other.textureCoords;
        this->visibility = other.visibility;
        this->size = other.size;

        other.color = Colors::Color4B(0, 0, 0, 0);
        other.textureCoords = UVs::UV2D(0, 0);
        other.visibility = false;
        other.size = 0;
    }
    return *this;
}

G::Vertex3DStandardContext::~Vertex3DStandardContext()
{
    this->color = Colors::Color4B(0, 0, 0, 0);
    this->textureCoords = UVs::UV2D(0, 0);
    this->visibility = false;
    this->size = 0;
}

Colors::Color4B G::Vertex3DStandardContext::GetColor(void) const
{
    return this->color;
}

UVs::UV2D G::Vertex3DStandardContext::GetTextureCoords(void) const
{
    return this->textureCoords;
}

bool G::Vertex3DStandardContext::IsVisible(void) const
{
    return this->visibility;
}

double G::Vertex3DStandardContext::GetSize(void) const
{
    return this->size;
}

void G::Vertex3DStandardContext::SetColor(Colors::Color4B color)
{
    this->color = color;
}

void G::Vertex3DStandardContext::SetTextureCoords(UVs::UV2D textureCoords)
{
    this->textureCoords = textureCoords;
}

void G::Vertex3DStandardContext::SetVisibility(bool visibility)
{
    this->visibility = visibility;
}

void G::Vertex3DStandardContext::SetSize(double size)
{
    if(size < 0.0)
        throw std::domain_error("SetSize(): size cannot be negative");
    this->size = size;
}
