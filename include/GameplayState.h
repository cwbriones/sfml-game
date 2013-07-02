#ifndef GAMEPLAY_STATE
#define GAMEPLAY_STATE

#include "State.h"

#include <SFML/Graphics.hpp>

class GameplayState : public GameState {
    public:
        GameplayState();
        void update(sf::Time delta);
        void render(sf::RenderTarget* target);
        
        void onKeyPressed(int keycode);
        void onKeyReleased(int keycode);
    private:
        sf::Font font_;
        sf::Text text_;
};

#endif //GAMEPLAY_STATE
