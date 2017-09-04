#include "graphicsdevicemanager.h"
#include "game.h"
#include "gameplatform.h"
#include "gameservicecontainer.h"

using namespace yna::framework;

GraphicsDeviceManager::GraphicsDeviceManager(Game* game)
    : _game(game)
{
    GamePlatform::PlatformCreate(game);
    game->Services->AddService(this);
}

const std::string& GraphicsDeviceManager::Name() const
{
    static std::string s = "GraphicsDeviceManager";
    return s;
}

graphics::GraphicsDevice* GraphicsDeviceManager::GetGraphicsDevice()
{
    return nullptr;
}
