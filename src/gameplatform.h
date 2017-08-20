#ifndef GAMEPLATFORM_H
#define GAMEPLATFORM_H

#include "property.h"

namespace yna
{

namespace framework
{

class GamePlatform
{
public:
    GamePlatform();

    static GamePlatform* PlatformCreate(class Game* game);

    property<class GameWindow*> Window;

    virtual bool BeforeDraw() = 0;
    virtual void AfterDraw() = 0;
    virtual void RunLoop() = 0;
    virtual void Exit() = 0;
};

}

}

#endif // GAMEPLATFORM_H
