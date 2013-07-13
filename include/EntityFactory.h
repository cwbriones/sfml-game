#ifndef ENTITY_FACTORY
#define ENTITY_FACTORY

namespace demo {

class Entity;

class EntityFactory
{
    public:
        Entity* createPlayer(int x, int y, int vx, int vy);
};

} // namespace demo

#endif // ENTITY_FACTORY
