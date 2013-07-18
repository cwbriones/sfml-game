#ifndef DEMO_INPUT_CONTEXT_H
#define DEMO_INPUT_CONTEXT_H 

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>

#include <list>
#include <vector>
#include <string>

#include <map>
#include <unordered_map>

namespace demo {

class InputContext
{
public:
    enum InputType {
        Keyboard,
        Mouse,
        Joystick
    };
    struct InputEvent {
        InputType inputType;
        sf::Event ev;
    };
    
    InputContext();
    ~InputContext();

    void bindKeyEvent(std::string action, sf::Event::EventType type, int keycode);
    std::vector<std::string> getAvailableActions();

    bool testEvent(std::string action, sf::Event& ev);
private:
    std::map< std::string, InputEvent > bindings_;
}; // InputContext

} // namespace demo

#endif // DEMO_INPUT_CONTEXT_H
