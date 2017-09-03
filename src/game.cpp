#include "game.h"
#include "gamecomponentcollection.h"
#include "gameservicecontainer.h"
#include "gameplatform.h"
#include "gametime.h"
#include <iostream>

using namespace yna::framework;

Game::Game()
    : _graphicsDevice(nullptr),
      _services(nullptr),
      _components(nullptr),
      Window(_window),
      GraphicsDevice(_graphicsDevice),
      Components(_components),
      Services(_services),
      Content(_content)
{
    this->IsFixedTimeStep = false;
    this->TargetElapsedTime = 0.0;

    this->_services = new GameServiceContainer();
    this->_components = new GameComponentCollection();
    this->_content = new content::ContentManager(_services);
}

Game::~Game()
{
    // Destroy GraphicsDevice
}

void Game::Run()
{
    auto now = std::chrono::high_resolution_clock().now();
    _gameStart = now;
    _lastUpdate = now;
    _lastDraw = now;

    Initialized();

    LoadContent();

    BeginRun();

    _platform->RunLoop();

    EndRun();

    UnloadContent();

    Finalize();
}

void Game::Tick()
{
    using namespace std::chrono;
    auto now = high_resolution_clock().now();
    auto lastUpdateCount = duration_cast<duration<double>>(now - _lastUpdate).count();
    auto lastDrawCount = duration_cast<duration<double>>(now - _lastDraw).count();
    auto totalCount = duration_cast<duration<double>>(now - _gameStart).count();

    if (!IsFixedTimeStep || lastUpdateCount > TargetElapsedTime)
    {
        auto updateTime = GameTime(lastUpdateCount, totalCount);

        Update(updateTime);

        _lastUpdate = now;
    }

    if (_platform->BeforeDraw() && BeginDraw())
    {
        auto drawTime = GameTime(lastDrawCount, totalCount);

        Draw(drawTime);

        EndDraw();

        _platform->AfterDraw();
    }

    _lastDraw = now;
}

void Game::Exit()
{
    _platform->Exit();
}
