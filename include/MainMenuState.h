#ifndef MAIN_MENU_STATE
#define MAIN_MENU_STATE

#include "Menu/Menu.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>


class MainMenuState : public GameState {
    public:
        MainMenuState();

        // Implementation : GameState

        void update(sf::Time delta) override;
        void checkForInput(sf::Event& ev) override;
        void render(sf::RenderTarget* target) override;

        void onEnter();
    private:
        Menu menu_;
};

#endif //MAIN_MENU_STATE
