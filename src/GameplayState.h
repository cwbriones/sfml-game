#ifndef GAMEPLAY_STATE
#define GAMEPLAY_STATE

#include "State.h"

#include <SFML/Graphics.hpp>

class GameplayState : public GameState {
    public:
        GameplayState();
        void update(sf::Time delta);
        void render(sf::RenderTarget* target);
        
        void onEnter();
        void onExit();

      	void onHidden();
      	void onRevealed();

        void onKeyPressed(int keycode);
        void onKeyReleased(int keycode);

        bool readyForClose();
};

#endif //GAMEPLAY_STATE
