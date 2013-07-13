#ifndef GAMEPLAY_STATE
#define GAMEPLAY_STATE

#include "GameState.h"
#include "Entity.h"
#include "EntityFactory.h"

#include <SFML/Graphics.hpp>

#include <list>

class GameplayState : public GameState {
    public:
        GameplayState();
        ~GameplayState();
        void update(sf::Time delta);
        void render(sf::RenderTarget* target);
        
        void onKeyPressed(int keycode);
        void onKeyReleased(int keycode);
    private:
        sf::Font font_;
        sf::Text text_;

        demo::EntityFactory factory_;
        std::list<demo::Entity*> entities_;
};

#endif //GAMEPLAY_STATE
