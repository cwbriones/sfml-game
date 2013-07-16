#ifndef DEMO_INPUT_SYSTEM_H
#define DEMO_INPUT_SYSTEM_H 

#include <SFML/Window/Event.hpp>
#include "Component/Input.h"

#include <list>

namespace demo {

/*
 * Central dispatcher for all input events.
 */
class InputSystem
{
public:
    InputSystem();
    ~InputSystem();
    void registerSink(InputComponent* component);

    void delegateKeyboardEvent(sf::Event& ev);
    void delegateMouseEvent(sf::Event& ev);
private:
    std::list<KeyboardListener*> keyboardSinks_;
    std::list<MouseListener*> mouseSinks_;
    // TODO: Add an input mapping?

}; // InputSystem

} // namespace demo

#endif // DEMO_INPUT_SYSTEM_H
