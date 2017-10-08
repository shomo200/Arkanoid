#include "Ball.hpp"

Ball::Ball(float radius, const sf::Vector2f & position, const sf::Color & color, float speed)
{
    circle.setRadius(radius);
    circle.setPosition(position);
    circle.setFillColor(color);
    circle.setOrigin(radius, radius);

    this->speed = speed;
    velocity = sf::Vector2f(-speed, -speed);
}

void Ball::Update(float deltaTime)
{
    circle.move(velocity * deltaTime);

    if (left() < 0.f)
        velocity.x = -velocity.x;
    if (rigth() > 512.f)
        velocity.x = -velocity.x;
    if (top() < 0.f)
        velocity.y = -velocity.y;
    if (bottom() > 512.f)
        velocity.y = -velocity.y;
}

void Ball::Draw(sf::RenderWindow & window)
{
    window.draw(circle);
}
