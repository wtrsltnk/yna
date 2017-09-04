#ifndef CONTENTMANAGER_H
#define CONTENTMANAGER_H

#include "../property.h"
#include "../type.h"
#include "../iserviceprovider.h"
#include "../stream.h"

#include <string>
#include <vector>
#include <map>
#include <algorithm>

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
    std::map<std::string, void*> _loadedAssets;
public:
    ContentManager(IServiceProvider* serviceProvider);
    ContentManager(IServiceProvider* serviceProvider, const std::string& rootFirectory);

    // Gets or sets the root directory associated with this ContentManager.
    get_property<std::string> RootDirectory;
    get_property<IServiceProvider*> ServiceProvider;

    // Loads an asset that has been processed by the Content Pipeline.
    graphics::Effect* LoadEffect(const std::string& assetName);
    graphics::Model* LoadModel(const std::string& assetName);
    graphics::SpriteFont* LoadSpriteFont(const std::string& assetName);
    graphics::Texture2D* LoadTexture2D(const std::string& assetName);

    // Disposes all data that was loaded by this ContentManager.
    void Unload();

protected:
    void* Load(const std::string& assetName);
    Stream* OpenStream(const std::string& assetName);
};

}

}

}

#endif // CONTENTMANAGER_H
