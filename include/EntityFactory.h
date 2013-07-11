#ifndef ENTITY_FACTORY
#define ENTITY_FACTORY

namespace demo {

class EntityFactory
{
    public:
        EntityFactory();
        Entity* createdemoeroid();
        Entity* createPlayer();
        Entity* createUFO();
};

} // namespace demo

#endif // ENTITY_FACTORY
