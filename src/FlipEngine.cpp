#include "FlipEngine.hpp"

FlipEngine::FlipEngine() 
    : gameWindow(VideoMode(800,600), "Flip2D"),
      Player("Player1"),
      deltaTime(0.f)
      {
        obstacles.emplace_back(sf::Vector2f(100.f,50.f), sf::Vector2f(600.f,50.f));
      }
