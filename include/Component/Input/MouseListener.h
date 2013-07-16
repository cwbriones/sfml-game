#ifndef DEMO_MOUSE_INPUT_COMPONENT_H
#define DEMO_MOUSE_INPUT_COMPONENT_H

#include "Component/Input/InputComponent.h"

#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>

namespace demo {

class MouseListener : public InputComponent
{
    public:
        MouseListener(){ type_ = InputType::MOUSE; }
        ~MouseListener(){ 
            if(inputSystem_){
                inputSystem_->deregisterSink(this);
            }
        }
        virtual void update(Entity& owner, int delta) = 0;
}; // MouseInputComponent

} // namespace demo


#endif // DEMO_MOUSE_INPUT_COMPONENT_H
