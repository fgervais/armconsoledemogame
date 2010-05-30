/*
 * Buster.cpp
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#include "Buster.h"
#include "BusterState.h"
#include "Environment.h"
#include "BusterShotLeft.h"
//#include "BusterShotRight.h"
#include <iostream>
using namespace std;
//#include "LPC2478.h"

Buster::Buster(BusterState* initialState, Environment* environment, uint32_t positionX, uint32_t positionY) : Sprite(initialState, environment) {
	// Keep a pointer to the initial state in case we need to re-spawn the sprite
	//this->initialState = initialState;
	this->currentState = initialState;
	this->setPositionX(positionX);
	this->setPositionY(positionY+15);

	// Unsafe?
	this->currentState->initialize(this);

	//Initialize every possible Buster states
	//BusterWalkingLeft = BusterWalkingLeft::createInstance();
	//BusterWalkingLeft = BusterWalkingRight::createInstance();
}

Buster::~Buster() {

}

void Buster::setState(BusterState* state)  {
	this->currentState = state;

	// Do state entry initialization on the sprite
	currentState->initialize(this);

	// Send state to the superclass
	Sprite::setState(state);
}

void Buster::update() {
	environment->move(this, positionX+velocityX, positionY+velocityY);

	collisionCheckEnabled = true;

	if(collisionCheckEnabled) {
		environment->checkCollision(this);
	}

	// Update the currently displayed frame
	// And possibly some state specific things
	currentState->update(this);
}

void Buster::collideWith(Collider* collider) {
	collider->collideWith(this);
}

void Buster::collideWith(Megaman*) {
	//cout << "Buster collided with Megaman";
	//LPC2478::delay(1000000);
}

void Buster::collideWith(Metool*) {
	//cout << "Buster collided with Metool";
	//LPC2478::delay(1000000);
}


