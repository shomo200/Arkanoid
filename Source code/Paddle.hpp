#ifndef PADDLE_HPP_
#define PADDLE_HPP_

#include <SFML/Graphics.hpp>

class Paddle
{
private:
    sf::RectangleShape paddle;
    float speed;

public:
    Paddle(const sf::Vector2f & size, const sf::Vector2f & position, const sf::Color & color, float speed);

    void Update(float deltaTime);

    void Draw(sf::RenderWindow & window);
};

#endif // PADDLE_HPP_
