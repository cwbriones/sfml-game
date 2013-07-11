#ifndef DEMO_ENTITY_H
#define DEMO_ENTITY_H 

#include "Vector2.h"
#include "Component/GraphicsComponent.h"
#include "Component/PhysicsComponent.h"
#include "Component/InputComponent.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <string>

namespace demo {

class Entity
{
public:
    Entity();
    Entity(std::string id, 
            float x, float y, 
            float vx, float vy);

    bool isAlive();
    void setAlive(bool alive);
    std::string getID();

    void update(int delta, sf::RenderTarget& target)
private:
    Vector2f position_;
    Vector2f velocity_;

    InputComponent* input_;
    PhysicsComponent* physics_;
    GraphicsComponent* graphics_;

    bool alive_;
    std::string id_;
}; // class Entity

} // namespace demo


#endif // ENTITY_H
