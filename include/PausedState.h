#ifndef DEMO_PAUSED_STATE_H
#define DEMO_PAUSED_STATE_H

#include "GameState.h"

class PausedState : public GameState {
    public:
        virtual void update(sf::Time delta);
        virtual void render(sf::RenderTarget* target);
};

#endif DEMO_PAUSED_STATE_H
