#include "Player.hpp"

Player::Player(const std::string &userName){
    this->userName = userName;

    position = sf::Vector2f(100.f,100.f);
    velocity = sf::Vector2f(0.f,0.f);
    acceleration = sf::Vector2f(0.f,0.f);
    speed = 600.f;
    friction = 0.9f;
    jumpVelocity = -600.f;
    isOnGround = false;
    gravity = 1500.f;

    
    shape.setFillColor(sf::Color::Blue);
    shape.setSize(sf::Vector2f(50.f,50.f));
    shape.setPosition(position);
    
};

void Player::handleInput(){
    acceleration = sf::Vector2f(0.f,0.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        acceleration.y = -speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        acceleration.y = speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        acceleration.x = -speed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        acceleration.x = -speed;
    }
}

