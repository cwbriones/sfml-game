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

        void update(sf::Time delta) override;
        void render(sf::RenderTarget* target) override;
        void checkForInput(sf::Event& ev) override;

        void onEnter() override;
        void createEntities(); 
    private:
        sf::Font font_;
        sf::Text text_;

        demo::EntityFactory factory_;

        demo::Entity* player_;
        std::list<demo::Entity*> entities_;
};

#endif //GAMEPLAY_STATE
