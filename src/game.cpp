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
      Window([this] () -> yna::framework::GameWindow* { return (Platform != nullptr ? Platform.get()->Window : nullptr); }),
      GraphicsDevice(_graphicsDevice),
      Components(_components),
      Services(_services)
{
    this->IsFixedTimeStep = false;
    this->TargetElapsedTime = 0.0;

    this->_services = new GameServiceContainer();
    this->_components = new GameComponentCollection();
    //this->_content = new ContentManager(_services);

    Platform = GamePlatform::PlatformCreate(this);
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

    Platform->RunLoop();

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

    if (Platform.get()->BeforeDraw() && BeginDraw())
    {
        auto drawTime = GameTime(lastDrawCount, totalCount);

        Draw(drawTime);

        EndDraw();

        Platform.get()->AfterDraw();
    }

    _lastDraw = now;
}

void Game::Exit()
{
    Platform->Exit();
}
