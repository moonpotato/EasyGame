#include "rendermanager.hpp"

#include <stdexcept>

using namespace easy;

using namespace sf;

RenderManager::RenderManager(RenderWindow* owner)
: m_handlers(), m_parent(owner)
{
    if(m_parent)
    {
        m_parent->setVerticalSyncEnabled(true);
    }
}

void RenderManager::setWindow(RenderWindow* owner)
{
    m_parent = owner;
    if(m_parent)
    {
        m_parent->setVerticalSyncEnabled(true);
    }
}

void RenderManager::registerHandler(RenderHandler* to_add)
{
    m_handlers.push_back(to_add);
}

void RenderManager::clear()
{
    m_handlers.clear();
}

void RenderManager::handleCycle()
{
    {
        Time elapsed = m_sinceLast.getElapsedTime();
        m_sinceLast.restart();
        for(RenderHandler* h: m_handlers)
        {
            h->update(elapsed);
        }
    }

    if(m_parent)
    {
        m_parent->clear();
        for(RenderHandler* h: m_handlers)
        {
            m_parent->draw(h->getDrawable());
        }
        m_parent->display();
    }
}
