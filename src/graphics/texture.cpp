#include "graphics/texture.h"
#include "graphics/graphicsdevice.h"

using namespace yna::framework::graphics;

Texture::Texture(graphics::GraphicsDevice* graphicsDevice)
    : GraphicsResource(graphicsDevice), Format(_format)
{ }
