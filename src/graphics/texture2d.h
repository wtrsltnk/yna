#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include "texture.h"
#include "../color.h"
#include "../rectangle.h"
#include <vector>

namespace yna
{

namespace framework
{

namespace graphics
{

class Texture2D : public Texture
{
    Rectangle _bounds;
public:
    Texture2D();

    get_property<Rectangle> Bounds;
    getref_property<int> Height;
    getref_property<int> Width;

    void GetData(std::vector<Color>& data);
    void GetData(std::vector<Color>& data, int width, int height);

    void SetData(const std::vector<Color>& data);
    void SetData(const std::vector<Color>& data, int width, int height);
};

}

}

}

#endif // TEXTURE2D_H
