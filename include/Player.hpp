#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <StaticObstacles.hpp>

class Player {
private:
    std::string userName;
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float speed;
    float gravity;
    float friction;
    float jumpVelocity;
    bool isOnGround;

public:
    Player(const std::string& userName);

    void update(float dt, const std::vector<StaticObstacles>& obstacles);
    void draw(sf::RenderWindow& window);
    void handleInput();

    const sf::RectangleShape& getShape() const;
    void setOnGround(bool value);
    bool onGround() const;
};
