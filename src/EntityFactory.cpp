#include "Entity.h"
#include "EntityFactory.h"

#include "InputSystem.h"
#include "Component/ShipGraphicsComponent.h"

namespace demo {

EntityFactory::EntityFactory(){
}

EntityFactory::EntityFactory(InputSystem* system) {
    inputSystem_ = system;
}

void EntityFactory::assignInputSystem(const InputSystem* system){
    if (!inputSystem_){
        inputSystem_ = system;
    }
}

Entity* EntityFactory::createPlayer(int x, int y, int vx, int vy){

    Entity* player = new Entity("player", 200, 200, 0, 0);
    player->addGraphics(new ShipGraphicsComponent());

    return player;
}

} // namespace demo
