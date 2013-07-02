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
        
        void onKeyPressed(int keycode);
        void onKeyReleased(int keycode);

        void onEnter();

        bool readyForClose(){ return true; };
    private:
        Menu menu_;
};

#endif //MAIN_MENU_STATE
