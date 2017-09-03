#ifndef GAMESERVICECONTAINER_H
#define GAMESERVICECONTAINER_H

#include "iserviceprovider.h"

#include <map>
#include <string>

namespace yna
{

namespace framework
{

class GameServiceContainer : public IServiceProvider
{
    std::map<std::string, IGameService*> _services;
public:
    GameServiceContainer();
    virtual ~GameServiceContainer();

    void AddService(IGameService* service);
    void RemoveService(const std::string& name);
    IGameService* GetService(const std::string& name);
};

}

}

#endif // GAMESERVICECONTAINER_H
