#include "MeshStandardContext.h"

Redactor::Graphic::DrawContext::MeshStandardDrawContext::MeshStandardDrawContext(void)
{
    this->isVisible = true;
    this->vertexContext = Redactor::Graphic::DrawContext::Vertex3DStandardContext();
    this->edgeContext = Redactor::Graphic::DrawContext::Line3DStandardContext();
}

Redactor::Graphic::DrawContext::MeshStandardDrawContext::MeshStandardDrawContext(const Redactor::Graphic::DrawContext::MeshStandardDrawContext& other)
{
    this->isVisible = true;
    this->vertexContext = vertexContext;
    this->edgeContext = edgeContext;
}

Redactor::Graphic::DrawContext::MeshStandardDrawContext::MeshStandardDrawContext(Redactor::Graphic::DrawContext::MeshStandardDrawContext&& other) noexcept
{
    this->isVisible = other.isVisible;
    this->vertexContext = other.vertexContext;
    this->edgeContext = other.edgeContext;
}

Redactor::Graphic::DrawContext::MeshStandardDrawContext& Redactor::Graphic::DrawContext::MeshStandardDrawContext::operator=(const Redactor::Graphic::DrawContext::MeshStandardDrawContext& other)
{
    if(this != &other)
    {
        this->isVisible = other.isVisible;
        this->vertexContext = other.vertexContext;
        this->edgeContext = other.edgeContext;
    }
    return *this;
}

Redactor::Graphic::DrawContext::MeshStandardDrawContext& Redactor::Graphic::DrawContext::MeshStandardDrawContext::operator=(Redactor::Graphic::DrawContext::MeshStandardDrawContext&& other) noexcept
{
    if(this != &other)
    {
        this->isVisible = other.isVisible;
        this->vertexContext = other.vertexContext;
        this->edgeContext = other.edgeContext;
    }
    return *this;
}

Redactor::Graphic::DrawContext::MeshStandardDrawContext::~MeshStandardDrawContext(void)
{
    this->isVisible = false;
}

bool Redactor::Graphic::DrawContext::MeshStandardDrawContext::IsVisible(void) const
{
    return this->isVisible;
}

Redactor::Graphic::DrawContext::Vertex3DStandardContext& Redactor::Graphic::DrawContext::MeshStandardDrawContext::VertexContext(void)
{
    return this->vertexContext;
}

const Redactor::Graphic::DrawContext::Vertex3DStandardContext& Redactor::Graphic::DrawContext::MeshStandardDrawContext::VertexContext(void) const
{
    return this->vertexContext;
}

Redactor::Graphic::DrawContext::Line3DStandardContext& Redactor::Graphic::DrawContext::MeshStandardDrawContext::EdgeContext(void)
{
    return this->edgeContext;
}

const Redactor::Graphic::DrawContext::Line3DStandardContext& Redactor::Graphic::DrawContext::MeshStandardDrawContext::EdgeContext(void) const
{
    return this->edgeContext;
}

void Redactor::Graphic::DrawContext::MeshStandardDrawContext::SetVisibility(bool visibility)
{
    this->isVisible = visibility;
}
