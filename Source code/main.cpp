#include <SFML/Graphics.hpp>
#include <iostream>
#include "GlobalObjects.hpp"
#include "BlocksField.hpp"
#include "Paddle.hpp"
#include "Block.hpp"
#include "screen.hpp"


int main()
{
    sf::Event event;
    sf::Clock clock;
    float deltaTime;

    GlobalObjects::initializeWindow(true);


    Game::createBall(Ball(10.f, sf::Vector2f(225.0710f, 400.f), sf::Color::Red, 180.f, 90.f));

    Game::createPaddle(Paddle(sf::Vector2f(100.f, 10.f), sf::Vector2f(256.f, 450.f), sf::Color::Green, 200.f));

    GameDrawable gameDrawable(sf::Vector2f(GlobalObjects::windowWidth, 200.f), sf::Vector2f(0.f, 0.f), sf::Color::Yellow, 9, 7, 2);
   

    while (GlobalObjects::window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        while (GlobalObjects::window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                GlobalObjects::window.close();
        }


        GlobalObjects::window.clear(sf::Color::Black);


        gameDrawable.Draw(GlobalObjects::window , deltaTime);
      


        GlobalObjects::window.display();
    }

    return 0;
}



