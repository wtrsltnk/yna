#ifndef GAMESERVICECONTAINER_H
#define GAMESERVICECONTAINER_H

#include <map>
#include <string>
#include <algorithm>

namespace yna
{

namespace framework
{

class IGameService
{
public:
    virtual ~IGameService() { }

    virtual const std::string& Name() const = 0;
};

class GameServiceContainer
{
    std::map<std::string, IGameService*> _services;
public:
    GameServiceContainer();
    virtual ~GameServiceContainer();

    void AddService(IGameService* service);
    void RemoveService(const std::string& name);
    template<class T> T* GetService(const std::string& name)
    {
        auto found = std::find_if(_services.begin(), _services.end, [name] (IGameService* service) -> bool { return service->Name() == name; });

        if (found != _services.end()) return (T*)(*found);

        return nullptr;
    }
};

}

}

#endif // GAMESERVICECONTAINER_H
