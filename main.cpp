#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "eventhandler.hpp"
#include "eventmanager.hpp"
#include "rendermanager.hpp"
#include "renderhandler.hpp"

using namespace easy;

using namespace std;
using namespace sf;

ostream& operator<<(ostream& os, Vector2i rhs)
{
    cout << "(" << rhs.x << ", " << rhs.y << ")";
    return os;
}

class MyHandler : public KeyboardHandler, public MouseHandler
{
protected:
    virtual void keyDown(Keyboard::Key key)
    {
        cout << key << " was pressed" << endl;
    }

    virtual void keyUp(Keyboard::Key key)
    {
        cout << key << " was released" << endl;
    }

    virtual void mouseDown(Mouse::Button mb, Vector2i pos)
    {
        cout << mb << " was pressed at " << pos << endl;
    }

    virtual void mouseUp(Mouse::Button mb, Vector2i pos)
    {
        cout << mb << " was released at " << pos << endl;
    }

    virtual void mouseMove(Vector2i pos)
    {
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            cout << "Mouse moved to " << pos << endl;
        }
    }
};

class WolololHandler : public MouseHandler
{
protected:
    virtual void scrollUp(Vector2i pos)
    {
        cout << "scrolled up!" << endl;
    }

    virtual void scrollDown(Vector2i pos)
    {
        cout << "scrolled down!" << endl;
    }
};

class WolololRenderer : public RenderHandler, public MouseHandler
{
private:
    vector<Color> flickers;
    RectangleShape rs;
    unsigned i;

public:
    WolololRenderer()
    : rs({800, 600}), i(0)
    {
        flickers.push_back(Color::Blue);
        flickers.push_back(Color::Red);
        flickers.push_back(Color::Yellow);
        flickers.push_back(Color::Green);
        flickers.push_back(Color::Magenta);
        flickers.push_back(Color::Cyan);
    }

    virtual void update(Time elapsed)
    {
        rs.setFillColor(flickers[i]);
    }

    virtual Drawable& getDrawable()
    {
        return rs;
    }

protected:
    virtual void leftButtonDown(Vector2i pos)
    {
        ++i;
        if(i == flickers.size())
        {
            i = 0;
        }
    }
};

int main()
{
    RenderWindow mw({800, 600}, "Test Window");
    EventManager em(&mw);
    RenderManager rm(&mw);

    vector<GameObject*> objects;

    {
        WolololHandler* r = new WolololHandler();
        objects.push_back(r);
        em.registerHandler(r);
    }
    {
        MyHandler* r = new MyHandler();
        objects.push_back(r);
        em.registerHandler(r);
    }
    {
        WolololRenderer* r = new WolololRenderer();
        objects.push_back(r);
        em.registerHandler(r);
        rm.registerHandler(r);
    }

    while(mw.isOpen())
    {
        em.handleCycle();
        rm.handleCycle();
    }

    for(GameObject* g: objects)
    {
        if(g)
        {
            delete g;
        }
    }
    return 0;
}
