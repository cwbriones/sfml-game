#ifndef DEMO_INPUT_COMPONENT_H
#define DEMO_INPUT_COMPONENT_H

namespace demo {

class Entity;
class InputSystem;

class InputComponent
{
public:
    enum class InputType {
        KEYBOARD,
        MOUSE,
        JOYSTICK,
        UNDEFINED
    };

    virtual ~InputComponent();
    virtual void update(Entity& owner, int delta) = 0;

    void setInputSystem(const InputSystem* system){
        if (!system_){
            system_ = system;
        }
    }
    InputType getType(){ return type_; };
protected:
    InputType type_ = InputType::UNDEFINED;
    const InputSystem* system_ = nullptr;
}; // InputComponent

} // namespace demo

#endif // DEMO_INPUT_COMPONENT_H
