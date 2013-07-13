#include "Component/ShipGraphicsComponent.h"
#include "Entity.h"

#include <SFML/Graphics/CircleShape.hpp>

namespace demo {

void ShipGraphicsComponent::ShipGraphicsComponent() : shape(40, 3) {
}

void ShipGraphicsComponent::update(Entity& entity, sf::RenderTarget& target){
    target.draw(shape);
}

} // namespace demo
