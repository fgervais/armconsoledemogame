/*
 * Graphic.cpp
 *
 *  Created on: Mar 8, 2010
 *      Author: fgervais
 */

#include "Graphic.h"
#include "Environment.h"
#include "VisibleArea.h"
#include "SDL.h"

Graphic::Graphic(uint32_t height, uint32_t width, uint32_t** handles, uint32_t numberOfFrame) {
	this->height = height;
	this->width = width;
	this->handles = handles;
	this->numberOfFrame = numberOfFrame;
	this->currentFrame = 0;
	this->environment = 0;
}

Graphic::~Graphic() {
	/* Free memory */
	for(uint32_t i=0; i<numberOfFrame; i++) {
		delete[] handles[i];
	}
	delete[] handles;
}

void Graphic::update() {

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
void Graphic::render(SDL_Surface* sdl_Surface) {
	VisibleArea* visibleArea = environment->getVisibleArea();

	uint32_t renderPositionX = positionX - visibleArea->x;
	uint32_t renderPositionY = positionY - visibleArea->y;

	/*
	 * These are used to subtract part of the image from the
	 * rendering process.
	 */
	uint32_t renderMaskX1 = 0;
	uint32_t renderMaskY1 = 0;
	uint32_t renderMaskX2 = width;
	uint32_t renderMaskY2 = height;

	/*
	 * These 4 following tests check if part of the image is outside
	 * the visible area. If so, t set the render mask so it won't
	 * render the part outside the screen.
	 */
	if(positionX < visibleArea->x) {
		renderMaskX1 = visibleArea->x - positionX;
		renderPositionX = visibleArea->x;
	}
	if(positionY < visibleArea->y) {
		renderMaskY1 = visibleArea->y - positionY;
		renderPositionY = visibleArea->y;
	}
	if((positionX+width) > (visibleArea->x+visibleArea->width)) {
		renderMaskX2 = (positionX+width) - (visibleArea->x+visibleArea->width);
	}
	if((positionY+height) > (visibleArea->y+visibleArea->height)) {
		renderMaskY2 = (positionY+height) - (visibleArea->y+visibleArea->height);
	}

	// Draw the image on the screen
	uint32_t sdl_SurfaceWidth = sdl_Surface->w;
	//uint32_t* sdl_SurfacePointer = sdl_Surface->getPointer();
	uint32_t renderWidth = renderMaskX2 - renderMaskX1;
/*
	for (uint32_t i=renderMaskY1; i<renderMaskY2; i++) {
		for (uint32_t j=renderMaskX1; j<renderMaskX2; j++) {
			sdl_SurfacePointer[(i+renderPositionY)*sdl_SurfaceWidth + (j+renderPositionX)] = handles[currentFrame][i*renderWidth + j];
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
void Graphic::setPosition(uint32_t x, uint32_t y) {
	positionX = x;
	positionY = y;
}

void Graphic::set(Environment* environment) {
	this->environment = environment;
}
