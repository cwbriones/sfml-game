#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "State.h"

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
    void toggleUpdates(){ showUpdates_ = !showUpdates_; };

    void notify(std::string event, std::string message);
private:
    GameState* currentState_;
	std::list<GameState*> stateStack_;
    void clearStack();

    std::list<GameState*> oldStates_;
    bool closeRequested_;
    bool showUpdates_;
};

#endif //STATEMANAGER_H
