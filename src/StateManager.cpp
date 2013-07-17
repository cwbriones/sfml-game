#include "StateManager.h"
#include "Game.h"

#include <iostream>
/*
 * Create a state manager with the given initial state.
 */
StateManager::StateManager(Game* game) {
    game_ = game;
	currentState_ = nullptr;
    showUpdates_ = false;
    closeRequested_ = false;
    sendInputToCurrentState();
}

StateManager::~StateManager(){
    clearStack();
    clean();
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
    sendInputToCurrentState();
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
    sendInputToCurrentState();
}

void StateManager::clearToState(GameState* newState){
    newState->setManager(this);
    clearStack();
    notify("State Clear", "Successful"); 

    currentState_ = newState;
    stateStack_.push_back(newState);
    currentState_->onEnter();

    notify("Entering", currentState_->getName());
    sendInputToCurrentState();
}

void StateManager::clearStack(){
    while (!stateStack_.empty()){
        GameState* oldState = stateStack_.back();
        oldState->onExit();
        oldStates_.push_back(oldState);
        stateStack_.pop_back();
    }
    currentState_ = nullptr;
    sendInputToCurrentState();
}

GameState* StateManager::currentState(){
    return currentState_;
}

void StateManager::clean(){
    while (!oldStates_.empty()){
        notify("Deleting", oldStates_.back()->getName());
        delete oldStates_.back();
        oldStates_.pop_back();
    }
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

Game* StateManager::game(){
    return game_;
}

void StateManager::sendInputToCurrentState(){
    if(currentState_){
        game_->setActiveInputSystem(currentState_->getInputSystem());
        notify("Switched active input", currentState_->getName() );
    } else {
        game_->setActiveInputSystem(&nullInputSystem_);
        notify("Switched active input", "NULL INPUT");
    }
}
