#ifndef DEMO_SHIP_GRAPHICS_COMPONENT_H
#define DEMO_SHIP_GRAPHICS_COMPONENT_H

#include "Component/GraphicsComponent.h"
#include "Component/ShipGraphicsComponent.h"

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace demo {

class Entity;

class ShipGraphicsComponent : public GraphicsComponent
{
public:
    ShipGraphicsComponent();

    sf::Vector2f getCenter();
private:
    sf::VertexArray vertices_;
    const sf::Vector2f center_;
protected:
    virtual void update(Entity& entity, int delta);
    virtual void render(Entity& entity, sf::RenderTarget& target);
};

} // namespace demo

#endif // DEMO_SHIP_GRAPHICS_COMPONENT_H
