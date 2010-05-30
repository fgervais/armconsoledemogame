/*
 * ClipableSprite.cpp
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#include "ClipableSprite.h"
#include <iostream>
using namespace std;

ClipableSprite::ClipableSprite(State* initialState, Environment* environment) : Sprite(initialState, environment) {

	//Init
	this->clipped = 0;
	this->offsetX = 0;
	this->offsetY = 0;
	this->clipSprite = 0;
}

ClipableSprite::~ClipableSprite() {

}

void ClipableSprite::update() {
	if(this->isClipped() == 1)
	{
		positionX = positionX + offsetX;
		positionY = positionY + offsetY;
	}
}

void ClipableSprite::clipTo(Sprite* clipSprite, uint32_t offsetX, uint32_t offsetY) {
	this->clipSprite = clipSprite;
	this->offsetX = offsetX;
	this->offsetY = offsetY;

}
