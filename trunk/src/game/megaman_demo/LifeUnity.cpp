/*
 * Tile.cpp
 *
 *  Created on: Mar 8, 2010
 *      Author: fgervais
 */

#include "LifeUnity.h"
#include "Environment.h"
#include "SDL.h"
#include "VisibleArea.h"
#include "Bitmap.h"
#include <iostream>

LifeUnity::LifeUnity(uint32_t width, uint32_t height, Bitmap* frame, Environment* environment) {
	this->width = width;
	this->height = height;
	this->frame = frame;
	this->environment = environment;

	// Ensure every bitmap are loaded into memory
	if(!(frame->isLoaded())) {
		frame->load();
	}
}

LifeUnity::~LifeUnity() {

}

void LifeUnity::update() {
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
void LifeUnity::render(SDL_Surface* sdl_Surface, uint32_t positionX, uint32_t positionY) {

	//Make a temporary rectangle to hold the offsets
	SDL_Rect offset;
	//Give the offsets to the rectangle
	offset.x = positionX;
	offset.y = positionY;
	SDL_BlitSurface( frame->getData(), NULL, sdl_Surface, &offset );

	/*
	// Get x,y coordinates inside the visible area
	uint32_t renderPositionX = positionX - visibleArea->x;
	uint32_t renderPositionY = positionY - visibleArea->y;


	 * These are used to subtract part of the image from the
	 * rendering process.

	uint32_t renderMaskX1 = 0;
	uint32_t renderMaskY1 = 0;
	uint32_t renderMaskX2 = width;
	uint32_t renderMaskY2 = height;


	 * These 4 following tests check if part of the image is outside
	 * the visible area. If so, set the render mask so it won't
	 * render the part outside the screen.

	if(positionX < visibleArea->x) {
		renderMaskX1 = visibleArea->x - positionX;
		renderPositionX = 0;
	}
	if(positionY < visibleArea->y) {
		renderMaskY1 = visibleArea->y - positionY;
		renderPositionY = 0;
	}
	if((positionX+width) > (visibleArea->x+visibleArea->width)) {
		renderMaskX2 = (visibleArea->x+visibleArea->width) - positionX;
	}
	if((positionY+height) > (visibleArea->y+visibleArea->height)) {
		renderMaskY2 = (visibleArea->y+visibleArea->height) - positionY;
	}

	// Draw the image on the screen
	uint32_t sdl_SurfaceWidth = sdl_Surface->w;
	uint32_t* sdl_SurfacePointer = sdl_Surface->getPointer();

	// Render the part of the LifeUnity inside the render mask
	for (uint32_t i=renderMaskY1; i<renderMaskY2; i++) {
		for (uint32_t j=renderMaskX1; j<renderMaskX2; j++) {
			// This is complicated to understand but I don't think we can simplify it
			sdl_SurfacePointer[((i-renderMaskY1)+renderPositionY)*sdl_SurfaceWidth + ((j-renderMaskX1)+renderPositionX)]
							   = frames[currentFrame]->getData()[i*width + j];
		}
	}
	*/
}

/**
 * Set the absolute position in the environment.
 *
 * @param x X position
 * @param y Y position
 */
void LifeUnity::setPosition(uint32_t x, uint32_t y) {
	positionX = x;
	positionY = y;
}

void LifeUnity::set(Environment* environment) {
	this->environment = environment;
}
