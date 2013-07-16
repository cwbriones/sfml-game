#ifndef DEMO_MOUSE_INPUT_COMPONENT_H
#define DEMO_MOUSE_INPUT_COMPONENT_H

#include "Component/Input/InputComponent.h"

namespace demo {

class MouseListener : public InputComponent
{
    public:
        MouseListener(){ type_ = InputType::MOUSE; }
    
}; // MouseInputComponent

} // namespace demo


#endif // DEMO_MOUSE_INPUT_COMPONENT_H
