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
        void assignInputSystem(const InputSystem* system);
    private:
        const InputSystem* inputSystem_ = nullptr;
}; // EntityFactory

} // namespace demo

#endif // ENTITY_FACTORY
