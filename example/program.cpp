#include <iostream>
#include <game.h>
#include <gametime.h>
#include <thread>
#include <random>
#include <GL/gl.h>

class ExampleGame : public yna::framework::Game
{
public:
    ExampleGame()
    {
        std::cout << "ExampleGame::ExampleGame()\n";
    }

    virtual void Update(const yna::framework::GameTime& gameTime)
    {
        std::cout << "Update\n"
                  << gameTime.TotalGameTime << "\n"
                  << gameTime.ElapsedGameTime << std::endl;
        auto ms = 10 + (std::rand() % 10);
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    virtual void Draw(const yna::framework::GameTime& gameTime)
    {
        std::cout << "Draw\n"
                  << gameTime.TotalGameTime << "\n"
                  << gameTime.ElapsedGameTime << std::endl;
        auto ms = 10 + (std::rand() % 10);
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));

        glClearColor(0.3f, 0.6f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
};

int main(int argc, char* argv[])
{
    auto game = ExampleGame();

    game.Run();

    return 0;
}
