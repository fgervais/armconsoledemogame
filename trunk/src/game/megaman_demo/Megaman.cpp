/*
 * Megaman.cpp
 *
 *  Created on: Mar 8, 2010
 *      Author: fgervais
 */

#include "Megaman.h"
#include "Environment.h"
#include "MegamanState.h"
#include "Metool.h"
#include <iostream>
using namespace std;
//#include "LPC2478.h"
#include "Wave.h"

Wave* Megaman::jumpSoundFX = 0;
Wave* Megaman::landSoundFX = 0;

Megaman::Megaman(MegamanState* initialState, Environment* environment) : Entity(initialState, environment) {
	// Keep a pointer to the initial state in case we need to re-spawn the sprite
	//this->initialState = initialState;
	this->currentState = initialState;
	setCurrentHP(30);
	setMaxHP(30);
	setBaseSpeed(6);
	setCurrentSpeed(6);
	setBaseJumpPower(8);
	setCurrentJumpPower(8);

	// Initialize and load sound effects
	if(jumpSoundFX == 0) {
		jumpSoundFX = new Wave("src/game/megaman_demo/sound/jump.wav");
		jumpSoundFX->load();
	}
	if(landSoundFX == 0) {
		landSoundFX = new Wave("src/game/megaman_demo/sound/land.wav");
		landSoundFX->load();
	}

	//Initalize the buster number
	currentBusterNum = 0;

	// Unsafe?
	this->currentState->initialize(this);
}

Megaman::~Megaman() {

}

void Megaman::setState(MegamanState* state)  {
	this->currentState = state;

	// Do state entry initialization on the sprite
	state->initialize(this);

	// Send state to the superclass
	Entity::setState(state);

}

void Megaman::update() {

	environment->move(this, positionX+velocityX, positionY+velocityY);

	if(collisionCheckEnabled) {
		environment->checkCollision(this);
	}

	// Update the currently displayed frame
	// And possibly some state specific things
	currentState->update(this);

	if(this->children != 0) {
		for(uint32_t i=0; i<childLimit; i++) {
			if(children[i] != 0)
			{
				children[i]->update();
			}
		}
	}
}

void Megaman::collideWith(Collider* collider) {
	collider->collideWith(this);
}

void Megaman::collideWith(Megaman*) {
	//Debug::writeLine("Megaman collided with Megaman");
	//LPC2478::delay(1000000);
}

void Megaman::collideWith(Metool* metool) {
	//Debug::writeLine("Megaman collided with Metool");
	//LPC2478::delay(1000000);
	this->hit();

	if(this->getCurrentHP() > metool->getCurrentDamage())
		this->setCurrentHP(this->getCurrentHP()-metool->getCurrentDamage());
	else
		this->setCurrentHP(0);
}

/**
 * This function delegates the action to the current state.
 */
void Megaman::jump() {
	currentState->jump(this);
}

/**
 * This function delegates the action to the current state.
 */
void Megaman::runLeft() {
	currentState->runLeft(this);
}

/**
 * This function delegates the action to the current state.
 */
void Megaman::runRight() {
	currentState->runRight(this);
}

/**
 * This function delegates the action to the current state.
 */
void Megaman::stopRunning() {
	currentState->stopRunning(this);
}

/**
 * This function delegates the action to the current state.
 */
void Megaman::stopJumping() {
	currentState->stopJumping(this);
}

void Megaman::stopSliding() {
	currentState->stopSliding(this);
}

/**
 * This function delegates the action to the current state.
 */
void Megaman::shot() {
	if (getCurrentBusterNum() < getMaxBusterNum())
		currentState->shot(this);
}

/**
 * This function delegates the action to the current state.
 */
void Megaman::slide() {
	currentState->slide(this);
}

void Megaman::hit() {
	currentState->hit(this);
}
