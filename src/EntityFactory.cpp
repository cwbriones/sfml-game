#include "Entity.h"
#include "EntityFactory.h"

#include "Component/ShipGraphicsComponent.h"

namespace demo {

EntityFactory::EntityFactory(){
}

Entity* EntityFactory::createPlayer(int x, int y, int vx, int vy){

    Entity* player = new Entity("player", 200, 200, 0, 0);
    player->addGraphics(new ShipGraphicsComponent());

    return player;
}

} // namespace demo
