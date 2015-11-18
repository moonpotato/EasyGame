#include "eventmanager.hpp"

#include <stdexcept>

using namespace easy;

using namespace sf;

EventManager::EventManager(Window* owner)
: m_handlers(), m_parent(owner)
{
    if(m_parent)
    {
        m_parent->setKeyRepeatEnabled(false);
    }
}

void EventManager::setWindow(Window* owner)
{
    m_parent = owner;
    if(m_parent)
    {
        m_parent->setKeyRepeatEnabled(false);
    }
}

void EventManager::registerHandler(EventHandler* to_add)
{
    m_handlers.push_back(to_add);
}

void EventManager::clear()
{
    m_handlers.clear();
}

void EventManager::handleCycle()
{
    {
        Time elapsed = m_sinceStart.getElapsedTime();
        m_sinceStart.restart();
        for(EventHandler* h: m_handlers)
        {
            h->processBegin(elapsed);
        }
    }

    if(m_parent)
    {
        Event e;
        while(m_parent->pollEvent(e))
        {
            handleEvent(e);
        }
    }

    {
        Time elapsed = m_sinceEnd.getElapsedTime();
        m_sinceEnd.restart();
        for(EventHandler* h: m_handlers)
        {
            h->processEnd(elapsed);
        }
    }
}

void EventManager::handleEvent(Event e)
{
    if(e.type == Event::Closed)
    {
        m_parent->close();
    }
    else
    {
        for(EventHandler* h: m_handlers)
        {
            switch(e.type)
            {
            case Event::KeyPressed:
            case Event::KeyReleased:
                if(auto kh = dynamic_cast<KeyboardHandler*>(h))
                {
                    kh->processKeyEvent(e.type, e.key.code);
                }
                break;

            case Event::MouseButtonPressed:
            case Event::MouseButtonReleased:
                if(auto mh = dynamic_cast<MouseHandler*>(h))
                {
                    mh->processClickEvent(e.type, e.mouseButton.button, {e.mouseButton.x, e.mouseButton.y});
                }
                break;

            case Event::MouseMoved:
                if(auto mh = dynamic_cast<MouseHandler*>(h))
                {
                    mh->processCursorEvent(e.type, {e.mouseMove.x, e.mouseMove.y});
                }
                break;

            case Event::MouseWheelMoved:
                if(auto mh = dynamic_cast<MouseHandler*>(h))
                {
                    mh->processCursorEvent(e.type, {e.mouseWheel.x, e.mouseWheel.y}, e.mouseWheel.delta);
                }
                break;

            default:
                break;
            }
        }
    }
}
