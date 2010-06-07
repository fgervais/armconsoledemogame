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

LifeGauge::LifeGauge(LifeGaugeState* initialState, Environment* environment) : ClipableSprite(initialState, environment) {
	// Keep a pointer to the initial state in case we need to re-spawn the sprite
	//this->initialState = initialState;
	this->currentState = initialState;

	// FIXME Unsafe?
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
	environment->move(this, visibleArea->x+getOffsetX(), visibleArea->y+getOffsetY());

	//cout << this->getPositionX() << " " << this->getPositionY() << endl;

	// Update the currently displayed frame
	// And possibly some state specific things
	currentState->update(this);

}
