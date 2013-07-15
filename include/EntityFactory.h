#ifndef ENTITY_FACTORY
#define ENTITY_FACTORY

namespace demo {

class Entity;
class InputSystem;

class EntityFactory
{
    public:
        EntityFactory();
        EntityFactory(InputSystem* system);
        Entity* createPlayer(int x, int y, int vx, int vy);
        void assignInputSystem(InputSystem* system);
    private:
        InputSystem* inputSystem_ = nullptr;
}; // EntityFactory

} // namespace demo

#endif // ENTITY_FACTORY
