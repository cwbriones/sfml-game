#ifndef ENTITY_FACTORY
#define ENTITY_FACTORY

namespace demo {

class Entity;
class InputSystem;

class EntityFactory
{
    public:
        EntityFactory();
        Entity* createPlayer(int x, int y, int vx, int vy);
}; // EntityFactory

} // namespace demo

#endif // ENTITY_FACTORY
