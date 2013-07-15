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

        // Implementation : GameState

        virtual void update(sf::Time delta) override;
        virtual void render(sf::RenderTarget* target) override;
        
        virtual void onKeyPressed(int keycode) override;
        virtual void onKeyReleased(int keycode) override;

        virtual void onEnter() override;
        void createEntities(); 
    private:
        sf::Font font_;
        sf::Text text_;

        demo::EntityFactory factory_;
        std::list<demo::Entity*> entities_;
};

#endif //GAMEPLAY_STATE
