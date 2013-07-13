#include "Entity.h"
#include "Vector2.h"

namespace demo {

Entity::Entity() : position_(0, 0), velocity_(0, 0), id_("null") {

    alive_ = true;

    input_ = nullptr;
    graphics_ = nullptr;
    physics = nullptr;
}

Entity::Entity(std::string id, float x, float y, float vx, float vy) :
        position_(x, y),
        velocity_(vx, vy),
        alive_(true),
        id_(id) {
}

Entity::~Entity(){
    if(graphics_){
        delete graphics_;
    }
    if(physics_){
        delete physics_;
    }
    if(input_){
        delete input_;
    }
}

void Entity::addGraphics(GraphicsComponent* graphics){
    if (!graphics_){
        this.graphics_ = graphics;
    }
}

void Entity::addPhysics(PhysicsComponent* physics){
    if (!physics_){
        this.physics_ = physics;
    }
}

void Entity::addInput(InputComponent* input){
    if (!input_){
        this.input_ = input;
    }
}

void Entity::setAlive(bool alive){
    alive_ = alive;
}

bool Entity::isAlive(){
    return alive_;
}

} // namespace demo
