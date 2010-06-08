/*
 * Sprite.cpp
 *
 *  Created on: Mar 8, 2010
 *      Author: fgervais
 */

#include "Sprite.h"
#include "Environment.h"
#include "State.h"
#include <iostream>
using namespace std;

Sprite::Sprite(State* initialState, Environment* environment) {
	this->environment = environment;
	this->state = initialState;

	// Variable init
	this->positionX = 0;
	this->positionY = 0;
	this->velocityX = 0;
	this->velocityY = 0;
	this->currentFrame = 0;
	this->childLimit = 30;

	// Unsafe?
	this->state->initialize(this);

	// Sprite collision check is disabled by default
	this->collisionCheckEnabled = 0;
}

Sprite::~Sprite() {

}

void Sprite::setVelocity(int32_t x, int32_t y) {
	velocityX = x;
	velocityY = y;
}

void Sprite::setVelocityX(int32_t x) {
	velocityX = x;
}

void Sprite::setVelocityY(int32_t y) {
	velocityY = y;
}

void Sprite::setPosition(uint32_t x, uint32_t y) {
	positionX = x;
	positionY = y;
}

void Sprite::setPositionX(uint32_t x) {
	positionX = x;
}

void Sprite::setPositionY(uint32_t y) {
	positionY = y;
}

uint32_t Sprite::getWidth() {
	return state->getAnimationWidth();
}

uint32_t Sprite::getHeight() {
	return state->getAnimationHeight();
}

void Sprite::setState(State* state)  {
	// State transition position adjustment
	if(this->state != 0) {
		positionY += this->state->getAnimationHeight() - state->getAnimationHeight();
	}

	this->state = state;

	// On state change, reset the current frame
	currentFrame = 0;

	// Do state entry initialization on the sprite
	state->initialize(this);
}

void Sprite::addChild(Sprite* sprite) {
	// If the array isn't initialized, we initialize it
	if(this->children == 0) {
		children = new Sprite*[childLimit];
		for(uint32_t i=0; i<childLimit; i++) {
			children[i] = 0;
		}
	}

	for(uint32_t i=0; i<childLimit; i++) {
		if(children[i] == 0)
		{
			children[i] = sprite;
			i = childLimit;
		}
	}

	cout << "Child added " << children[0]->getPositionX() << children[0]->getPositionY() << endl;

}

void Sprite::removeChild(Sprite* sprite) {

	for(uint32_t i=0; i<childLimit; i++) {
		if(children[i] != 0 && children[i] == sprite)
		{
			children[i] = 0;
			cout << "Child removed" << endl;
		}
	}

}

void Sprite::update() {
	environment->move(this, positionX+velocityX, positionY+velocityY);

	// Update the currently displayed frame
	// And possibly some state specific things
	state->update(this);

	//Update all the children
	if(this->children != 0) {
		for(uint32_t i=0; i<childLimit; i++) {
			if(children[i] != 0)
			{
				children[i]->update();
			}
		}
	}
}

void Sprite::render(SDL_Surface* sdl_Surface) {
	state->render(this, sdl_Surface);

	//Render all the children
	if(this->children != 0) {
		for(uint32_t i=0; i<childLimit; i++) {
			if(children[i] != 0)
				children[i]->getState()->render(children[i], sdl_Surface);
		}
	}
}

uint8_t Sprite::isOnGround() {
	return environment->isOnGround(this);
}
