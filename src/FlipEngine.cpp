#include "FlipEngine.hpp"
#include "Player.hpp"

FlipEngine::FlipEngine() 
    : gameWindow(VideoMode(800,600), "Flip2D"),
      player("Brrrp"),
      deltaTime(0.f)
      {
        obstacles.emplace_back(sf::Vector2f(100.f,50.f), sf::Vector2f(600.f,50.f));
      }

void FlipEngine::run(){
    while(gameWindow.isOpen()){
        deltaTime = dtClock.restart().asSeconds();
        
        processInput();
        updateGame();
        render();
    }
}

void FlipEngine::processInput(){
    sf::Event userActivity;
    while(gameWindow.pollEvent(userActivity)){
        if(userActivity.type == sf::Event::Closed){
            gameWindow.close();
        }
    }

    player.handleInput();
}

void FlipEngine::updateGame(){
    player.update(deltaTime,obstacles);

}

void FlipEngine::render(){
    gameWindow.clear();

    for(auto &obs: obstacles){
        obs.draw(gameWindow);
    }
    player.draw(gameWindow);
    gameWindow.display();
}