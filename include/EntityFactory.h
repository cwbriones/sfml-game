#ifndef ENTITY_FACTORY
#define ENTITY_FACTORY

namespace ast {

class EntityFactory
{
    public:
        EntityFactory();
        Entity* createAsteroid();
        Entity* createPlayer();
        Entity* createUFO();
};

} // namespace ast

#endif // ENTITY_FACTORY
