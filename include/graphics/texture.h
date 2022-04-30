#ifndef TEXTURE_H
#define TEXTURE_H

#include "graphicsresource.h"
#include "surfaceformat.h"

namespace yna
{

    namespace framework
    {

        namespace graphics
        {

            class Texture : public GraphicsResource
            {
                SurfaceFormat _format;

            public:
                Texture(class GraphicsDevice *graphicsDevice);

                get_property<SurfaceFormat> Format;
            };

        } // namespace graphics

    } // namespace framework

} // namespace yna

#endif // TEXTURE_H
