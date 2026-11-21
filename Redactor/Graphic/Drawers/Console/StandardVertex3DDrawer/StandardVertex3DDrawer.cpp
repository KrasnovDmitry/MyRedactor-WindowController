#include "StandardVertex3DDrawer.h"
#include "iostream"

void Redactor::Graphic::Drawers::Console::StandardVertex3DDrawer::Draw(const Redactor::Graphic::Vertex3D& object, const Redactor::Graphic::DrawContext::Vertex3DStandardContext& context) const
{
    Redactor::Graphic::Colors::Color4B col = context.GetColor();
    Redactor::Graphic::UVs::UV2D uv = context.GetTextureCoords();

    std::cout << "Vertex3D { " << object.GetX() << "; " << object.GetY() << "; " << object.GetZ() << " }" << std::endl;
    std::cout << "Vertex Size: " << context.GetSize() << std::endl;
    std::cout << "Color: Color4B { " << (int)col.GetR() << "; " << (int)col.GetG() << "; " << (int)col.GetB() << "; " << (int)col.GetA() << " }" << std::endl;
    std::cout << "TextureCoords: UV2D { " << uv.GetU() << "; " << uv.GetV() << "} " << std::endl;
    std::cout << "Visibility: " << context.IsVisible() << std::endl;
}
