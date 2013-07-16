#ifndef MAIN_MENU_STATE
#define MAIN_MENU_STATE

#include "Menu/Menu.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>


class MainMenuState : public GameState {
    public:
        MainMenuState();

        // Implementation : GameState

        void update(sf::Time delta);
        void render(sf::RenderTarget* target) override;
        
        void onKeyPressed(int keycode);
        void onKeyReleased(int keycode);

        void onEnter();

        bool readyForClose(){ return true; };
    private:
        Menu menu_;
};

#endif //MAIN_MENU_STATE
