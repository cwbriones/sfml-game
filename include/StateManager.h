#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "InputSystem.h"
#include "GameState.h"

#include <string>
#include <list>

class StateManager {
public:
    StateManager();

    GameState* currentState();
    void clean();
    void clearAll();
	void clearToState(GameState* newState);

    void popState();
    void pushState(GameState* newState);

    void requestClose();
    bool closeRequested();
    void toggleUpdates();

    void notify(std::string event, std::string message);

    void assignInputSystem(demo::InputSystem* system);
    demo::InputSystem* getInputSystem();
private:
    GameState* currentState_;
	std::list<GameState*> stateStack_;
    void clearStack();

    std::list<GameState*> oldStates_;
    bool closeRequested_;
    bool showUpdates_;

    demo::InputSystem* inputSystem_ = nullptr;
};

#endif //STATEMANAGER_H
