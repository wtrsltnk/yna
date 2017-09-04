#include "texture2dreader.h"
#include "../graphics/texture2d.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace yna::framework::content;

Texture2DReader::Texture2DReader()
    : ContentTypeReader(Type(typeid(graphics::Texture2D)))
{ }

void* Texture2DReader::Read(ContentReader* input)
{
    std::vector<unsigned char> buffer;
    if (!input->ReadBytes(input->BaseStream->Length(), buffer))
    {
        return nullptr;
    }

    int w, h, comp;

    auto texture = new graphics::Texture2D();

    Color* colorData = (Color*)stbi_load_from_memory(buffer.data(), buffer.size(), &w, &h, &comp, 4);

    std::vector<Color> colorVector(colorData, colorData + (w * h));
    texture->SetData(colorVector, w, h);

    delete []colorData;

    return texture;
}

TextureContentTypeReaderFactory::TextureContentTypeReaderFactory()
{ }

void TextureContentTypeReaderFactory::Init()
{
    AddContentTypeReader(Type(typeid(yna::framework::graphics::Texture2D)), this);
}

ContentTypeReader* TextureContentTypeReaderFactory::Create()
{
    return new Texture2DReader();
}

TextureContentTypeReaderFactory Texture2DReader::textureContentTypeReaderFactory;

