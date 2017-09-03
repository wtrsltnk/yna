#include "gameservicecontainer.h"
#include <algorithm>

using namespace yna::framework;

GameServiceContainer::GameServiceContainer() { }

GameServiceContainer::~GameServiceContainer() { }

void GameServiceContainer::AddService(IGameService* service) { }

void GameServiceContainer::RemoveService(const std::string& name) { }

IGameService* GameServiceContainer::GetService(const std::string &name)
{
    auto found = _services.find(name);

    if (found != _services.end()) return found->second;

    return nullptr;
}
