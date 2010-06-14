/*
 * InputHandler.h
 *
 *  Created on: 2010-06-14
 *      Author: Emile
 */

#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include "Environment.h"
#include "SDL.h"

class InputHandler {
public:
	InputHandler();
	virtual ~InputHandler();
	uint8_t handleInput(Environment*);
private:
	SDL_Event event;
};

#endif /* INPUTHANDLER_H_ */
