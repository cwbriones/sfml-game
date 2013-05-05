/*
 * =====================================================================================
 *
 *       Filename:  mainmenustate.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2013 19:48:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Christian Briones (cb), cwbriones@berkeley.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef MAIN_MENU_STATE
#define MAIN_MENU_STATE

#include "state.h"

#include <SFML/graphics.hpp>

class MainMenuState : public GameState {
    public:
        void update();
        void render(sf::RenderWindow* window);
        void initialize();
};

#endif
