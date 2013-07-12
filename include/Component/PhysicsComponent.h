#ifndef DEMO_PHYSICS_COMPONENT_H
#define DEMO_PHYSICS_COMPONENT_H 

namespace demo {

class PhysicsComponent
{
public:
    virtual void update(int delta) = 0;
}; // PhysicsComponent

} // namespace demo

#endif // DEMO_PHYSICS_COMPONENT_H
