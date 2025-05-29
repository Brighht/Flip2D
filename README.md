# Flip2D
Flip2D is a lightweight 2D platformer engine built in C++ using SFML. It features a custom physics system with gravity, jump mechanics, and collision handling. The engine includes a smooth camera system that follows the player using an adjustable view, and supports full gameplay replays by recording and replaying player inputs over time. Designed with modular architecture, Flip2D is optimized for fast iteration, clear separation of update and render logic, and future extensibility into sprite-based animation and level design.

## File Structure( As of creation)
```m
Flip2D/
├── include/
│   ├── FlipEngine.hpp
│   ├── Player.hpp
│   ├── Obstacles.hpp
│   ├── Enemy.hpp
├── src/
│   ├── FlipEngine.cpp
│   ├── Player.cpp
│   ├── Obstacles.cpp
│   ├── Enemy.cpp
├── assets/            # Optional: for textures, sounds, etc.
├── main.cpp
├── CMakeLists.txt     # Or Makefile if you're using one
```