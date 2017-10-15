#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include "Ball.hpp"

class Game
{
private:
    Game() = delete;

public:
    static void createBall(const Ball & bll) { ball = new Ball(bll); }
    static void Update(float deltaTime);
    static void Draw(sf::RenderWindow & window);
    static Ball * ball;
};

#endif // GAME_HPP_
