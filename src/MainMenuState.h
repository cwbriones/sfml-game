#ifndef MAIN_MENU_STATE
#define MAIN_MENU_STATE

#include "State.h"
#include "Menu.h"

#include <SFML/Graphics.hpp>

class MainMenuState : public GameState {
    public:
        MainMenuState();
        void update(sf::Time delta);
        void render(sf::RenderTarget* target);
        
        void onEnter();
        void onExit();

      	void onHidden();
      	void onRevealed();

        void onKeyPressed(int keycode);
        void onKeyReleased(int keycode);
    private:
        Menu menu_;
};

#endif //MAIN_MENU_STATE
