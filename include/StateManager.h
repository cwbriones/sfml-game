#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "InputSystem.h"
#include "GameState.h"

#include <string>
#include <list>

class Game;

class StateManager {
public:
    StateManager(Game* game);
    ~StateManager(); 

    Game* game();
    GameState* currentState();
    GameState* hiddenState();

    /*
     * void StateManager::clean()
     * Deletes all of the pointers to states no longer needed
     */
    void clean();
    /*
     * void StateManager::clearAll()
     * Clears the current state stack and then cleans.
     */
    void clearAll();
	void clearToState(GameState* newState);

    void popState();
    void pushState(GameState* newState);

    void requestClose();
    bool closeRequested();
    void toggleUpdates();

    void notify(std::string event, std::string message);
    void sendInputToCurrentState();
private:
    Game* game_ = nullptr;
    GameState* currentState_ = nullptr;
    GameState* hiddenState_ = nullptr;

	std::list<GameState*> stateStack_;
    void clearStack();

    std::list<GameState*> oldStates_;
    bool closeRequested_;
    bool showUpdates_;
    demo::InputSystem nullInputSystem_;
};

#endif //STATEMANAGER_H
