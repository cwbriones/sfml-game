#ifndef DEMO_PLAYER_GRAPHICS_COMPONENT_H
#define DEMO_PLAYER_GRAPHICS_COMPONENT_H

#include "GraphicsComponent.h"

namespace demo {

class PlayerGraphicsComponent : public GraphicsComponent
{
public:
    PlayerGraphicsComponent();
    virtual void update(Entity& owner, sf::RenderTarget& target, int delta);
}; // PlayerGraphicsComponent

} // namespace demo
#endif
