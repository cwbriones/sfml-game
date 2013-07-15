#ifndef DEMO_BASE_COMPONENT_H
#define DEMO_BASE_COMPONENT_H

namespace demo {

struct BaseComponent
{
    virtual void update(Entity& owner, int delta) = 0;
};

}

#endif // DEMO_BASE_COMPONENT_H
