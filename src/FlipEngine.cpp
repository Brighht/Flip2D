#include "FlipEngine.hpp"
#include "Player.hpp"

FlipEngine::FlipEngine()
    : gameWindow(sf::VideoMode(800, 600), "Flip2D"),
      player("Brrrp"),
      deltaTime(0.f)
{
    // Setup camera view inside body
    cameraView.setSize(800.f, 600.f);
    cameraView.setCenter(player.getShape().getPosition());

    float groundHeight = 50.f;
    obstacles.emplace_back(
        sf::Vector2f(0.f, 600.f - groundHeight),
        sf::Vector2f(800.f, groundHeight)
    );
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
    cameraView.setCenter(player.getShape().getPosition()); // follow player
    gameWindow.setView(cameraView);

    for(auto &obs: obstacles){
        obs.draw(gameWindow);
    }
    player.draw(gameWindow);
    gameWindow.display();
}