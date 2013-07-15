#include "StateManager.h"

#include <iostream>
/*
 * Create a state manager with the given initial state.
 */
StateManager::StateManager() {
	currentState_ = nullptr;
    showUpdates_ = false;
    closeRequested_ = false;
}

void StateManager::notify(std::string event, std::string message){
    if (! showUpdates_){
        return;
    }

    std::cout << "[StateManager] " << event 
        << ": " << message << std::endl;
}

void StateManager::toggleUpdates(){
    showUpdates_ = !showUpdates_;
}

void StateManager::popState(){
    GameState* oldState = stateStack_.back();
    oldState->onExit();

    notify("Exiting", currentState_->getName());

    oldStates_.push_back(oldState);
    stateStack_.pop_back();

    if (stateStack_.size() > 0){
        currentState_ = stateStack_.back();
        currentState_->onRevealed();
        notify("Revealing", currentState_->getName());
    } else {
        currentState_ = nullptr;
    }
 }

void StateManager::pushState(GameState* newState){
    newState->setManager(this);
    if (stateStack_.size() > 0){
        stateStack_.back()->onHidden();
        notify("Hiding", currentState_->getName());
    }

    stateStack_.push_back(newState);
    stateStack_.back()->onEnter();

    currentState_ = stateStack_.back();
    notify("Entering", currentState_->getName());
}

void StateManager::clearToState(GameState* newState){
    newState->setManager(this);
    if (!stateStack_.empty()){
        clearAll();
    }
    notify("State Clear", "Successful"); 
    stateStack_.push_back(newState);
    currentState_ = stateStack_.back();
    currentState_->onEnter();
    notify("Entering", currentState_->getName());
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
    while (!oldStates_.empty()){
        delete oldStates_.back();
        oldStates_.pop_back();
    }
}

void StateManager::clearAll(){
    clearStack();
    clean();
    currentState_ = nullptr;
}

void StateManager::requestClose(){
    closeRequested_ = true;
}

bool StateManager::closeRequested(){
    if (closeRequested_){
        closeRequested_ = false;
        return true;
    }
}

void StateManager::assignInputSystem(demo::InputSystem* system){
    if (!inputSystem_){
        inputSystem_ = system;
    }
}

demo::InputSystem* StateManager::getInputSystem(){
    return inputSystem_;
}
