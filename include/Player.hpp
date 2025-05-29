#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

class Player {
    private:
        string userName;
        RectangleShape shape;
        Vector2f position;
        Vector2f velocity;
        Vector2f acceleration;
        float speed;
        float gravity;
        float jumpVelocity;
        bool isOnGround;

    public:
        Player(const string &userName);
        void update(float dt);
        void draw(RenderWindow &window);
        void handleInput();

};