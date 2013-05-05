/*
 * =====================================================================================
 *
 *       Filename:  state.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2013 16:19:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Christian Briones (cb), cwbriones@berkeley.edu
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

class GameState {

public:
    virtual void initialize() = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow* window) = 0;
};

#endif // GAMESTATE_H
