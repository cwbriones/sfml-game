#include "Component/ShipGraphicsComponent.h"
#include "Entity.h"

#include <SFML/Graphics/VertexArray.hpp>

namespace demo {

ShipGraphicsComponent::ShipGraphicsComponent() {
    const int NUM_VERTICES = 4;
    const float SCALE = 2.5;

    vertices_ = sf::VertexArray(sf::LinesStrip, NUM_VERTICES + 1);

    const int xCoords[NUM_VERTICES] = {0, 6, 12, 6};
    const int yCoords[NUM_VERTICES] = {15, 10, 15, 0};

    const sf::Vector2f center_(SCALE * 6.0f, SCALE * 7.5f);

    for(int i = 0; i < NUM_VERTICES; i++){
        vertices_[i].position = sf::Vector2f(SCALE * xCoords[i], SCALE * yCoords[i]);
    }
    // Draw line to fully enclose shape
    vertices_[NUM_VERTICES] = sf::Vector2f(SCALE * xCoords[0], SCALE * yCoords[0]);
}

void ShipGraphicsComponent::update(Entity& entity, int delta){
    // rotation_ += ROTATION_RATE * delta;
    const float ROTATION_RATE = 0.00628f * 2.0f;
    entity.rotate(ROTATION_RATE * delta);
}

sf::Vector2f ShipGraphicsComponent::getCenter(){
    return center_;
}

void ShipGraphicsComponent::render(Entity& entity, sf::RenderTarget& target){
    target.draw(vertices_, entity.getTransform());
}

} // namespace demo
