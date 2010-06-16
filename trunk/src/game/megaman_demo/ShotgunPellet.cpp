/*
 * ShotgunPellet.cpp
 *
 *  Created on: 2010-05-29
 *      Author: DUPA
 */

#include "ShotgunPellet.h"
#include "Metool.h"
#include "ShotgunState.h"
#include "Environment.h"
#include "Megaman.h"
#include "ShotgunShotLeft.h"
#include "VisibleArea.h"
#include "Random.h"
//#include "ShotgunPelletShotRight.h"
#include <iostream>
using namespace std;
//#include "LPC2478.h"

ShotgunPellet::ShotgunPellet(ShotgunState* initialState, Environment* environment, uint32_t positionX, uint32_t positionY, uint32_t initializer, uint32_t ini2) : Entity(initialState, environment) {

	// Keep a pointer to the initial state in case we need to re-spawn the sprite
	//this->initialState = initialState;
	this->currentState = initialState;
	this->setPositionX(positionX);
	this->setPositionY(positionY+15);

	setBaseDamage(1);
	setCurrentDamage(1);
	setBaseSpeed(18);
	setCurrentSpeed(18);

	randomGen=new Random();

	//the following lines are used to generate a direction to the pellet
	uint32_t directionx = (randomGen->getRandom(ini2, initializer+ini2)%25)+10;
	cout <<randomGen->getRandom(ini2, initializer+ini2)<< endl;
	uint32_t directiony = randomGen->getRandom(directionx, ini2)%2;

	//cout <<directionx<<"   "<<directiony<<endl;

	if(directiony==0)
		directiony=-1;

	velocityX=directionx;
	//each pellet has the same force
	velocityY=(25-directionx)*directiony;


	// Unsafe?
	this->currentState->initialize(this);

	//Initialize every possible ShotgunPellet states
	//ShotgunPelletWalkingLeft = ShotgunPelletWalkingLeft::createInstance();
	//ShotgunPelletWalkingLeft = ShotgunPelletWalkingRight::createInstance();
}

ShotgunPellet::~ShotgunPellet() {

}

void ShotgunPellet::setState(ShotgunState* state)  {
	this->currentState = state;

	// Do state entry initialization on the sprite
	currentState->initialize(this);

	// Send state to the superclass
	Sprite::setState(state);
}

void ShotgunPellet::update() {
	//cout <<velocityX<<"   "<<velocityY<<endl;
	environment->move(this, positionX+velocityX, positionY+velocityY);

	VisibleArea* visibleArea = environment->getVisibleArea();

	collisionCheckEnabled = true;

	if(collisionCheckEnabled) {
		environment->checkCollision(this);
	}

	// Update the currently displayed frame
	// And possibly some state specific things
	currentState->update(this);

	// if the shot is outside the screen
	if(positionX <= visibleArea->x || positionX >= visibleArea->x + visibleArea->width ||
				positionY <= visibleArea->y || positionY >= visibleArea->y + visibleArea->height || this->isOnGround())
	{
		environment->deactivate(this);
		environment->getHero()->removeChild(this);
		((Megaman*)environment->getHero())->decCurrentBusterNum();
		cout << "sur le sol"<<endl;
	}
}

void ShotgunPellet::collideWith(Collider* collider) {
	collider->collideWith(this);
}

void ShotgunPellet::collideWith(Megaman*) {
	//cout << "ShotgunPellet collided with Megaman";
	//LPC2478::delay(1000000);
}

void ShotgunPellet::collideWith(Metool* metool) {
	cout << "ShotgunPellet collided with Metool"<<endl;
	//LPC2478::delay(1000000);
	environment->deactivate(this);
	environment->getHero()->removeChild(this);
	((Megaman*)environment->getHero())->decCurrentBusterNum();
}


