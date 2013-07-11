#ifndef ENTITY_H
#define ENTITY_H 

#include "Vector.h"
#include <string>

namespace ast {

class Entity
{
public:
    Entity();
    Entity(std::string id, float x, float y, float vx, float vy);
    void setAlive(bool alive);
    void move();
    bool isAlive();

    std::string getID();
private:
    Vector2d position_;
    Vector2d velocity_;

    bool alive_;
    std::string id_;
}; // class Entity

} // namespace ast


#endif // ENTITY_H
