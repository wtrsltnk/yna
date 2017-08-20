#include "gameservicecontainer.h"

using namespace yna::framework;

GameServiceContainer::GameServiceContainer() { }

GameServiceContainer::~GameServiceContainer() { }

void GameServiceContainer::AddService(IGameService* service) { }
void GameServiceContainer::RemoveService(const std::string& name) { }
