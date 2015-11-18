#ifndef RENDERHANDLER_HPP
#define RENDERHANDLER_HPP

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

#include "gameobject.hpp"

namespace easy
{

class RenderHandler : virtual public GameObject
{
public:
    virtual ~RenderHandler() {}

    virtual void update(sf::Time elapsed) {}

    virtual sf::Drawable& getDrawable() = 0;

protected:
    RenderHandler() = default;
};

} // namespace easy

#endif // RENDERHANDLER_HPP
