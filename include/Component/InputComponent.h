#ifndef DEMO_INPUT_COMPONENT_H
#define DEMO_INPUT_COMPONENT_H

namespace demo {

class InputComponent
{
public:
    InputComponent();
    virtual void update(Entity& entity) = 0;
};

} // namespace demo

#endif // DEMO_INPUT_COMPONENT_H
