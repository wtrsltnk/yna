#include "graphics/texture2d.h"
#include "graphics/graphicsdevice.h"

using namespace yna::framework::graphics;

Texture2D::Texture2D(graphics::GraphicsDevice* graphicsDevice, int width, int height)
    : Texture(graphicsDevice), Bounds(_bounds), Height([this] () { return _bounds.Height; }), Width([this] () { return _bounds.Width; })
{
    _bounds.Width = width;
    _bounds.Height = height;
}

void Texture2D::GetData(std::vector<Color>& data)
{ }

void Texture2D::GetData(std::vector<Color>& data, int width, int height)
{ }

void Texture2D::SetData(const std::vector<Color>& data)
{ }

void Texture2D::SetData(const std::vector<Color>& data, int width, int height)
{ }
