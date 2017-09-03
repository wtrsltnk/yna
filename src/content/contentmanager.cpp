#include "contentmanager.h"
#include "../graphics/effect.h"
#include "../graphics/model.h"
#include "../graphics/spritefont.h"
#include "../graphics/texture2d.h"
#include "pipline/textureimporter.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace yna::framework;
using namespace yna::framework::content;

ContentManager::ContentManager(IServiceProvider* serviceProvider)
    : _serviceProvider(serviceProvider),
      RootDirectory(_rootDirectory), ServiceProvider(_serviceProvider)
{ }

ContentManager::ContentManager(IServiceProvider* serviceProvider, const std::string& rootFirectory)
    : _serviceProvider(serviceProvider), _rootDirectory(rootFirectory),
      RootDirectory(_rootDirectory), ServiceProvider(_serviceProvider)
{ }

graphics::Effect* ContentManager::LoadEffect(const std::string& name) { return nullptr; }

graphics::Model* ContentManager::LoadModel(const std::string& name) { return nullptr; }

graphics::SpriteFont* ContentManager::LoadSpriteFont(const std::string& name) { return nullptr; }

graphics::Texture2D* ContentManager::LoadTexture2D(const std::string& name)
{
    auto textureImporter = _serviceProvider->GetService("TextureImporter");

    if (textureImporter == nullptr)
    {
        return nullptr;
    }

    // todo: determine full filename
    std::string filename = name;

//    std::vector<unsigned char> buffer;
//    if (!ReadAsset(name, buffer))
//    {
//        return nullptr;
//    }

    auto textureContent = ((pipline::TextureImporter*)textureImporter)->Import(filename);

//    int w, h, comp;

//    auto texture = new graphics::Texture2D();

//    Color* colorData = (Color*)stbi_load_from_memory(buffer.data(), buffer.size(), &w, &h, &comp, 4);

//    std::vector<Color> colorVector(colorData, colorData + (w * h));
//    texture->SetData(colorVector, w, h);

//    delete []colorData;

//    return texture;
}

void ContentManager::Unload()
{ }

bool ContentManager::ReadAsset(const std::string& assetName, std::vector<unsigned char>& buffer)
{
    // todo: determine full filename
    std::string filename = assetName;

    buffer.clear();

    auto file = fopen(filename.c_str(), "r");
    if (file != nullptr)
    {
        fseek(file, 0, SEEK_END);
        auto size = ftell(file);
        fseek(file, 0, SEEK_SET);

        std::vector<unsigned char> buf(size);
        fread(reinterpret_cast<unsigned char *>(buf.data()), sizeof(unsigned char), size + 1, file);

        fclose(file);
        buffer.swap(buf);

        return true;
    }

    return false;
}
