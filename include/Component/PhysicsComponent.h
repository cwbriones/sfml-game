#ifndef DEMO_PHYSICS_COMPONENT_H
#define DEMO_PHYSICS_COMPONENT_H 

namespace demo {

class Entity;
    
class PhysicsComponent
{
public:
    virtual void update(Entity& owner, int delta) = 0;
}; // PhysicsComponent

} // namespace demo

#endif // DEMO_PHYSICS_COMPONENT_H
