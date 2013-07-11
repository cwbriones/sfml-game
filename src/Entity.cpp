#include "Entity.h"
#include "Vector2.h"

demo::Entity::Entity() : position_(0, 0), velocity_(0, 0), id_("null") {
    alive_ = true;
}

demo::Entity::Entity(std::string id, float x, float y, float vx, float vy) :
        position_(x, y),
        velocity_(vx, vy),
        alive_(true),
        id_(id) {
}

void demo::Entity::setAlive(bool alive){
    alive_ = alive;
}

void demo::Entity::move(){
    position_.add(velocity_);
}

bool demo::Entity::isAlive(){
    return alive_;
}
