/*
 * Megaman.cpp
 *
 *  Created on: Mar 8, 2010
 *      Author: fgervais
 */

#include "LifeGauge.h"
#include "Environment.h"
#include "LifeGaugeState.h"
#include "LifeUnity.h"
#include "VisibleArea.h"
#include <iostream>
using namespace std;
//#include "LPC2478.h"

LifeGauge::LifeGauge(LifeGaugeState* initialState, Environment* environment) : Sprite(initialState, environment) {
	// Keep a pointer to the initial state in case we need to re-spawn the sprite
	//this->initialState = initialState;
	this->currentState = initialState;

	this->unity = new LifeUnity*[30];

	// FIXME Unsafe?

	for(uint32_t i=0; i < 30; i++) {
		this->unity[i] = (new LifeUnity(3,1,new Bitmap("src/display/interface/LifeGauge/unity.bmp"),environment));
	}
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

	for(uint32_t i=0; i < this->getLinkedSprite()->getCurrentHP(); i++) {
		this->getUnity(i)->render(sdl_Surface, offsetX+4, offsetY+((this->getLinkedSprite()->getMaxHP()-1-i)*2+2));
	}
}

LifeUnity * LifeGauge::getUnity(uint32_t num) {
	return unity[num];
}

void LifeGauge::linkTo(Megaman* sprite) {
	this->hero = sprite;
}

void LifeGauge::setOffset(uint32_t offsetX, uint32_t offsetY) {
	this->offsetX = offsetX;
	this->offsetY = offsetY;
}
