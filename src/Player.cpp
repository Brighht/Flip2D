#include "Player.hpp"

Player::Player(const std::string &userName){
    this->userName = userName;

    position = sf::Vector2f(100.f,100.f);
    velocity = sf::Vector2f(0.f,0.f);
    acceleration = sf::Vector2f(0.f,0.f);
    speed = 500.f;
    friction = 0.9f;
    // jumpVelocity = -600.f;
    // isOnGround = false;
    // gravity = 1500.f;

    
    shape.setFillColor(sf::Color::Blue);
    shape.setSize(sf::Vector2f(50.f,50.f));
    shape.setPosition(position);
    
};

void Player::handleInput(){
    acceleration = sf::Vector2f(0.f,0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) velocity.y = -speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) velocity.y = speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) velocity.x = -speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) velocity.x = speed;
}


void Player::update(float dt, const std::vector<StaticObstacles>& obstacles){
    velocity += acceleration * dt;

    sf::Vector2f nextPosition = position + velocity * dt;
    sf::FloatRect nextBounds = shape.getGlobalBounds();
    nextBounds.left = nextPosition.x;
    nextBounds.top = nextPosition.y;

    for(auto &obstacle : obstacles){
        if(nextBounds.intersects(obstacle.getShape().getGlobalBounds())){
            velocity = sf::Vector2f(0.f,0.f);
            return; //Don't move from this frame
        }
    }

    position = nextPosition;
    velocity *= friction;

    shape.setPosition(position);

    //This keeps the player in the pixel frame
    sf::Vector2f size = shape.getSize();
    float maxX = 800 - size.x;
    float maxY = 600 - size.y;

    if(position.x > maxX) position.x = maxX;
    if(position.x < 0) position.x = 0;
    if(position.y > maxY) position.y = maxY;
    if(position.y < 0) position.y = 0;
}

void Player::draw(sf::RenderWindow &window){
    window.draw(shape);
}