#include "EntityFactory.h"
#include "Entity.h"
#include "Component/ShipGraphicsComponent.h"

namespace demo {

// TODO: Make sure there is no memory leak when adding components to entities

Entity* EntityFactory::createPlayer(int x, int y, int vx, int vy){

    Entity* player = new Entity("player", 200, 200, 0, 0);
    player->addGraphics(new ShipGraphicsComponent());
}

} // namespace demo
