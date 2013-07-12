#ifndef DEMO_GRAPHICS_COMPONENT
#define DEMO_GRAPHICS_COMPONENT 

#include <SFML/Graphics/RenderTarget.hpp>

namespace demo {

class GraphicsComponent
{
public:
    virtual void update(Entity& entity, sf::RenderTarget& target) = 0;
private:
}; // GraphicsComponent

} // namespace demo

#endif
