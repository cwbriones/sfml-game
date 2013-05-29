#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "State.h"

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

private:
    GameState* currentState_;
	std::list<GameState*> stateStack_;
    void clearStack();

    std::list<GameState*> oldStates_;
};

#endif //STATEMANAGER_H
