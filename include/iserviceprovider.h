#ifndef ISERVICEPROVIDER_H
#define ISERVICEPROVIDER_H

#include <string>

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

class IServiceProvider
{
public:
    virtual ~IServiceProvider() { }

    virtual IGameService* GetService(const std::string& name) = 0;
};

}

}

#endif // ISERVICEPROVIDER_H
