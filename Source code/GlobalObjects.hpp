#ifndef GLOBALOBJECTS_HPP_
#define GLOBALOBJECTS_HPP_

#include <SFML/Graphics.hpp>

class GlobalObjects
{
private:
    GlobalObjects() = delete;

public:
    constexpr static const float windowWidth=512, windowHeight=512;
    static sf::RenderWindow window;
};

#endif // GLOBALOBJECTS_HPP_
