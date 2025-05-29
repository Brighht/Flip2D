#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Player {
private:
    std::string userName;
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float speed;
    float gravity;
    float jumpVelocity;
    bool isOnGround;

public:
    Player(const std::string& userName);

    void update(float dt);
    void draw(sf::RenderWindow& window);
    void handleInput();

    const sf::RectangleShape& getShape() const;
    void setOnGround(bool value);
    bool onGround() const;
};
