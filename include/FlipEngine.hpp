#pragma once
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "StaticObstacles.hpp"

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
        vector<StaticObstacles> obstacles;

        void updateGame();
        void processInput();
        void render();
};