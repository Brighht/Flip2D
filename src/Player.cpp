#include "Player.hpp"

Player::Player(const std::string &userName){
    this->userName = userName;

    position = sf::Vector2f(100.f,100.f);
    velocity = sf::Vector2f(0.f,0.f);
    acceleration = sf::Vector2f(0.f,0.f);
    speed = 400.f;
    friction = 0.98f;
    jumpVelocity = -800.f;
    isOnGround = false;
    gravity = 2000.f;

    
    shape.setFillColor(sf::Color::Blue);
    shape.setSize(sf::Vector2f(50.f,50.f));
    shape.setPosition(position);
    
};

void Player::handleInput() {
    velocity.x = 0.f; 

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) velocity.x = -speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) velocity.x = speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isOnGround) {
        velocity.y = jumpVelocity;
        isOnGround = false;
    }
}



void Player::update(float dt, const std::vector<StaticObstacles>& obstacles) {
    velocity.x *= friction;
    velocity.y += gravity * dt;

    sf::Vector2f nextPosition = position;
    nextPosition.x += velocity.x * dt;
    nextPosition.y += velocity.y * dt;


    sf::FloatRect nextBounds = shape.getGlobalBounds();
    nextBounds.left = nextPosition.x;
    nextBounds.top = nextPosition.y;

    isOnGround = false;

    // Collision check
    for (auto& obstacle : obstacles) {
        sf::FloatRect obstacleBounds = obstacle.getShape().getGlobalBounds();

        if (nextBounds.intersects(obstacleBounds)) {
            // Hit the ground
            if (velocity.y > 0.f) {
                isOnGround = true;
                velocity.y = 0.f;

                nextPosition.y = obstacle.getShape().getPosition().y - shape.getSize().y;
            }

            if (velocity.x != 0.f) {
                velocity.x = 0.f;
            }
        }
    }

    position = nextPosition;
    shape.setPosition(position);

    // Keep inside window bounds (optional for now)
    sf::Vector2f size = shape.getSize();
    float maxX = 800 - size.x;
    float maxY = 600 - size.y;

    if (position.x > maxX) position.x = maxX;
    if (position.x < 0) position.x = 0;
    if (position.y > maxY) position.y = maxY;
    if (position.y < 0) position.y = 0;
}


void Player::draw(sf::RenderWindow &window){
    window.draw(shape);
}