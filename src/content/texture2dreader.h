#ifndef TEXTURE2DREADER_H
#define TEXTURE2DREADER_H

#include "content/contenttypereader.h"
#include "graphics/texture2d.h"
#include "content/contenttypereadermanager.h"

namespace yna
{

namespace framework
{

namespace content
{

class TextureContentTypeReaderFactory : public ContentTypeReaderFactory
{
public:
    TextureContentTypeReaderFactory();

    void Init();

    virtual ContentTypeReader* Create();
};

class Texture2DReader : public ContentTypeReader
{
public:
    Texture2DReader();

    virtual void* Read(ContentReader* input);

    static TextureContentTypeReaderFactory textureContentTypeReaderFactory;
};

}

}

}

#endif // TEXTURE2DREADER_H
