#include "StateManager.h"

#include <iostream>
/*
 * Create a state manager with the given initial state.
 */
StateManager::StateManager() {
	currentState_ = nullptr;
}

void StateManager::popState(){
    GameState* oldState = stateStack_.back();
    oldState->onExit();
    oldStates_.push_back(oldState);
    stateStack_.pop_back();

    if (stateStack_.size() > 0){
        stateStack_.back()->onRevealed();
        currentState_ = stateStack_.back();
    } else {
        currentState_ = nullptr;
    }
 }

void StateManager::pushState(GameState* newState){
    newState->setManager(this);
    if (stateStack_.size() > 0){
        stateStack_.back()->onHidden();
    }

    stateStack_.push_back(newState);
    stateStack_.back()->onEnter();

    currentState_ = stateStack_.back();
}

void StateManager::clearToState(GameState* newState){
    newState->setManager(this);
    if (!stateStack_.empty()){
        clearStack();
    }
    
    stateStack_.push_back(newState);
    currentState_ = stateStack_.back();
    currentState_->onEnter();
}

void StateManager::clearStack(){
    while (!stateStack_.empty()){
        GameState* oldState = stateStack_.back();
        oldState->onExit();
        oldStates_.push_back(oldState);
        stateStack_.pop_back();
    }
}

GameState* StateManager::currentState(){
    return currentState_;
}

void StateManager::clean(){
    while (oldStates_.size() > 0){
        delete oldStates_.back();
        oldStates_.pop_back();
    }
}

void StateManager::clearAll(){
    clearStack();
    clean();
    currentState_ = nullptr;
}
