#ifndef DEMO_PHYSICS_COMPONENT_H
#define DEMO_PHYSICS_COMPONENT_H 

namespace demo {

class PhysicsComponent
{
public:
    PhysicsComponent();
    virtual void update(int delta) = 0;
    /* data */
};

} // namespace demo

#endif // DEMO_PHYSICS_COMPONENT_H
