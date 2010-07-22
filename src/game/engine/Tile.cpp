/*
 * Tile.cpp
 *
 *  Created on: Mar 8, 2010
 *      Author: fgervais
 */

#include "Tile.h"
#include "Environment.h"
#include "SDL.h"
#include "VisibleArea.h"
#include "Bitmap.h"
#include "System.h"
#include <iostream>

Tile::Tile(uint32_t width, uint32_t height, Bitmap** frames, uint32_t numberOfFrame, Environment* environment) {
	this->width = width;
	this->height = height;
	this->frames = frames;
	this->numberOfFrame = numberOfFrame;
	this->currentFrame = 0;
	this->environment = environment;

	// Ensure every bitmap are loaded into memory
	for(uint32_t frameNumber=0; frameNumber<numberOfFrame; frameNumber++) {
		if(!(frames[frameNumber]->isLoaded())) {
			frames[frameNumber]->load();
		}
	}
}

Tile::~Tile() {

}

void Tile::update() {
	if(currentFrame < (numberOfFrame-1)) {
		currentFrame++;
	}
	else {
		currentFrame = 0;
	}
}

/**
 * This function is used to render a graphic on the screen.
 *
 * For now this function doen't check if we are trying to
 * render something completely outside the screen. The
 * parent object should take care of that.
 *
 * @param videoMemory The video memory
 */
void Tile::render(SDL_Surface* sdl_Surface) {
	System::render(this, sdl_Surface);

}

/**
 * Set the absolute position in the environment.
 *
 * @param x X position
 * @param y Y position
 */
void Tile::setPosition(uint32_t x, uint32_t y) {
	positionX = x;
	positionY = y;
}

void Tile::set(Environment* environment) {
	this->environment = environment;
}
