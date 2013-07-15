#ifndef DEMO_INPUT_SYSTEM_H
#define DEMO_INPUT_SYSTEM_H 

#include <SFML/Window/Event.hpp>
#include <list>

namespace demo {

class InputComponent;

class InputSystem
{
public:
    InputSystem();
    ~InputSystem();
    virtual void delegateEvent(sf::Event& ev);
    void registerComponent(InputComponent* component);
private:
    void delegateKeyboardEvent(sf::Event& ev);
    void delegateJoystickEvent(sf::Event& ev);
    void delegateMouseEvent(sf::Event& ev);

    std::list<InputComponent*> registered_;

    // TODO: Add an input mapping?

}; // InputSystem

} // namespace demo

#endif // DEMO_INPUT_SYSTEM_H
