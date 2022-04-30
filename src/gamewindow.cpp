#include "gamewindow.h"

using namespace yna::framework;

GameWindow::GameWindow()
    : _clientSizeWidth(100),
      _clientSizeHeight(100),
      Handle(_handle),
      ClientSizeWidth(_clientSizeWidth),
      ClientSizeHeight(_clientSizeHeight)
{}

GameWindow::~GameWindow() {}

void GameWindow::OnClientSizeChanged()
{
    // TODO : raise ClientSizeChanged event
}
