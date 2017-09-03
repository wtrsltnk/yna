#ifndef TEXTUREIMPORTER_H
#define TEXTUREIMPORTER_H

#include "graphics/texturecontent.h"

namespace yna
{

namespace framework
{

namespace content
{

namespace pipline
{

class TextureImporter
{
public:
    TextureImporter();

    graphics::TextureContent* Import(const std::string& filename);
};

}

}

}

}

#endif // TEXTUREIMPORTER_H
