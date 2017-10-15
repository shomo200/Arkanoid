#include "Game.hpp"
#include <iostream>

Ball * Game::ball = nullptr;
void Game::Update(float deltaTime)
{
    static int i = 0;
    if (ball != nullptr && !ball->Update(deltaTime))
    {
        delete ball;
        ball = nullptr;
    }
    /*if (ball != nullptr)
        std::cout << "Ball " << i++ << std::endl;*/
}

void Game::Draw(sf::RenderWindow & window)
{
    if (ball != nullptr)
        ball->Draw(window);
}
