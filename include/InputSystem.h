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
    void registerSink(InputComponent* component);

    void delegateKeyboardEvent(sf::Event& ev);
    void delegateJoystickEvent(sf::Event& ev);
    void delegateMouseEvent(sf::Event& ev);
private:
    std::list<InputComponent*> keyboardSinks_;
    std::list<InputComponent*> mouseSinks_;
    std::list<InputComponent*> joystickSinks_;
    // TODO: Add an input mapping?

}; // InputSystem

} // namespace demo

#endif // DEMO_INPUT_SYSTEM_H
