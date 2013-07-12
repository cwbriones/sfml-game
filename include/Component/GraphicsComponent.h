#ifndef DEMO_GRAPHICS_COMPONENT
#define DEMO_GRAPHICS_COMPONENT 

#include <SFML/Graphics/RenderTarget.hpp>

namespace demo {

class GraphicsComponent
{
public:
    virtual void update(Entity& owner, sf::RenderTarget& target, int delta) = 0;
}; // GraphicsComponent

} // namespace demo

#endif
