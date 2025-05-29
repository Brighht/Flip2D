#include <SFML/Graphics.hpp>
#include "Player.hpp"

using namespace sf;

class FlipEngine {
    public : 
        FlipEngine();
        void run();

    private:
        RenderWindow gameWindow;
        Clock dtClock;
        float deltaTime;

        Player player;
        

        void updateGame();
        void processInput();
        void render();
};