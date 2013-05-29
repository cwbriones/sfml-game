#ifndef GAMEPLAY_STATE
#define GAMEPLAY_STATE

#include "State.h"

#include <SFML/graphics.hpp>

class GameplayState : public GameState {
    public:
        GameplayState();
        void update(sf::Time delta);
        void render(sf::RenderTarget* target);
        
        void onEnter();
        void onExit();

      	void onHidden();
      	void onRevealed();

        void keyPressed(int keycode);
        void keyReleased(int keycode);
        
        bool readyForClose();
    private:
        sf::Font font_;
        sf::Text text_;
};

#endif //GAMEPLAY_STATE
