#ifndef GAME_H
#define GAME_H

#include "content/contentmanager.h"
#include "graphics/graphicsdevice.h"
#include "platform.h"
#include "property.h"

#include <chrono>

namespace yna
{

    namespace framework
    {

        class Game
        {
        public:
            Game();
            virtual ~Game();

            get_property<content::ContentManager *> Content;
            get_property<graphics::GraphicsDevice *> GraphicsDevice;
            get_property<class GameServiceContainer *> Services;
            get_property<class GameComponentCollection *> Components;
            get_property<class GameWindow *> Window;

            // Gets or sets a value indicating whether to use fixed time steps.
            property<bool> IsFixedTimeStep;
            // Gets or sets the target time between calls to Update when IsFixedTimeStep is true.
            property<double> TargetElapsedTime;

        public:
            // Call this method to initialize the game, begin running the game loop, and start processing events for the game.
            void Run();
            // Updates the game's clock and calls Update and Draw.
            void Tick();
            // Exits the game.
            void Exit();

        protected:
            // Called after the Game and GraphicsDevice are created, but before LoadContent.
            virtual void Initialized() {}
            // Allows a Game to attempt to free resources and perform other cleanup operations before garbage collection reclaims the Game.
            virtual void Finalize() {}
            // Called when graphics resources need to be loaded.
            virtual void LoadContent() {}
            // Called when graphics resources need to be unloaded. Override this method to unload any game-specific graphics resources.
            virtual void UnloadContent() {}

            // Starts the drawing of a frame. This method is followed by calls to Draw and EndDraw.
            virtual bool BeginDraw() { return true; }
            // Called when the game determines it is time to draw a frame.
            virtual void Draw(const class GameTime &gameTime) {}
            // Ends the drawing of a frame. This method is preceeded by calls to Draw and BeginDraw.
            virtual void EndDraw() {}

            // Called after all components are initialized but before the first update in the game loop.
            virtual void BeginRun() {}
            // Called when the game has determined that game logic needs to be processed.
            virtual void Update(const class GameTime &gameTime) {}
            // Called after the game loop has stopped running before exiting.
            virtual void EndRun() {}

        private:
            friend class GamePlatform;

            std::chrono::high_resolution_clock::time_point _gameStart;
            std::chrono::high_resolution_clock::time_point _lastUpdate;
            std::chrono::high_resolution_clock::time_point _lastDraw;
            double _targetElapsedTime;
            class GameWindow *_window;
            graphics::GraphicsDevice *_graphicsDevice;
            class GameServiceContainer *_services;
            class GameComponentCollection *_components;
            class GamePlatform *_platform;
            content::ContentManager *_content;
        };

    } // namespace framework

} // namespace yna

#endif // GAME_H
