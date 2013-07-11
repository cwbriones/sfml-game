#ifndef DEMO_ENTITY_H
#define DEMO_ENTITY_H 

#include "Vector2.h"
#include <string>

namespace demo {

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

} // namespace demo


#endif // ENTITY_H
