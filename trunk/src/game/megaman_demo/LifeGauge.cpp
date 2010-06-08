/*
 * Megaman.cpp
 *
 *  Created on: Mar 8, 2010
 *      Author: fgervais
 */

#include "LifeGauge.h"
#include "Environment.h"
#include "LifeGaugeState.h"
#include "VisibleArea.h"
#include <iostream>
using namespace std;
//#include "LPC2478.h"

LifeGauge::LifeGauge(LifeGaugeState* initialState, Environment* environment) : Sprite(initialState, environment) {
	// Keep a pointer to the initial state in case we need to re-spawn the sprite
	//this->initialState = initialState;
	this->currentState = initialState;

	// FIXME Unsafe?
	unity = new Bitmap("src/display/interface/LifeGauge/unity.bmp");
	this->currentState->initialize(this);
}

LifeGauge::~LifeGauge() {

}

void LifeGauge::setState(LifeGaugeState* state)  {

	this->currentState = state;

	// Do state entry initialization on the sprite
	state->initialize(this);

	// Send state to the superclass
	Sprite::setState(state);
}

void LifeGauge::update() {
	VisibleArea* visibleArea = environment->getVisibleArea();
	environment->move(this, visibleArea->x + offsetX, visibleArea->y + offsetY);

	//cout << this->getPositionX() << " " << this->getPositionY() << endl;

	// Update the currently displayed frame
	// And possibly some state specific things
	currentState->update(this);

}

void LifeGauge::render(SDL_Surface* sdl_Surface) {
	Sprite::render(sdl_Surface);

	//Make a temporary rectangle to hold the offsets
	SDL_Rect offset;

	//Give the offsets to the rectangle
	offset.x = 605;
	offset.y = 50;

	//Blit the surface
	SDL_BlitSurface( unity->getData(), NULL, sdl_Surface, &offset );
}

void LifeGauge::linkTo(Sprite* sprite) {
	this->hero = sprite;
}

void LifeGauge::setOffset(uint32_t offsetX, uint32_t offsetY) {
	this->offsetX = offsetX;
	this->offsetY = offsetY;
}
