#include "Menu/Menu.h"
#include "Menu/MenuKeyListener.h"

namespace demo {

MenuKeyListener::MenuKeyListener(Menu* parent){
    parent_ = parent;
}

void MenuKeyListener::onKeyReleased(KeyEvent ke){

}

void MenuKeyListener::onKeyPressed(KeyEvent ke){
    if (ke.code == sf::Keyboard::Up){
        parent_->decrementSelection();
    }
    else if (ke.code == sf::Keyboard::Down){
        parent_->incrementSelection();
    } else if (ke.code == sf::Keyboard::Return){
        parent_->activateSelection();
    }
}

} /* namespace demo */
