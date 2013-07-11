#include "Entity.h"
#include "Vector.h"

ast::Entity::Entity() : position_(0, 0), velocity_(0, 0), id_("null") {
    alive_ = true;
}

ast::Entity::Entity(std::string id, float x, float y, float vx, float vy) :
        position_(x, y),
        velocity_(vx, vy),
        alive_(true),
        id_(id) {
}

void ast::Entity::setAlive(bool alive){
    alive_ = alive;
}

void ast::Entity::move(){
    position_.add(velocity_);
}

bool ast::Entity::isAlive(){
    return alive_;
}
