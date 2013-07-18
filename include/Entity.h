#ifndef DEMO_ENTITY_H
#define DEMO_ENTITY_H 

#include "Vector2.h"
#include "Component/GraphicsComponent.h"
#include "Component/PhysicsComponent.h"

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <string>

// TODO: Add change(Component) methods

namespace demo {

class Entity : public sf::Transformable
{
public:
    Entity();
    Entity(std::string id, 
            float x, float y, 
            float vx, float vy);

    virtual ~Entity();

    bool isAlive();
    void setAlive(bool alive);
    std::string getID();

    void update(int delta);
    void render(sf::RenderTarget& target);

    void addPhysics(PhysicsComponent* physics);
    void addGraphics(GraphicsComponent* graphics);
private:
    sf::Vector2f velocity_;

    PhysicsComponent* physics_;
    GraphicsComponent* graphics_;

    bool alive_;
    std::string id_;
}; // class Entity

} // namespace demo


#endif // ENTITY_H
