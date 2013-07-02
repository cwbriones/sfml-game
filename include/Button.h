#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

#include <string>
#include <functional>

class Button : public sf::Transformable {
    public:
        Button(std::string label, float x, float y, float width, float height);
        bool isActive();
        bool hasMouse();
        void update(sf::Vector2i mousePosition, bool buttonDown);
        void activate();

        std::string getLabel();
        sf::Vector2f getDimensions();
        void setDimensions(float x, float y);
        void setAction(std::function<void(void)> action);
    private:
        bool active_;
        bool hasMouse_;
        std::function<void(void)> onPress_;
        
        std::string label_;
        sf::Vector2f bounds_;
};

#endif //BUTTON_H
