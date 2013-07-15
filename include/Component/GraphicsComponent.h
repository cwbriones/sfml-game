#ifndef DEMO_GRAPHICS_COMPONENT_H
#define DEMO_GRAPHICS_COMPONENT_H

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transform.hpp>

namespace demo {

class Entity;

class GraphicsComponent
{
public:
    virtual void update(Entity& entity, int delta) = 0;
    virtual void render(Entity& entity, sf::RenderTarget& target) = 0;
}; // GraphicsComponent

} // namespace demo

#endif // DEMO_GRAPHICS_COMPONENT_H
