#ifndef DEMO_INPUT_COMPONENT_H
#define DEMO_INPUT_COMPONENT_H

namespace demo {

class Entity;
class InputSystem;

class InputComponent
{
public:
    virtual void update(Entity& owner, int delta) = 0;
    void setInputSystem(InputSystem* system){
        system_ = system;
    }
protected:
    InputSystem* system_ = nullptr;
}; // InputComponent

} // namespace demo

#endif // DEMO_INPUT_COMPONENT_H
