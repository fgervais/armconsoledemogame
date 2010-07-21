/*
 * InputHandler.cpp
 *
 *  Created on: 2010-06-14
 *      Author: Emile
 */

#include "InputHandler.h"
#include "Megaman.h"
#include <iostream>
using namespace std;

InputHandler::InputHandler() {
}

InputHandler::~InputHandler() {

}

uint8_t InputHandler::handleInput(Environment* environment) {
	//Get the keystates, used to know if a key is currently pressed
	Uint8 *keystates = SDL_GetKeyState(NULL);

	// Key event : This "if" returns true only if a key have been pressed
	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			//Quit the program
			return true;
		}
		if (event.key.keysym.sym != SDLK_LAST) {
			uint32_t eventKey = event.key.keysym.sym;
			//If a key was pressed
			if (event.type == SDL_KEYDOWN) {
				//cout << "key pressed = " << event.key.keysym.sym << endl;
				//Set the proper message surface
				switch (eventKey) {
				case SDLK_c:
				//	((Megaman*) environment->getHero())->charge();
					((Megaman*) environment->getHero())->shot();
					break;

				case SDLK_x:
					((Megaman*) environment->getHero())->jump();
					break;
				case SDLK_a :
					{
					((Megaman*) environment->getHero())->changeWeapon();
					cout << "current weapon :"<< ((Megaman*) environment->getHero())->getCurrentWeapon()<< endl;

					break;
					}
				case SDLK_z:
					((Megaman*) environment->getHero())->slide();
					break;
				case SDLK_LEFT:
					((Megaman*) environment->getHero())->runLeft();
					break;
				case SDLK_RIGHT:
					if (!keystates[SDLK_LEFT])
						((Megaman*) environment->getHero())->runRight();
					break;
				}
			}

			if (event.type == SDL_KEYUP) {
				//Set the proper message surface
				switch (eventKey) {
				case SDLK_LEFT:
					if (!keystates[SDLK_RIGHT])
						((Megaman*) environment->getHero())->stopRunning();
					break;
				case SDLK_RIGHT:
					if (!keystates[SDLK_LEFT])
						((Megaman*) environment->getHero())->stopRunning();
					break;
				case SDLK_x:
					((Megaman*) environment->getHero())->stopJumping();
					break;
				case SDLK_z:
					((Megaman*) environment->getHero())->stopSliding();
					break;
				case SDLK_c:
					((Megaman*) environment->getHero())->stopShooting();
					break;

				}
			}
		}// end here if event.key.keysym.sym == SDLK_LAST that is not handle in switch
	}// end here if no keys is pressed

	if (keystates[SDLK_LEFT]) {
		((Megaman*) environment->getHero())->runLeft();
	} else if (keystates[SDLK_RIGHT]) {
		((Megaman*) environment->getHero())->runRight();
	}

	// End of the key handler


	//If the user has Xed out the window
	else if (event.type == SDL_QUIT) {
		//Quit the program
		return true;
	}
	return false;
}
