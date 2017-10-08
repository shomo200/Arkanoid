#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "BlocksField.hpp"
#include "Paddle.hpp"
#include "Game.hpp"
#include "GlobalObjects.hpp"

int main()
{
    sf::Event event;
    sf::Clock clock;
    float deltaTime;

    BlocksField blocksField(sf::Vector2f(512.f, 150.f), sf::Vector2f(0.f, 0.f), sf::Color::Yellow, 11, 6);
    Ball ball(10.f, sf::Vector2f(250.f, 400.f), sf::Color::Red, 300.f);
    Paddle paddle(sf::Vector2f(100.f, 10.f), sf::Vector2f(256.f, 450.f), sf::Color::Green, 200.f);

    while (GlobalObjects::window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        while (GlobalObjects::window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                GlobalObjects::window.close();
        }

        ball.Update(deltaTime);
        blocksField.Update(ball);
        paddle.Update(deltaTime);

        GlobalObjects::window.clear(sf::Color::Black);

        blocksField.Draw(GlobalObjects::window);
        ball.Draw(GlobalObjects::window);
        paddle.Draw(GlobalObjects::window);

        GlobalObjects::window.display();
    }

    return 0;
}
