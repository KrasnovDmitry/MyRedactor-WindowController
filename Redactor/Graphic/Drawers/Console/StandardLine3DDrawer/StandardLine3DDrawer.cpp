#include "StandardLine3DDrawer.h"
#include "iostream"

void Redactor::Graphic::Drawers::Console::StandardLine3DDrawer::Draw(const Redactor::Graphic::Line3D& object, const Redactor::Graphic::DrawContext::Line3DStandardContext& context) const
{
    Redactor::Graphic::Colors::Color4B start_col = context.GetStartColor();
    Redactor::Graphic::Colors::Color4B end_col = context.GetEndColor();

    Redactor::Graphic::UVs::UV2D start_uv = context.GetStartTextureCoords();
    Redactor::Graphic::UVs::UV2D end_uv = context.GetEndTextureCoords();

    std::cout << "Line3D: { " << object.GetStartX() << "; " << object.GetStartY() << "; " << object.GetStartZ() << " } -> { " << object.GetEndX() << "; " << object.GetEndY() << "; " << object.GetEndZ() << " }" << std::endl;
    std::cout << "Line width: " << context.GetWidth() << std::endl;
    std::cout << "Start Color: Color4B { " << (int)start_col.GetR() << "; " << (int)start_col.GetG() << "; " << (int)start_col.GetB() << "; " << (int)start_col.GetA() << " }" << std::endl;
    std::cout << "End Color: Color4B { " << (int)end_col.GetR() << "; " << (int)end_col.GetG() << "; " << (int)end_col.GetB() << "; " << (int)end_col.GetA() << " }" << std::endl;
    std::cout << "Start TextureCoords: UV2D { " << start_uv.GetU() << "; " << start_uv.GetV() << "} " << std::endl;
    std::cout << "End TextureCoords: UV2D { " << end_uv.GetU() << "; " << end_uv.GetV() << "} " << std::endl;
    std::cout << "Is Stripped: " << context.IsStripped() << std::endl;
    if(context.IsStripped())
    {
        std::cout << "Strip Factor: " << context.GetStripFactor() << std::endl;
        std::cout << "Strip Pattern: " << std::showbase << std::hex << context.GetStripPattern() << std::noshowbase << std::dec << std::endl;
    }
    std::cout << "Visibility: " << context.IsVisible() << std::endl;
}
