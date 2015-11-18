#ifndef RENDERMANAGER_HPP
#define RENDERMANAGER_HPP

#include <vector>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

#include "renderhandler.hpp"

namespace easy
{

class RenderManager
{
private:
    std::vector<RenderHandler*> m_handlers;
    sf::RenderWindow* m_parent;

    sf::Clock m_sinceLast;

public:
    RenderManager(sf::RenderWindow* owner);

    void setWindow(sf::RenderWindow* owner);

    void registerHandler(RenderHandler* to_add);
    void clear();

    void handleCycle();

    ~RenderManager() {}
};

} // namespace easy

#endif // RENDERMANAGER_HPP
