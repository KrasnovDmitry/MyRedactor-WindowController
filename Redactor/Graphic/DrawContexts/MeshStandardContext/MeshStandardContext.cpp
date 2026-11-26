#include "MeshStandardContext.h"

Redactor::Graphic::DrawContext::MeshStandardContext::MeshStandardContext(void)
{
    this->isVisible = true;
    this->vertexContext = Redactor::Graphic::DrawContext::Vertex3DStandardContext();
    this->edgeContext = Redactor::Graphic::DrawContext::Line3DStandardContext();
}

Redactor::Graphic::DrawContext::MeshStandardContext::MeshStandardContext(Redactor::Graphic::DrawContext::Vertex3DStandardContext vertexContext, Redactor::Graphic::DrawContext::Line3DStandardContext edgeContext)
{
    this->isVisible = true;
    this->vertexContext = vertexContext;
    this->edgeContext = edgeContext;
}

Redactor::Graphic::DrawContext::MeshStandardContext::MeshStandardContext(const Redactor::Graphic::DrawContext::MeshStandardContext& other)
{
    this->isVisible = other.isVisible;
    this->vertexContext = other.vertexContext;
    this->edgeContext = other.edgeContext;
}

Redactor::Graphic::DrawContext::MeshStandardContext::MeshStandardContext(Redactor::Graphic::DrawContext::MeshStandardContext&& other) noexcept
{
    this->isVisible = other.isVisible;
    this->vertexContext = other.vertexContext;
    this->edgeContext = other.edgeContext;
}

Redactor::Graphic::DrawContext::MeshStandardContext& Redactor::Graphic::DrawContext::MeshStandardContext::operator=(const Redactor::Graphic::DrawContext::MeshStandardContext& other)
{
    if(this != &other)
    {
        this->isVisible = other.isVisible;
        this->vertexContext = other.vertexContext;
        this->edgeContext = other.edgeContext;
    }
    return *this;
}

Redactor::Graphic::DrawContext::MeshStandardContext& Redactor::Graphic::DrawContext::MeshStandardContext::operator=(Redactor::Graphic::DrawContext::MeshStandardContext&& other) noexcept
{
    if(this != &other)
    {
        this->isVisible = other.isVisible;
        this->vertexContext = other.vertexContext;
        this->edgeContext = other.edgeContext;
    }
    return *this;
}

Redactor::Graphic::DrawContext::MeshStandardContext::~MeshStandardContext(void)
{
    this->isVisible = false;
}

bool Redactor::Graphic::DrawContext::MeshStandardContext::IsVisible(void) const
{
    return this->isVisible;
}

Redactor::Graphic::DrawContext::Vertex3DStandardContext& Redactor::Graphic::DrawContext::MeshStandardContext::VertexContext(void)
{
    return this->vertexContext;
}

const Redactor::Graphic::DrawContext::Vertex3DStandardContext& Redactor::Graphic::DrawContext::MeshStandardContext::VertexContext(void) const
{
    return this->vertexContext;
}

Redactor::Graphic::DrawContext::Line3DStandardContext& Redactor::Graphic::DrawContext::MeshStandardContext::EdgeContext(void)
{
    return this->edgeContext;
}

const Redactor::Graphic::DrawContext::Line3DStandardContext& Redactor::Graphic::DrawContext::MeshStandardContext::EdgeContext(void) const
{
    return this->edgeContext;
}

void Redactor::Graphic::DrawContext::MeshStandardContext::SetVisibility(bool visibility)
{
    this->isVisible = visibility;
}
