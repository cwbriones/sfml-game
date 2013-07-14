#ifndef DEMO_GRAPHICS_COMPONENT_H
#define DEMO_GRAPHICS_COMPONENT_H

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transform.hpp>

namespace demo {

class Entity;

class GraphicsComponent
{
public:
    virtual void update(Entity& owner, int delta) = 0;
    virtual void render(sf::RenderTarget& target) = 0;
protected:
    sf::Transform transform;
}; // GraphicsComponent

} // namespace demo

#endif // DEMO_GRAPHICS_COMPONENT_H
