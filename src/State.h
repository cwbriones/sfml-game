#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

class StateManager;

class GameState {
public:
    enum States {
        MAIN_MENU,
        GAMEPLAY,
        NUM_STATES
    };

    GameState() : manager_(nullptr) {};
    GameState(int id) : manager_(nullptr), id_(id){};

    virtual void update(sf::Time delta) = 0;
    virtual void render(sf::RenderTarget* target) = 0;

    virtual void onEnter() = 0;
    virtual void onExit() = 0;

    virtual void onHidden() = 0;
    virtual void onRevealed() = 0;

    virtual void onKeyPressed(int keycode) = 0;
    virtual void onKeyReleased(int keycode) = 0;

    virtual bool readyForClose(){ return true; };
    void setManager(StateManager* manager){ manager_ = manager; };

    void setID(int id){ id_ = id; };
    int getID() const { return id_;};
protected:
    int id_;
    StateManager* manager_;
    };

#endif // GAMESTATE_H
