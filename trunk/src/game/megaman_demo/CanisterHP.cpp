/*
 * CanisterHP.cpp
 *
 *  Created on: May 12, 2010
 *      Author: fgervais
 *      Edited: Brass
 */

#include "CanisterHP.h"
#include "Buster.h"
#include "CanisterHPState.h"
#include "Environment.h"
#include "CanisterHPIddleState.h"
//#include "CanisterHPWalkingLeft.h"
//#include "CanisterHPWalkingRight.h"
#include <iostream>
//#include "LPC2478.h"
using namespace std;

CanisterHP::CanisterHP(CanisterHPState* initialState, Environment* environment) : Entity(initialState, environment) {
	// Keep a pointer to the initial state in case we need to re-spawn the sprite
	//this->initialState = initialState;
	this->currentState = initialState;
/*
	setMaxHP(2);
	setCurrentHP(2);
	setBaseSpeed(4);
	setCurrentSpeed(4);
	setBaseDamage(3);
	setCurrentDamage(3);
*/
	// Unsafe?
	this->currentState->initialize(this);

	//Initialize every possible CanisterHP states
	//CanisterHPWalkingLeft = CanisterHPWalkingLeft::createInstance();
	//CanisterHPWalkingLeft = CanisterHPWalkingRight::createInstance();
}

CanisterHP::~CanisterHP() {

}



void CanisterHP::setState(CanisterHPState* state)  {
	this->currentState = state;

	// Do state entry initialization on the sprite
	currentState->initialize(this);

	// Send state to the superclass
	Sprite::setState(state);
}

void CanisterHP::update() {
	environment->move(this, positionX+velocityX, positionY+velocityY);

	// Update the currently displayed frame
	// And possibly some state specific things
	currentState->update(this);
}

void CanisterHP::collideWith(Collider* collider) {
	collider->collideWith(this);
}

void CanisterHP::collideWith(Megaman*) {
	//cout << "CanisterHP collided with Megaman";
	//LPC2478::delay(1000000);
	cout << "CanisterHP : Collided" << endl;
	environment->deactivate(this);
}


