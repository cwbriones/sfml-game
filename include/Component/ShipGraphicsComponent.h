#include "Component/GraphicsComponent.h"
#include "Component/ShipGraphicsComponent.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace demo {

class Entity;

class ShipGraphicsComponent
{
public:
    ShipGraphicsComponent();
private:
    sf::CircleShape shape;
    virtual void update(Entity& entity, sf::RenderTarget& target);
};

} // namespace demo
