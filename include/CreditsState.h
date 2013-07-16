#ifndef CREDITS_STATE
#define CREDITS_STATE

#include "GameState.h"
#include <SFML/Graphics.hpp>

class CreditsState : public GameState {
    public:
        CreditsState();
        void update(sf::Time delta);
        void render(sf::RenderTarget* target);
        
        void onKeyPressed(int keycode);
        void onKeyReleased(int keycode);
    private:
        sf::Text text_;
        sf::Font font_;
};

#endif //CREDITS_STATE
