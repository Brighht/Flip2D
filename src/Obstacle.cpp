#include "StaticObstacles.hpp"

StaticObstacles::StaticObstacles(Vector2f position, Vector2f size){
    shape.setSize(size);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(position);
}

const RectangleShape& StaticObstacles::getShape() const{
    return shape;
}

void StaticObstacles::draw(RenderWindow &window){
    window.draw(shape);
}