#include "screen.hpp"

GameDrawable::GameDrawable(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, int rows, int columns, int level)
        : blocksField(size, position, color, rows, columns, level) {}


void GameDrawable::Draw(sf::RenderWindow &window, float deltaTime)
{
        blocksField.Draw(window);
        Game::Draw(window);
        Game::Update(deltaTime, blocksField);
}


