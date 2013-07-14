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

    for(int i = 0; i < NUM_VERTICES; i++){
        vertices_[i].position = sf::Vector2f(SCALE * xCoords[i], SCALE * yCoords[i]);
    }
    // Draw line to fully enclose shape
    vertices_[NUM_VERTICES] = sf::Vector2f(SCALE * xCoords[0], SCALE * yCoords[0]);
}

void ShipGraphicsComponent::update(Entity& entity, int delta){

}

void ShipGraphicsComponent::render(sf::RenderTarget& target){
    target.draw(vertices_);
}

} // namespace demo
