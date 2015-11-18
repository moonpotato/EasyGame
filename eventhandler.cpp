#include "eventhandler.hpp"

#include <stdexcept>

using namespace easy;

using namespace sf;

void MouseHandler::processCursorEvent(Event::EventType e, Vector2i pos, int delta)
{
    switch(e)
    {
    case Event::MouseMoved:
        this->mouseMove(pos);
        break;

    case Event::MouseWheelMoved:
        if(delta > 0)
        {
            this->scrollUp(pos);
        }
        else
        {
            this->scrollDown(pos);
        }
        this->mouseScroll(delta, pos);
        break;

    default:
        throw std::invalid_argument("e");
        break;
    }
}

void MouseHandler::processClickEvent(Event::EventType e, Mouse::Button mb, Vector2i pos)
{
    switch(e)
    {
    case Event::MouseButtonPressed:
        switch(mb)
        {
        case Mouse::Left:
            this->leftButtonDown(pos);
            break;

        case Mouse::Right:
            this->rightButtonDown(pos);
            break;

        case Mouse::Middle:
            this->middleButtonDown(pos);
            break;

        case Mouse::XButton1:
            this->x1ButtonDown(pos);
            break;

        case Mouse::XButton2:
            this->x2ButtonDown(pos);
            break;

        default:
            throw std::invalid_argument("mb");
            break;
        }
        this->mouseDown(mb, pos);
        break;

    case Event::MouseButtonReleased:
        switch(mb)
        {
        case Mouse::Left:
            this->leftButtonUp(pos);
            break;

        case Mouse::Right:
            this->rightButtonUp(pos);
            break;

        case Mouse::Middle:
            this->middleButtonUp(pos);
            break;

        case Mouse::XButton1:
            this->x1ButtonUp(pos);
            break;

        case Mouse::XButton2:
            this->x2ButtonUp(pos);
            break;

        default:
            throw std::invalid_argument("mb");
            break;
        }
        this->mouseUp(mb, pos);
        break;

    default:
        throw std::invalid_argument("e");
        break;
    }
}

void KeyboardHandler::processKeyEvent(Event::EventType e, Keyboard::Key key)
{
    switch(e)
    {
    case Event::KeyPressed:
        switch(key)
        {
        case Keyboard::Unknown:
            this->unknownKeyDown();
            break;

        case Keyboard::A:
            this->aKeyDown();
            break;

        case Keyboard::B:
            this->bKeyDown();
            break;

        case Keyboard::C:
            this->cKeyDown();
            break;

        case Keyboard::D:
            this->dKeyDown();
            break;

        case Keyboard::E:
            this->eKeyDown();
            break;

        case Keyboard::F:
            this->fKeyDown();
            break;

        case Keyboard::G:
            this->gKeyDown();
            break;

        case Keyboard::H:
            this->hKeyDown();
            break;

        case Keyboard::I:
            this->iKeyDown();
            break;

        case Keyboard::J:
            this->jKeyDown();
            break;

        case Keyboard::K:
            this->kKeyDown();
            break;

        case Keyboard::L:
            this->lKeyDown();
            break;

        case Keyboard::M:
            this->mKeyDown();
            break;

        case Keyboard::N:
            this->nKeyDown();
            break;

        case Keyboard::O:
            this->oKeyDown();
            break;

        case Keyboard::P:
            this->pKeyDown();
            break;

        case Keyboard::Q:
            this->qKeyDown();
            break;

        case Keyboard::R:
            this->rKeyDown();
            break;

        case Keyboard::S:
            this->sKeyDown();
            break;

        case Keyboard::T:
            this->tKeyDown();
            break;

        case Keyboard::U:
            this->uKeyDown();
            break;

        case Keyboard::V:
            this->vKeyDown();
            break;

        case Keyboard::W:
            this->wKeyDown();
            break;

        case Keyboard::X:
            this->xKeyDown();
            break;

        case Keyboard::Y:
            this->yKeyDown();
            break;

        case Keyboard::Z:
            this->zKeyDown();
            break;

        case Keyboard::Num0:
            this->num0KeyDown();
            break;

        case Keyboard::Num1:
            this->num1KeyDown();
            break;

        case Keyboard::Num2:
            this->num2KeyDown();
            break;

        case Keyboard::Num3:
            this->num3KeyDown();
            break;

        case Keyboard::Num4:
            this->num4KeyDown();
            break;

        case Keyboard::Num5:
            this->num5KeyDown();
            break;

        case Keyboard::Num6:
            this->num6KeyDown();
            break;

        case Keyboard::Num7:
            this->num7KeyDown();
            break;

        case Keyboard::Num8:
            this->num8KeyDown();
            break;

        case Keyboard::Num9:
            this->num9KeyDown();
            break;

        case Keyboard::Escape:
            this->escapeKeyDown();
            break;

        case Keyboard::LControl:
            this->lcontrolKeyDown();
            break;

        case Keyboard::LShift:
            this->lshiftKeyDown();
            break;

        case Keyboard::LAlt:
            this->laltKeyDown();
            break;

        case Keyboard::LSystem:
            this->lsystemKeyDown();
            break;

        case Keyboard::RControl:
            this->rcontrolKeyDown();
            break;

        case Keyboard::RShift:
            this->rshiftKeyDown();
            break;

        case Keyboard::RAlt:
            this->raltKeyDown();
            break;

        case Keyboard::RSystem:
            this->rsystemKeyDown();
            break;

        case Keyboard::Menu:
            this->menuKeyDown();
            break;

        case Keyboard::LBracket:
            this->lbracketKeyDown();
            break;

        case Keyboard::RBracket:
            this->rbracketKeyDown();
            break;

        case Keyboard::SemiColon:
            this->semicolonKeyDown();
            break;

        case Keyboard::Comma:
            this->commaKeyDown();
            break;

        case Keyboard::Period:
            this->periodKeyDown();
            break;

        case Keyboard::Quote:
            this->quoteKeyDown();
            break;

        case Keyboard::Slash:
            this->slashKeyDown();
            break;

        case Keyboard::BackSlash:
            this->backslashKeyDown();
            break;

        case Keyboard::Tilde:
            this->tildeKeyDown();
            break;

        case Keyboard::Equal:
            this->equalKeyDown();
            break;

        case Keyboard::Dash:
            this->dashKeyDown();
            break;

        case Keyboard::Space:
            this->spaceKeyDown();
            break;

        case Keyboard::Return:
            this->returnKeyDown();
            break;

        case Keyboard::BackSpace:
            this->backspaceKeyDown();
            break;

        case Keyboard::Tab:
            this->tabKeyDown();
            break;

        case Keyboard::PageUp:
            this->pageupKeyDown();
            break;

        case Keyboard::PageDown:
            this->pagedownKeyDown();
            break;

        case Keyboard::End:
            this->endKeyDown();
            break;

        case Keyboard::Home:
            this->homeKeyDown();
            break;

        case Keyboard::Insert:
            this->insertKeyDown();
            break;

        case Keyboard::Delete:
            this->deleteKeyDown();
            break;

        case Keyboard::Add:
            this->addKeyDown();
            break;

        case Keyboard::Subtract:
            this->subtractKeyDown();
            break;

        case Keyboard::Multiply:
            this->multiplyKeyDown();
            break;

        case Keyboard::Divide:
            this->divideKeyDown();
            break;

        case Keyboard::Left:
            this->leftKeyDown();
            break;

        case Keyboard::Right:
            this->rightKeyDown();
            break;

        case Keyboard::Up:
            this->upKeyDown();
            break;

        case Keyboard::Down:
            this->downKeyDown();
            break;

        case Keyboard::Numpad0:
            this->numpad0KeyDown();
            break;

        case Keyboard::Numpad1:
            this->numpad1KeyDown();
            break;

        case Keyboard::Numpad2:
            this->numpad2KeyDown();
            break;

        case Keyboard::Numpad3:
            this->numpad3KeyDown();
            break;

        case Keyboard::Numpad4:
            this->numpad4KeyDown();
            break;

        case Keyboard::Numpad5:
            this->numpad5KeyDown();
            break;

        case Keyboard::Numpad6:
            this->numpad6KeyDown();
            break;

        case Keyboard::Numpad7:
            this->numpad7KeyDown();
            break;

        case Keyboard::Numpad8:
            this->numpad8KeyDown();
            break;

        case Keyboard::Numpad9:
            this->numpad9KeyDown();
            break;

        case Keyboard::F1:
            this->f1KeyDown();
            break;

        case Keyboard::F2:
            this->f2KeyDown();
            break;

        case Keyboard::F3:
            this->f3KeyDown();
            break;

        case Keyboard::F4:
            this->f4KeyDown();
            break;

        case Keyboard::F5:
            this->f5KeyDown();
            break;

        case Keyboard::F6:
            this->f6KeyDown();
            break;

        case Keyboard::F7:
            this->f7KeyDown();
            break;

        case Keyboard::F8:
            this->f8KeyDown();
            break;

        case Keyboard::F9:
            this->f9KeyDown();
            break;

        case Keyboard::F10:
            this->f10KeyDown();
            break;

        case Keyboard::F11:
            this->f11KeyDown();
            break;

        case Keyboard::F12:
            this->f12KeyDown();
            break;

        case Keyboard::F13:
            this->f13KeyDown();
            break;

        case Keyboard::F14:
            this->f14KeyDown();
            break;

        case Keyboard::F15:
            this->f15KeyDown();
            break;

        case Keyboard::Pause:
            this->pauseKeyDown();
            break;

        default:
            throw std::invalid_argument("key");
            break;
        }
        this->keyDown(key);
        break;

    case Event::KeyReleased:
        switch(key)
        {
        case Keyboard::Unknown:
            this->unknownKeyUp();
            break;

        case Keyboard::A:
            this->aKeyUp();
            break;

        case Keyboard::B:
            this->bKeyUp();
            break;

        case Keyboard::C:
            this->cKeyUp();
            break;

        case Keyboard::D:
            this->dKeyUp();
            break;

        case Keyboard::E:
            this->eKeyUp();
            break;

        case Keyboard::F:
            this->fKeyUp();
            break;

        case Keyboard::G:
            this->gKeyUp();
            break;

        case Keyboard::H:
            this->hKeyUp();
            break;

        case Keyboard::I:
            this->iKeyUp();
            break;

        case Keyboard::J:
            this->jKeyUp();
            break;

        case Keyboard::K:
            this->kKeyUp();
            break;

        case Keyboard::L:
            this->lKeyUp();
            break;

        case Keyboard::M:
            this->mKeyUp();
            break;

        case Keyboard::N:
            this->nKeyUp();
            break;

        case Keyboard::O:
            this->oKeyUp();
            break;

        case Keyboard::P:
            this->pKeyUp();
            break;

        case Keyboard::Q:
            this->qKeyUp();
            break;

        case Keyboard::R:
            this->rKeyUp();
            break;

        case Keyboard::S:
            this->sKeyUp();
            break;

        case Keyboard::T:
            this->tKeyUp();
            break;

        case Keyboard::U:
            this->uKeyUp();
            break;

        case Keyboard::V:
            this->vKeyUp();
            break;

        case Keyboard::W:
            this->wKeyUp();
            break;

        case Keyboard::X:
            this->xKeyUp();
            break;

        case Keyboard::Y:
            this->yKeyUp();
            break;

        case Keyboard::Z:
            this->zKeyUp();
            break;

        case Keyboard::Num0:
            this->num0KeyUp();
            break;

        case Keyboard::Num1:
            this->num1KeyUp();
            break;

        case Keyboard::Num2:
            this->num2KeyUp();
            break;

        case Keyboard::Num3:
            this->num3KeyUp();
            break;

        case Keyboard::Num4:
            this->num4KeyUp();
            break;

        case Keyboard::Num5:
            this->num5KeyUp();
            break;

        case Keyboard::Num6:
            this->num6KeyUp();
            break;

        case Keyboard::Num7:
            this->num7KeyUp();
            break;

        case Keyboard::Num8:
            this->num8KeyUp();
            break;

        case Keyboard::Num9:
            this->num9KeyUp();
            break;

        case Keyboard::Escape:
            this->escapeKeyUp();
            break;

        case Keyboard::LControl:
            this->lcontrolKeyUp();
            break;

        case Keyboard::LShift:
            this->lshiftKeyUp();
            break;

        case Keyboard::LAlt:
            this->laltKeyUp();
            break;

        case Keyboard::LSystem:
            this->lsystemKeyUp();
            break;

        case Keyboard::RControl:
            this->rcontrolKeyUp();
            break;

        case Keyboard::RShift:
            this->rshiftKeyUp();
            break;

        case Keyboard::RAlt:
            this->raltKeyUp();
            break;

        case Keyboard::RSystem:
            this->rsystemKeyUp();
            break;

        case Keyboard::Menu:
            this->menuKeyUp();
            break;

        case Keyboard::LBracket:
            this->lbracketKeyUp();
            break;

        case Keyboard::RBracket:
            this->rbracketKeyUp();
            break;

        case Keyboard::SemiColon:
            this->semicolonKeyUp();
            break;

        case Keyboard::Comma:
            this->commaKeyUp();
            break;

        case Keyboard::Period:
            this->periodKeyUp();
            break;

        case Keyboard::Quote:
            this->quoteKeyUp();
            break;

        case Keyboard::Slash:
            this->slashKeyUp();
            break;

        case Keyboard::BackSlash:
            this->backslashKeyUp();
            break;

        case Keyboard::Tilde:
            this->tildeKeyUp();
            break;

        case Keyboard::Equal:
            this->equalKeyUp();
            break;

        case Keyboard::Dash:
            this->dashKeyUp();
            break;

        case Keyboard::Space:
            this->spaceKeyUp();
            break;

        case Keyboard::Return:
            this->returnKeyUp();
            break;

        case Keyboard::BackSpace:
            this->backspaceKeyUp();
            break;

        case Keyboard::Tab:
            this->tabKeyUp();
            break;

        case Keyboard::PageUp:
            this->pageupKeyUp();
            break;

        case Keyboard::PageDown:
            this->pagedownKeyUp();
            break;

        case Keyboard::End:
            this->endKeyUp();
            break;

        case Keyboard::Home:
            this->homeKeyUp();
            break;

        case Keyboard::Insert:
            this->insertKeyUp();
            break;

        case Keyboard::Delete:
            this->deleteKeyUp();
            break;

        case Keyboard::Add:
            this->addKeyUp();
            break;

        case Keyboard::Subtract:
            this->subtractKeyUp();
            break;

        case Keyboard::Multiply:
            this->multiplyKeyUp();
            break;

        case Keyboard::Divide:
            this->divideKeyUp();
            break;

        case Keyboard::Left:
            this->leftKeyUp();
            break;

        case Keyboard::Right:
            this->rightKeyUp();
            break;

        case Keyboard::Up:
            this->upKeyUp();
            break;

        case Keyboard::Down:
            this->downKeyUp();
            break;

        case Keyboard::Numpad0:
            this->numpad0KeyUp();
            break;

        case Keyboard::Numpad1:
            this->numpad1KeyUp();
            break;

        case Keyboard::Numpad2:
            this->numpad2KeyUp();
            break;

        case Keyboard::Numpad3:
            this->numpad3KeyUp();
            break;

        case Keyboard::Numpad4:
            this->numpad4KeyUp();
            break;

        case Keyboard::Numpad5:
            this->numpad5KeyUp();
            break;

        case Keyboard::Numpad6:
            this->numpad6KeyUp();
            break;

        case Keyboard::Numpad7:
            this->numpad7KeyUp();
            break;

        case Keyboard::Numpad8:
            this->numpad8KeyUp();
            break;

        case Keyboard::Numpad9:
            this->numpad9KeyUp();
            break;

        case Keyboard::F1:
            this->f1KeyUp();
            break;

        case Keyboard::F2:
            this->f2KeyUp();
            break;

        case Keyboard::F3:
            this->f3KeyUp();
            break;

        case Keyboard::F4:
            this->f4KeyUp();
            break;

        case Keyboard::F5:
            this->f5KeyUp();
            break;

        case Keyboard::F6:
            this->f6KeyUp();
            break;

        case Keyboard::F7:
            this->f7KeyUp();
            break;

        case Keyboard::F8:
            this->f8KeyUp();
            break;

        case Keyboard::F9:
            this->f9KeyUp();
            break;

        case Keyboard::F10:
            this->f10KeyUp();
            break;

        case Keyboard::F11:
            this->f11KeyUp();
            break;

        case Keyboard::F12:
            this->f12KeyUp();
            break;

        case Keyboard::F13:
            this->f13KeyUp();
            break;

        case Keyboard::F14:
            this->f14KeyUp();
            break;

        case Keyboard::F15:
            this->f15KeyUp();
            break;

        case Keyboard::Pause:
            this->pauseKeyUp();
            break;

        default:
            throw std::invalid_argument("key");
            break;
        }
        this->keyUp(key);
        break;

    default:
        throw std::invalid_argument("e");
        break;
    }
}
