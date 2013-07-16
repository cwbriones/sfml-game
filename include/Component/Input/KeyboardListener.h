#ifndef DEMO_KEYBOARD_INPUT_COMPONENT_H
#define DEMO_KEYBOARD_INPUT_COMPONENT_H

#include "InputComponent.h"

namespace demo {

class KeyboardListener : public InputComponent {
    public:
        KeyboardListener(){ type_ = InputType::KEYBOARD; };
        virtual void onKeyPressed(int keycode) = 0;
        virtual void onKeyReleased(int keycode) = 0;
};
    
} /* namespace demo */

#endif // DEMO_KEYBOARD_INPUT_COMPONENT_H
