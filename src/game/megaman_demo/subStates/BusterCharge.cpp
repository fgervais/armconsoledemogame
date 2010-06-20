/*
 * MetoolWalkingLeft.cpp
 *
 *  Created on: May 13, 2010
 *      Author: fgervais
 */

#include "BusterCharge.h"
#include "Bitmap.h"
#include "Entity.h"
#include "Environment.h"
#include "Physics.h"
#include <iostream>
using namespace std;

State* BusterCharge::instance = 0;
//Bitmap** BusterCharge::sharedFrames = 0;
//Bitmap** BusterCharge::sharedMasks = 0;

BusterCharge::BusterCharge(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: State(animationWidth, animationHeight, animationFrames, numberOfFrame, animationMasks) {

}

BusterCharge::~BusterCharge() {

}

State* BusterCharge::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[1];
		animationFrames[0] = 0;

		Bitmap** animationMasks = new Bitmap*[1];
		animationMasks[0] = 0;

		instance = new BusterCharge(0,0, animationFrames, 0, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */
void BusterCharge::initialize(Sprite* sprite) {
	// This is the hard coded running speed
	// could be (should be?) somewhere defined else?
}

void BusterCharge::update(Sprite* sprite) {
	// Update the current state

	if(((Entity*)sprite)->getCounter(this) == 24) {

	}
	else
	{
		((Entity*)sprite)->incCounter(this);
		sprite->disableCollisionCheck();
	}

}
