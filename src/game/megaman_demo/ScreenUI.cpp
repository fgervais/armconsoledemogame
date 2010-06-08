/*
 * Megaman.cpp
 *
 *  Created on: Mar 8, 2010
 *      Author: fgervais
 */

#include "ScreenUI.h"
#include "Environment.h"
#include "ScreenUIState.h"
#include "VisibleArea.h"
#include <iostream>
using namespace std;
//#include "LPC2478.h"

ScreenUI::ScreenUI(ScreenUIState* initialState, Environment* environment) : Sprite(initialState, environment) {
	// Keep a pointer to the initial state in case we need to re-spawn the sprite
	//this->initialState = initialState;
	this->currentState = initialState;

	// Unsafe?
	this->currentState->initialize(this);
}

ScreenUI::~ScreenUI() {

}

void ScreenUI::setState(ScreenUIState* state)  {

	this->currentState = state;

	// Do state entry initialization on the sprite
	state->initialize(this);

	// Send state to the superclass
	Sprite::setState(state);
}

void ScreenUI::update() {
	VisibleArea* visibleArea = environment->getVisibleArea();
	environment->move(this, visibleArea->x+getOffsetX(), visibleArea->y+getOffsetY());

	cout << this->getPositionX() << " " << this->getPositionY() << endl;

	// Update the currently displayed frame
	// And possibly some state specific things
	currentState->update(this);

}

void ScreenUI::linkTo(Sprite* sprite) {
	linkedSprite = sprite;
}

void ScreenUI::show() {
	this->isHidden = 0;
}

void ScreenUI::hide() {
	this->isHidden = 1;
}
