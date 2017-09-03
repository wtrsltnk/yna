#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

#include "../property.h"
#include "../iserviceprovider.h"

#include <string>
#include <vector>

namespace yna
{

namespace framework
{

namespace graphics
{
class Effect;
class Model;
class SpriteFont;
class Texture2D;
}

namespace content
{

enum class ContentTypes
{
    Effect,
    Model,
    SpriteFont,
    Texture2D,
};

class ContentManager
{
    std::string _rootDirectory;
    IServiceProvider* _serviceProvider;
public:
    ContentManager(IServiceProvider* serviceProvider);
    ContentManager(IServiceProvider* serviceProvider, const std::string& rootFirectory);

    // Gets or sets the root directory associated with this ContentManager.
    get_property<std::string> RootDirectory;
    get_property<IServiceProvider*> ServiceProvider;

    // Loads an asset that has been processed by the Content Pipeline.
    graphics::Effect* LoadEffect(const std::string& name);
    graphics::Model* LoadModel(const std::string& name);
    graphics::SpriteFont* LoadSpriteFont(const std::string& name);
    graphics::Texture2D* LoadTexture2D(const std::string& name);

    // Disposes all data that was loaded by this ContentManager.
    void Unload();

    // Low-level worker method that reads asset data.
    bool ReadAsset(const std::string& assetName, std::vector<unsigned char>& buffer);
};

}

}

}

#endif // CONTENTMANAGER_H
