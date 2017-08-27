#include "graphicsdevicemanager.h"
#include "game.h"
#include "gameplatform.h"

using namespace yna::framework;

GraphicsDeviceManager::GraphicsDeviceManager(Game* game)
    : _game(game)
{
    GamePlatform::PlatformCreate(game);
}
