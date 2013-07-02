#ifndef GAMESTATE_H
#define GAMESTATE_H

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

    GameState() : manager_(nullptr), id_(0), name_("") {};
    GameState(int id, std::string name) : 
        manager_(nullptr), id_(id), name_(name){};

    virtual void update(sf::Time delta) = 0;
    virtual void render(sf::RenderTarget* target) = 0;

    virtual void onEnter(){};
    virtual void onExit(){};

    virtual void onHidden(){};
    virtual void onRevealed(){};

    virtual void onKeyPressed(int keycode) = 0;
    virtual void onKeyReleased(int keycode) = 0;

    virtual bool readyForClose(){ return false; }
    void setManager(StateManager* manager){ manager_ = manager; };

    void setID(int id){ id_ = id; };
    int getID() const { return id_;};
    std::string getName(){ return name_; };
protected:
    int id_;
    std::string name_;
    StateManager* manager_;
    };

#endif // GAMESTATE_H
