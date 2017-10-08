#ifndef BALL_HPP_
#define BALL_HPP_

#include <SFML/Graphics.hpp>
#include "GlobalObjects.hpp"

class Ball
{
private:
    sf::CircleShape circle;
    float speed;
    sf::Vector2f velocity;

public:
    Ball(float radius, const sf::Vector2f & position, const sf::Color & color, float speed);

    void Update(float deltaTime);

    void Draw(sf::RenderWindow & window);

    float left()   const { return circle.getPosition().x - circle.getRadius(); }
    float rigth()  const { return circle.getPosition().x + circle.getRadius(); }
    float top()    const { return circle.getPosition().y - circle.getRadius(); }
    float bottom() const { return circle.getPosition().y + circle.getRadius(); }

    float getX() const { return circle.getPosition().x; }
    float getY() const { return circle.getPosition().y; }
    sf::Vector2f getPosition() const { return circle.getPosition(); }
    float getRadius() const { return circle.getRadius(); }
};

#endif // BALL_HPP_
