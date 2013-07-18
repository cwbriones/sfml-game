#include "Entity.h"
#include "Vector2.h"

namespace demo {

Entity::Entity() : velocity_(0, 0), alive_(true), id_("null") {

    graphics_ = nullptr;
    physics_ = nullptr;

    setPosition(0, 0);
}

Entity::Entity(std::string id, float x, float y, float vx, float vy) :
        velocity_(vx, vy),
        alive_(true),
        id_(id) {

    graphics_ = nullptr;
    physics_ = nullptr;

    setPosition(x, y);
}

Entity::~Entity(){
    if(graphics_){
        delete graphics_;
    }
    if(physics_){
        delete physics_;
    }
}

void Entity::update(int delta){
    if (graphics_){
        graphics_->update(*this , delta);
    }
    if (physics_){
        physics_->update(*this, delta);
    }
}

void Entity::render(sf::RenderTarget& target){
    if (graphics_) {
        graphics_->render(*this, target);
    }
}

void Entity::addGraphics(GraphicsComponent* graphics){
    if (!graphics_){
        this->graphics_ = graphics;
    }
}

void Entity::addPhysics(PhysicsComponent* physics){
    if (!physics_){
        this->physics_ = physics;
    }
}

void Entity::setAlive(bool alive){
    alive_ = alive;
}

bool Entity::isAlive(){
    return alive_;
}

} // namespace demo
