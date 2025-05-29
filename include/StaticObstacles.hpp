#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class StaticObstacles {
    private:
        RectangleShape shape;

    public:
        StaticObstacles(Vector2f position, Vector2f size);
        void draw(RenderWindow &window);
        const RectangleShape& getShape() const;
};