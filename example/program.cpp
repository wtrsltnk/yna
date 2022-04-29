#include <game.h>
#include <gametime.h>
#include <graphicsdevicemanager.h>
#include <iostream>
#include <random>
#include <thread>

#include <color.h>
#include <graphics/texture2d.h>

class ExampleGame : public yna::framework::Game
{
public:
    std::unique_ptr<yna::framework::GraphicsDeviceManager> _graphics;

    ExampleGame()
    {
        _graphics = std::make_unique<yna::framework::GraphicsDeviceManager>(this);

        auto texture = Content->LoadTexture2D("test");
    }

    virtual void Update(
        const yna::framework::GameTime &gameTime)
    {
        //        std::cout << "Update\n"
        //                  << gameTime.TotalGameTime << "\n"
        //                  << gameTime.ElapsedGameTime << std::endl;
        auto ms = 10 + (std::rand() % 10);
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    virtual void Draw(
        const yna::framework::GameTime &gameTime)
    {
        GraphicsDevice->Clear(yna::framework::Color(76, 152, 255, 255));

        //        std::cout << "Draw\n"
        //                  << gameTime.TotalGameTime << "\n"
        //                  << gameTime.ElapsedGameTime << std::endl;
        auto ms = 10 + (std::rand() % 10);
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }
};

int main(
    int argc,
    char *argv[])
{
    auto game = ExampleGame();

    game.Run();

    return 0;
}
