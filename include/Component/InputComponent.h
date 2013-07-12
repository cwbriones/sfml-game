#ifndef DEMO_INPUT_COMPONENT_H
#define DEMO_INPUT_COMPONENT_H

namespace demo {

class InputComponent
{
public:
    virtual void update(Entity& entity) = 0;
}; // InputComponent

} // namespace demo

#endif // DEMO_INPUT_COMPONENT_H
