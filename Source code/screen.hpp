
#ifndef SCREEN_HPP_
#define SCREEN_HPP_

#include <SFML/Graphics.hpp>
#include "Game.hpp"


class Drawable {
public:
    virtual void Draw(sf::RenderWindow &window ,float deltaTime ) = 0; 
};


class GameDrawable : public Drawable {
public:
    GameDrawable(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, int rows, int columns, int level);

    void Draw(sf::RenderWindow &window, float deltaTime) override ;

private:
    BlocksField blocksField;
};


class GameStart : public Drawable{
    public:
    GameStart();
    void Draw(sf::RenderWindow &window, float deltaTime) override ;

};


#endif