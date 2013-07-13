#ifndef ENTITY_FACTORY
#define ENTITY_FACTORY

namespace demo {

class EntityFactory
{
    public:
        Entity* createPlayer(int x, int y);
};

} // namespace demo

#endif // ENTITY_FACTORY
