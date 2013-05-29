#ifndef MAIN_MENU_STATE
#define MAIN_MENU_STATE

#include "State.h"

#include <SFML/graphics.hpp>

class MainMenuState : public GameState {
    public:
        MainMenuState();
        void update(sf::Time delta);
        void render(sf::RenderTarget* target);
        
        void onEnter();
        void onExit();

      	void onHidden();
      	void onRevealed();

        void keyPressed(int keycode);
        void keyReleased(int keycode);
    private:
        sf::Font font_;
        sf::Text text_;
};

#endif //MAIN_MENU_STATE
