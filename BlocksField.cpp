#include <cmath>
#include "BlocksField.hpp"

BlocksField::BlocksField(const sf::Vector2f & size, const sf::Vector2f & position, const sf::Color & color, int columns, int rows)
{
    sf::Vector2f blockSize(size.x / columns, size.y / rows);

    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            blocks.push_back(Block(blockSize - sf::Vector2f(4.f, 4.f), position + sf::Vector2f(blockSize.x * i + 2.f, blockSize.y * j + 2.f), color));
        }
    }
}

bool BlocksField::checkCollision(const Ball & ball, const Block & block)
{
    if ( (ball.getX() >= block.left() && ball.getX() <= block.rigth()) ||
         (ball.getY() >= block.top() && ball.getY() <= block.bottom()) )
    {
        if (ball.left() < block.rigth() && ball.rigth() > block.left() && ball.top() < block.bottom() && ball.bottom() > block.top())
            return true;
    }
    else
    {
        auto distance = [](sf::Vector2f x1, sf::Vector2f x2)->float { return std::sqrt( pow(x1.x - x2.x, 2) + pow(x1.y - x2.y, 2) ); };
        if (distance(ball.getPosition(), sf::Vector2f(block.left(), block.top()))    < ball.getRadius() ||
            distance(ball.getPosition(), sf::Vector2f(block.left(), block.bottom())) < ball.getRadius() ||
            distance(ball.getPosition(), sf::Vector2f(block.rigth(), block.top()))   < ball.getRadius() ||
            distance(ball.getPosition(), sf::Vector2f(block.rigth(), block.bottom()))< ball.getRadius() )
            return true;
    }

    return false;
}

void BlocksField::Update(Ball & ball)
{
    blocks.remove_if([&ball, this](const Block & block)->bool { return checkCollision(ball, block); });
}

void BlocksField::Draw(sf::RenderWindow & window)
{
    for (auto &block : blocks)
    {
       block.Draw(window);
    }
}
