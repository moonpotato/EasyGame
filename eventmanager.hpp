#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include <vector>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

#include "eventhandler.hpp"

namespace easy
{

class EventManager
{
private:
    std::vector<EventHandler*> m_handlers;
    sf::Window* m_parent;

    sf::Clock m_sinceStart;
    sf::Clock m_sinceEnd;

    void handleEvent(sf::Event e);

public:
    EventManager(sf::Window* owner);

    void setWindow(sf::Window* owner);

    void registerHandler(EventHandler* to_add);
    void clear();

    void handleCycle();

    ~EventManager() {}
};

} // namespace easy

#endif // EVENTMANAGER_HPP
