#ifndef CREDITS_STATE
#define CREDITS_STATE

#include "GameState.h"
#include <SFML/Graphics.hpp>

class CreditsState : public GameState {
    public:
        CreditsState();
        virtual void update(sf::Time delta) override;
        virtual void render(sf::RenderTarget* target) override;
        virtual void checkForInput(sf::Event& ev) override;
    private:
        sf::Text text_;
        sf::Font font_;
};

#endif //CREDITS_STATE
