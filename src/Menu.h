#ifndef MENU_H
#define MENU_H

#include "Button.h"

#include <SFML/Graphics.hpp>

#include <string>
#include <unordered_map>

class Menu : public sf::Transformable {
    public:
        Menu(std::string fontPath);
        ~Menu();
        void addItem(std::string item_);
        void setFontSize(int size);
        void render(sf::RenderTarget* target);
        void renderSelection(sf::RenderTarget* target);
        void activateSelection();

        bool isActive(std::string item_);
        bool hasMouse(std::string item_);
        void update(sf::Vector2i mousePostion, bool buttonDown);

        void incrementSelection();
        void decrementSelection();
    private:
        int fontSize_;
        sf::Font font_;
        sf::Text text_;
        std::vector<Button*> buttons_;

        std::unordered_map<std::string, bool> active_;
        std::unordered_map<std::string, bool> hasMouse_;

        std::vector<Button*>::iterator selection_;

        void resize();
};

#endif //MENU_H
