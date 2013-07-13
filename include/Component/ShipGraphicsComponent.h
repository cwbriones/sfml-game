#ifndef DEMO_SHIP_GRAPHICS_COMPONENT_H
#define DEMO_SHIP_GRAPHICS_COMPONENT_H

#include "Component/GraphicsComponent.h"
#include "Component/ShipGraphicsComponent.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace demo {

class Entity;

class ShipGraphicsComponent : public GraphicsComponent
{
public:
    ShipGraphicsComponent();
private:
    sf::CircleShape shape_;
    virtual void update(Entity& entity, int delta);
    virtual void render(sf::RenderTarget& target);
};

} // namespace demo

#endif // DEMO_SHIP_GRAPHICS_COMPONENT_H
