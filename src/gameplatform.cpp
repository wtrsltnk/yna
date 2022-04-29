#include "gameplatform.h"
#include "game.h"

using namespace yna::framework;

GamePlatform::GamePlatform(
    Game *game)
    : _game(game)
{
    _game->_platform = this;
}

void GamePlatform::SetGameWindow(
    GameWindow *gameWindow)
{
    this->_game->_window = gameWindow;
}

void GamePlatform::SetGraphicsDevice(
    graphics::GraphicsDevice *graphicsDevice)
{
    this->_game->_graphicsDevice = graphicsDevice;
}
