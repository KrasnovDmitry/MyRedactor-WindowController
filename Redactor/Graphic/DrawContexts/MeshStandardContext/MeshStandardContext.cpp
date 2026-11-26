#include "MeshStandardContext.h"

<<<<<<< HEAD
Redactor::Graphic::DrawContext::MeshStandardDrawContext::MeshStandardDrawContext(void)
=======
Redactor::Graphic::DrawContext::MeshStandardContext::MeshStandardContext(void)
>>>>>>> ec5f8cca959bdc2e93115a7b6e5ce30430c822de
{
    this->isVisible = true;
    this->vertexContext = Redactor::Graphic::DrawContext::Vertex3DStandardContext();
    this->edgeContext = Redactor::Graphic::DrawContext::Line3DStandardContext();
}

<<<<<<< HEAD
Redactor::Graphic::DrawContext::MeshStandardDrawContext::MeshStandardDrawContext(const Redactor::Graphic::DrawContext::MeshStandardDrawContext& other)
=======
Redactor::Graphic::DrawContext::MeshStandardContext::MeshStandardContext(Redactor::Graphic::DrawContext::Vertex3DStandardContext vertexContext, Redactor::Graphic::DrawContext::Line3DStandardContext edgeContext)
{
    this->isVisible = true;
    this->vertexContext = vertexContext;
    this->edgeContext = edgeContext;
}

Redactor::Graphic::DrawContext::MeshStandardContext::MeshStandardContext(const Redactor::Graphic::DrawContext::MeshStandardContext& other)
>>>>>>> ec5f8cca959bdc2e93115a7b6e5ce30430c822de
{
    this->isVisible = other.isVisible;
    this->vertexContext = other.vertexContext;
    this->edgeContext = other.edgeContext;
}

<<<<<<< HEAD
Redactor::Graphic::DrawContext::MeshStandardDrawContext::MeshStandardDrawContext(Redactor::Graphic::DrawContext::MeshStandardDrawContext&& other) noexcept
=======
Redactor::Graphic::DrawContext::MeshStandardContext::MeshStandardContext(Redactor::Graphic::DrawContext::MeshStandardContext&& other) noexcept
>>>>>>> ec5f8cca959bdc2e93115a7b6e5ce30430c822de
{
    this->isVisible = other.isVisible;
    this->vertexContext = other.vertexContext;
    this->edgeContext = other.edgeContext;
}

<<<<<<< HEAD
Redactor::Graphic::DrawContext::MeshStandardDrawContext& Redactor::Graphic::DrawContext::MeshStandardDrawContext::operator=(const Redactor::Graphic::DrawContext::MeshStandardDrawContext& other)
=======
Redactor::Graphic::DrawContext::MeshStandardContext& Redactor::Graphic::DrawContext::MeshStandardContext::operator=(const Redactor::Graphic::DrawContext::MeshStandardContext& other)
>>>>>>> ec5f8cca959bdc2e93115a7b6e5ce30430c822de
{
    if(this != &other)
    {
        this->isVisible = other.isVisible;
        this->vertexContext = other.vertexContext;
        this->edgeContext = other.edgeContext;
    }
    return *this;
}

<<<<<<< HEAD
Redactor::Graphic::DrawContext::MeshStandardDrawContext& Redactor::Graphic::DrawContext::MeshStandardDrawContext::operator=(Redactor::Graphic::DrawContext::MeshStandardDrawContext&& other) noexcept
=======
Redactor::Graphic::DrawContext::MeshStandardContext& Redactor::Graphic::DrawContext::MeshStandardContext::operator=(Redactor::Graphic::DrawContext::MeshStandardContext&& other) noexcept
>>>>>>> ec5f8cca959bdc2e93115a7b6e5ce30430c822de
{
    if(this != &other)
    {
        this->isVisible = other.isVisible;
        this->vertexContext = other.vertexContext;
        this->edgeContext = other.edgeContext;
    }
    return *this;
}

<<<<<<< HEAD
Redactor::Graphic::DrawContext::MeshStandardDrawContext::~MeshStandardDrawContext(void)
=======
Redactor::Graphic::DrawContext::MeshStandardContext::~MeshStandardContext(void)
>>>>>>> ec5f8cca959bdc2e93115a7b6e5ce30430c822de
{
    this->isVisible = false;
}

<<<<<<< HEAD
bool Redactor::Graphic::DrawContext::MeshStandardDrawContext::IsVisible(void) const
=======
bool Redactor::Graphic::DrawContext::MeshStandardContext::IsVisible(void) const
>>>>>>> ec5f8cca959bdc2e93115a7b6e5ce30430c822de
{
    return this->isVisible;
}

<<<<<<< HEAD
void Redactor::Graphic::DrawContext::MeshStandardDrawContext::SetVisibility(bool visibility)
{
    this->isVisible = visibility;
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
=======
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
>>>>>>> ec5f8cca959bdc2e93115a7b6e5ce30430c822de
