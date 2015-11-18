#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window.hpp>

#include "gameobject.hpp"

namespace easy
{

class EventHandler : virtual public GameObject
{
public:
    virtual ~EventHandler() {}

    virtual void processBegin(sf::Time elapsed) {}
    virtual void processEnd(sf::Time elapsed) {}

protected:
    EventHandler() = default;
};

class MouseHandler : virtual public EventHandler
{
public:
    virtual ~MouseHandler() = default;

    virtual void processClickEvent(sf::Event::EventType e, sf::Mouse::Button mb, sf::Vector2i pos) final;
    virtual void processCursorEvent(sf::Event::EventType e, sf::Vector2i pos, int delta = 0) final;

protected:
    MouseHandler() = default;

    virtual void mouseScroll(int delta, sf::Vector2i pos) {}

    virtual void scrollDown(sf::Vector2i pos) {}
    virtual void scrollUp(sf::Vector2i pos) {}

    virtual void mouseMove(sf::Vector2i pos) {}

    virtual void mouseDown(sf::Mouse::Button mb, sf::Vector2i pos) {}

    virtual void leftButtonDown(sf::Vector2i pos) {}
    virtual void rightButtonDown(sf::Vector2i pos) {}
    virtual void middleButtonDown(sf::Vector2i pos) {}
    virtual void x1ButtonDown(sf::Vector2i pos) {}
    virtual void x2ButtonDown(sf::Vector2i pos) {}

    virtual void mouseUp(sf::Mouse::Button mb, sf::Vector2i pos) {}

    virtual void leftButtonUp(sf::Vector2i pos) {}
    virtual void rightButtonUp(sf::Vector2i pos) {}
    virtual void middleButtonUp(sf::Vector2i pos) {}
    virtual void x1ButtonUp(sf::Vector2i pos) {}
    virtual void x2ButtonUp(sf::Vector2i pos) {}
};

class KeyboardHandler : virtual public EventHandler
{
public:
    virtual ~KeyboardHandler() = default;

    virtual void processKeyEvent(sf::Event::EventType e, sf::Keyboard::Key key) final;

protected:
    KeyboardHandler() = default;

    virtual void keyDown(sf::Keyboard::Key key) {}

    virtual void unknownKeyDown() {}

    virtual void aKeyDown() {}
    virtual void bKeyDown() {}
    virtual void cKeyDown() {}
    virtual void dKeyDown() {}
    virtual void eKeyDown() {}
    virtual void fKeyDown() {}
    virtual void gKeyDown() {}
    virtual void hKeyDown() {}
    virtual void iKeyDown() {}
    virtual void jKeyDown() {}
    virtual void kKeyDown() {}
    virtual void lKeyDown() {}
    virtual void mKeyDown() {}
    virtual void nKeyDown() {}
    virtual void oKeyDown() {}
    virtual void pKeyDown() {}
    virtual void qKeyDown() {}
    virtual void rKeyDown() {}
    virtual void sKeyDown() {}
    virtual void tKeyDown() {}
    virtual void uKeyDown() {}
    virtual void vKeyDown() {}
    virtual void wKeyDown() {}
    virtual void xKeyDown() {}
    virtual void yKeyDown() {}
    virtual void zKeyDown() {}

    virtual void num0KeyDown() {}
    virtual void num1KeyDown() {}
    virtual void num2KeyDown() {}
    virtual void num3KeyDown() {}
    virtual void num4KeyDown() {}
    virtual void num5KeyDown() {}
    virtual void num6KeyDown() {}
    virtual void num7KeyDown() {}
    virtual void num8KeyDown() {}
    virtual void num9KeyDown() {}

    virtual void escapeKeyDown() {}
    virtual void lcontrolKeyDown() {}
    virtual void lshiftKeyDown() {}
    virtual void laltKeyDown() {}
    virtual void lsystemKeyDown() {}
    virtual void rcontrolKeyDown() {}
    virtual void rshiftKeyDown() {}
    virtual void raltKeyDown() {}
    virtual void rsystemKeyDown() {}
    virtual void menuKeyDown() {}

    virtual void lbracketKeyDown() {}
    virtual void rbracketKeyDown() {}
    virtual void semicolonKeyDown() {}
    virtual void commaKeyDown() {}
    virtual void periodKeyDown() {}
    virtual void quoteKeyDown() {}
    virtual void slashKeyDown() {}
    virtual void backslashKeyDown() {}
    virtual void tildeKeyDown() {}
    virtual void equalKeyDown() {}
    virtual void dashKeyDown() {}
    virtual void spaceKeyDown() {}
    virtual void returnKeyDown() {}
    virtual void backspaceKeyDown() {}
    virtual void tabKeyDown() {}

    virtual void pageupKeyDown() {}
    virtual void pagedownKeyDown() {}
    virtual void endKeyDown() {}
    virtual void homeKeyDown() {}
    virtual void insertKeyDown() {}
    virtual void deleteKeyDown() {}

    virtual void addKeyDown() {}
    virtual void subtractKeyDown() {}
    virtual void multiplyKeyDown() {}
    virtual void divideKeyDown() {}

    virtual void leftKeyDown() {}
    virtual void rightKeyDown() {}
    virtual void upKeyDown() {}
    virtual void downKeyDown() {}

    virtual void numpad0KeyDown() {}
    virtual void numpad1KeyDown() {}
    virtual void numpad2KeyDown() {}
    virtual void numpad3KeyDown() {}
    virtual void numpad4KeyDown() {}
    virtual void numpad5KeyDown() {}
    virtual void numpad6KeyDown() {}
    virtual void numpad7KeyDown() {}
    virtual void numpad8KeyDown() {}
    virtual void numpad9KeyDown() {}

    virtual void f1KeyDown() {}
    virtual void f2KeyDown() {}
    virtual void f3KeyDown() {}
    virtual void f4KeyDown() {}
    virtual void f5KeyDown() {}
    virtual void f6KeyDown() {}
    virtual void f7KeyDown() {}
    virtual void f8KeyDown() {}
    virtual void f9KeyDown() {}
    virtual void f10KeyDown() {}
    virtual void f11KeyDown() {}
    virtual void f12KeyDown() {}
    virtual void f13KeyDown() {}
    virtual void f14KeyDown() {}
    virtual void f15KeyDown() {}
    virtual void pauseKeyDown() {}

    virtual void keyUp(sf::Keyboard::Key key) {}

    virtual void unknownKeyUp() {}

    virtual void aKeyUp() {}
    virtual void bKeyUp() {}
    virtual void cKeyUp() {}
    virtual void dKeyUp() {}
    virtual void eKeyUp() {}
    virtual void fKeyUp() {}
    virtual void gKeyUp() {}
    virtual void hKeyUp() {}
    virtual void iKeyUp() {}
    virtual void jKeyUp() {}
    virtual void kKeyUp() {}
    virtual void lKeyUp() {}
    virtual void mKeyUp() {}
    virtual void nKeyUp() {}
    virtual void oKeyUp() {}
    virtual void pKeyUp() {}
    virtual void qKeyUp() {}
    virtual void rKeyUp() {}
    virtual void sKeyUp() {}
    virtual void tKeyUp() {}
    virtual void uKeyUp() {}
    virtual void vKeyUp() {}
    virtual void wKeyUp() {}
    virtual void xKeyUp() {}
    virtual void yKeyUp() {}
    virtual void zKeyUp() {}

    virtual void num0KeyUp() {}
    virtual void num1KeyUp() {}
    virtual void num2KeyUp() {}
    virtual void num3KeyUp() {}
    virtual void num4KeyUp() {}
    virtual void num5KeyUp() {}
    virtual void num6KeyUp() {}
    virtual void num7KeyUp() {}
    virtual void num8KeyUp() {}
    virtual void num9KeyUp() {}

    virtual void escapeKeyUp() {}
    virtual void lcontrolKeyUp() {}
    virtual void lshiftKeyUp() {}
    virtual void laltKeyUp() {}
    virtual void lsystemKeyUp() {}
    virtual void rcontrolKeyUp() {}
    virtual void rshiftKeyUp() {}
    virtual void raltKeyUp() {}
    virtual void rsystemKeyUp() {}
    virtual void menuKeyUp() {}

    virtual void lbracketKeyUp() {}
    virtual void rbracketKeyUp() {}
    virtual void semicolonKeyUp() {}
    virtual void commaKeyUp() {}
    virtual void periodKeyUp() {}
    virtual void quoteKeyUp() {}
    virtual void slashKeyUp() {}
    virtual void backslashKeyUp() {}
    virtual void tildeKeyUp() {}
    virtual void equalKeyUp() {}
    virtual void dashKeyUp() {}
    virtual void spaceKeyUp() {}
    virtual void returnKeyUp() {}
    virtual void backspaceKeyUp() {}
    virtual void tabKeyUp() {}

    virtual void pageupKeyUp() {}
    virtual void pagedownKeyUp() {}
    virtual void endKeyUp() {}
    virtual void homeKeyUp() {}
    virtual void insertKeyUp() {}
    virtual void deleteKeyUp() {}

    virtual void addKeyUp() {}
    virtual void subtractKeyUp() {}
    virtual void multiplyKeyUp() {}
    virtual void divideKeyUp() {}

    virtual void leftKeyUp() {}
    virtual void rightKeyUp() {}
    virtual void upKeyUp() {}
    virtual void downKeyUp() {}

    virtual void numpad0KeyUp() {}
    virtual void numpad1KeyUp() {}
    virtual void numpad2KeyUp() {}
    virtual void numpad3KeyUp() {}
    virtual void numpad4KeyUp() {}
    virtual void numpad5KeyUp() {}
    virtual void numpad6KeyUp() {}
    virtual void numpad7KeyUp() {}
    virtual void numpad8KeyUp() {}
    virtual void numpad9KeyUp() {}

    virtual void f1KeyUp() {}
    virtual void f2KeyUp() {}
    virtual void f3KeyUp() {}
    virtual void f4KeyUp() {}
    virtual void f5KeyUp() {}
    virtual void f6KeyUp() {}
    virtual void f7KeyUp() {}
    virtual void f8KeyUp() {}
    virtual void f9KeyUp() {}
    virtual void f10KeyUp() {}
    virtual void f11KeyUp() {}
    virtual void f12KeyUp() {}
    virtual void f13KeyUp() {}
    virtual void f14KeyUp() {}
    virtual void f15KeyUp() {}
    virtual void pauseKeyUp() {}
};

} // namespace easy

#endif // EVENTHANDLER_HPP
