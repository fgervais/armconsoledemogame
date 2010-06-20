/*
 * MetoolWalkingLeft.cpp
 *
 *  Created on: May 13, 2010
 *      Author: fgervais
 */

#include "Weakened.h"
#include "Bitmap.h"
#include "Entity.h"
#include "Environment.h"
#include "Physics.h"
#include <iostream>
using namespace std;

State* Weakened::instance = 0;
//Bitmap** Weakened::sharedFrames = 0;
//Bitmap** Weakened::sharedMasks = 0;

Weakened::Weakened(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: State(animationWidth, animationHeight, animationFrames, numberOfFrame, animationMasks) {

}

Weakened::~Weakened() {

}

State* Weakened::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[4];
		animationFrames[0] = 0;

		Bitmap** animationMasks = new Bitmap*[4];
		animationMasks[0] = 0;

		instance = new Weakened(0,0, animationFrames, 0, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */
void Weakened::initialize(Sprite* sprite) {
	// This is the hard coded running speed
	// could be (should be?) somewhere defined else?
}

void Weakened::update(Sprite* sprite) {
	// Update the current state

	if(((Entity*)sprite)->getCounter(this) >= 24) {
		((Entity*)sprite)->removeSubState(this);
		sprite->enableCollisionCheck();
	}
	else
	{
		((Entity*)sprite)->incCounter(this);
		sprite->disableCollisionCheck();
	}

}
