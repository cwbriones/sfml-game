#ifndef MENU_KEY_LISTENER_H
#define MENU_KEY_LISTENER_H 

#include "Component/Input/KeyboardListener.h"

class Menu;

namespace demo {

class MenuKeyListener : public KeyboardListener
{
public:
    MenuKeyListener(Menu* parent);

    virtual void onKeyPressed(KeyEvent ke);
    virtual void onKeyReleased(KeyEvent ke);
    virtual void update(Entity& owner, int delta){};
private:
    Menu* parent_;
};

} //demo

#endif // MENU_KEY_LISTENER_H
