#ifndef GAMETIME_H
#define GAMETIME_H

#include "property.h"

namespace yna
{

    namespace framework
    {

        class GameTime
        {
        public:
            GameTime();
            GameTime(double elapsed, double total);
            GameTime(double elapsed, double total, bool runningSlowly);

            virtual ~GameTime();

            // The amount of elapsed game time since the last update.
            property<double> ElapsedGameTime;

            // Gets a value indicating that the game loop is taking doubleer than its TargetElapsedTime. In this case, the game loop can be considered to be running too slowly and should do something to "catch up."
            property<bool> IsRunningSlowly;

            // The amount of game time since the start of the game.
            property<double> TotalGameTime;
        };

    } // namespace framework

} // namespace yna

#endif // GAMETIME_H
