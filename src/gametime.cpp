#include "gametime.h"

using namespace yna::framework;

GameTime::GameTime()
{
    ElapsedGameTime = 0.0;
    IsRunningSlowly = false;
    TotalGameTime = 0.0;
}

GameTime::GameTime(
    double elapsed,
    double total)
{
    ElapsedGameTime = elapsed;
    IsRunningSlowly = false;
    TotalGameTime = total;
}

GameTime::GameTime(
    double elapsed,
    double total,
    bool runningSlowly)
{
    ElapsedGameTime = elapsed;
    IsRunningSlowly = runningSlowly;
    TotalGameTime = total;
}

GameTime::~GameTime() {}
