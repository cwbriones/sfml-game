#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "InputSystem.h"

#include <SFML/Graphics.hpp>

#include <string>

class StateManager;

class GameState {
public:
    enum States {
        MAIN_MENU,
        GAMEPLAY,
        CREDITS,
        NUM_STATES
    };

    GameState(){};
    GameState(StateManager* manager) : manager_(manager) {};
    GameState(std::string name, StateManager* manager) : 
        name_(name), manager_(manager) {};

    virtual void update(sf::Time delta) = 0;
    virtual void render(sf::RenderTarget* target) = 0;

    virtual void onEnter(){};
    virtual void onExit(){};

    virtual void onHidden(){};
    virtual void onRevealed(){};
    virtual bool readyForClose(){ return true; }

    void setManager(StateManager* manager){ 
        if (!manager_)
            manager_ = manager;
    };

    std::string getName(){ return name_; };
    virtual demo::InputSystem* getInputSystem(){
        return &inputSystem_;
    }
protected:
    std::string name_ = "";
    StateManager* manager_ = nullptr;
    demo::InputSystem inputSystem_;
};

#endif // GAMESTATE_H
