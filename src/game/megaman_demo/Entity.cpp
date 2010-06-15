/*
 * Entity.cpp
 *
 *  Created on: 2010-06-14
 *      Author: Basse
 */

#include "Entity.h"
#include "Environment.h"
#include "State.h"
#include <iostream>
using namespace std;
//#include "LPC2478.h"


Entity::Entity(State* initialState, Environment* environment) : Sprite(initialState, environment) {

	// States initialization
	// Keep a pointer to the initial state in case we need to re-spawn the sprite
	this->currentState = initialState;

	// Attributes Initialization
	this->currentHP = 0;
	this->maxHP = 0;
	this->currentSpeed = 0;
	this->baseSpeed = 0;
	this->currentDamage = 0;
	this->baseDamage = 0;
	this->currentArmorValue = 0;
	this->baseArmorValue = 0;

	this->walkable = 0;

	// Counters initialization
	this->stateCounter = new uint32_t[6];

	for(uint32_t i=0; i<6; i++)
	{
		stateCounter[i] = 0;
	}

	// Unsafe?
	this->currentState->initialize(this);
}

Entity::~Entity() {

}

void Entity::setState(State* state)  {

	this->currentState = state;

	// Do state entry initialization on the sprite
	state->initialize(this);

	// Reset the counter
	setCounter(state, 0);

	// Send state to the superclass
	Sprite::setState(state);
}

void Entity::addSubState(State* state) {
	// If the array isn't initialized, we initialize it
	if(this->subState == 0)
	{
		subState = new State*[5];
		for(uint32_t i=0; i<5; i++)
		{
			subState[i] = 0;
		}
	}

	for(uint32_t i=0; i<5; i++)
	{
		if(subState[i] == 0)
		{
			subState[i] = state;
			i = 5;
		}
	}
}

void Entity::removeSubState(State* state) {

	for(uint32_t i=0; i<5; i++)
	{
		if(subState[i] == state)
		{
			subState[i] = 0;
			i = 5;
		}
	}
}

void Entity::setCounter(State* state, uint32_t num) {

	if(this->currentState == state)
	{
		this->stateCounter[0] = num;
	}
	else
	{
		for(uint32_t i=0; i<5; i++)
		{
			if(subState[i] == state)
			{
				this->stateCounter[i+1] = num;
			}
		}
	}
}

uint32_t Entity::getCounter(State* state) {

	uint32_t returnValue = 0;

	if(this->currentState == state)
	{
		returnValue = stateCounter[0];
	}
	else
	{
		for(uint32_t i=0; i<5; i++)
		{
			if(subState[i] == state)
			{
				returnValue = stateCounter[i+1];
			}
		}
	}

	return returnValue;
}

void Entity::incCounter(State* state) {

	if(this->currentState == state)
	{
		stateCounter[0]++;
	}
	else
	{
		for(uint32_t i=0; i<5; i++)
		{
			if(subState[i] == state)
			{
				stateCounter[i+1]++;
			}
		}
	}
}

void Entity::decCounter(State* state) {

	if(this->currentState == state)
	{
		stateCounter[0]--;
	}
	else
	{
		for(uint32_t i=0; i<5; i++)
		{
			if(subState[i] == state)
			{
				stateCounter[i+1]--;
			}
		}
	}
}

void Entity::update() {
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


