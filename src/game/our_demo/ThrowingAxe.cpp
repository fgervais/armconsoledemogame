/*
 * ThrowingAxe.cpp
 *
 *  Created on: 2010-06-14
 *      Author: DUPA
 */

#include "ThrowingAxe.h"
#include "ThrowingAxeState.h"
#include "Environment.h"
#include "Megaman.h"
#include "ThrowingAxeShotLeft.h"
#include "VisibleArea.h"
#include "Random.h"
//#include "BusterShotRight.h"
#include <iostream>
using namespace std;
//#include "LPC2478.h"


ThrowingAxe::ThrowingAxe(ThrowingAxeState* initialState, Environment* environment, uint32_t positionX, uint32_t positionY) :  Entity(initialState, environment) {

	// Keep a pointer to the initial state in case we need to re-spawn the sprite
	//this->initialState = initialState;
	this->currentState = initialState;
	this->setPositionX(positionX);
	this->setPositionY(positionY+15);
	//this->setVelocityY(-2);

	//Random* randomGen = new Random();

	//uint32_t test=0;

	setBaseDamage(3);
	setCurrentDamage(3);
	setBaseSpeed(5);
	setCurrentSpeed(5);
	offScreen=0;

	// Unsafe?
	this->currentState->initialize(this);

	//Initialize every possible Buster states
	//BusterWalkingLeft = BusterWalkingLeft::createInstance();
	//BusterWalkingLeft = BusterWalkingRight::createInstance();
}

ThrowingAxe::~ThrowingAxe() {

}

void ThrowingAxe::setState(ThrowingAxeState* state)  {
	this->currentState = state;

	// Do state entry initialization on the sprite
	currentState->initialize(this);

	// Send state to the superclass
	Sprite::setState(state);
}

void ThrowingAxe::update() {
	//test++;
	//uint32_t randomed = randomGen->getRandom(1, test);
	//cout << randomed << endl ;
	environment->move(this, positionX+velocityX, positionY+velocityY);

	VisibleArea* visibleArea = environment->getVisibleArea();

	collisionCheckEnabled = true;

	if(collisionCheckEnabled) {
		environment->checkCollision(this);
	}

	// Update the currently displayed frame
	// And possibly some state specific things
	currentState->update(this);


	// if the shot has touched the ground
	if(this->isOnGround())
	{
		environment->deactivate(this);
		environment->getHero()->removeChild(this);
		((Megaman*)environment->getHero())->decCurrentBusterNum();
	}

	// if the shot is outside the screen
	if(positionX <= visibleArea->x || positionX >= visibleArea->x + visibleArea->width ||
			positionY <= visibleArea->y || positionY >= visibleArea->y + visibleArea->height)
		{
			//cout << "axe has reached the top" << endl;
			environment->deactivate(this);
			offScreen=1;
		}
	else offScreen=0;
}

void ThrowingAxe::collideWith(Collider* collider) {
	collider->collideWith(this);
	cout << "buster collided";
}

void ThrowingAxe::collideWith(Megaman*) {
	//cout << "Buster collided with Megaman";
	//LPC2478::delay(1000000);
}

void ThrowingAxe::collideWith(Metool*) {
	//metoo->collideWith(this);
	//cout << "Buster collided with Metool";
	//LPC2478::delay(1000000);
}


