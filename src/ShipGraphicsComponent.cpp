#include "Component/ShipGraphicsComponent.h"
#include "Entity.h"

#include <SFML/Graphics/CircleShape.hpp>

namespace demo {

ShipGraphicsComponent::ShipGraphicsComponent() : shape_(40, 3) {
}

void ShipGraphicsComponent::update(Entity& entity, int delta){

}

void ShipGraphicsComponent::render(sf::RenderTarget& target){
    target.draw(shape_);
}

} // namespace demo
