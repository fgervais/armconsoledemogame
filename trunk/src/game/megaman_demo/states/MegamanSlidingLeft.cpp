/*
 * MegamanSlidingLeft.cpp
 *
 *  Created on: 2010-05-30
 *      Author: Basse
 */

#include "MegamanRunningLeft.h"
#include "MegamanJumpingLeft.h"
#include "MegamanSlidingRight.h"
#include "MegamanSlidingLeft.h"
#include "MegamanStandingLeft.h"
#include "Bitmap.h"
#include "Megaman.h"
#include "Physics.h"
#include "Environment.h"
#include <iostream>
using namespace std;

MegamanState* MegamanSlidingLeft::instance = 0;

MegamanSlidingLeft::MegamanSlidingLeft(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks, uint32_t counter)
: MegamanState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {

	this->counter = counter;

}

MegamanSlidingLeft::~MegamanSlidingLeft() {

}

MegamanState* MegamanSlidingLeft::getInstance(uint32_t counter) {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[1];
		animationFrames[0] = new Bitmap("src/display/state/MegamanSlidingLeft/1.bmp");

		Bitmap** animationMasks = new Bitmap*[1];
		animationMasks[0] = new Bitmap("src/display/state/MegamanSlidingLeft/mask1.bmp");

		instance = new MegamanSlidingLeft(38, 26, animationFrames, 1, animationMasks, counter);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */
void MegamanSlidingLeft::jump(Megaman* sprite) {
	sprite->setVelocityY(-8);
	setCounter(0);
	sprite->setState(MegamanJumpingLeft::getInstance());
}

void MegamanSlidingLeft::slide(Megaman* sprite) {
	sprite->setState(MegamanSlidingRight::getInstance(counter));
}

void MegamanSlidingLeft::runLeft(Megaman* sprite) {
	setCounter(0);
	sprite->setState(MegamanRunningLeft::getInstance());
}

void MegamanSlidingLeft::stopSliding(Megaman* sprite) {
	setCounter(0);
	sprite->setState(MegamanRunningLeft::getInstance());
}

/*void MegamanSlidingLeft::shot(Megaman* sprite) {
	sprite->setState(MegamanRunningLeftShot::getInstance());
}*/

void MegamanSlidingLeft::initialize(Megaman* sprite) {
		sprite->setVelocity(-12, 0);
}

void MegamanSlidingLeft::update(Megaman* sprite) {

	// If we loose contact with the ground, then we are falling
	// In our case, falling and jumping is handled by the same state
	if(!sprite->isOnGround()) {
		setCounter(0);
		sprite->setState(MegamanJumpingLeft::getInstance());
	}
	else if(getCounter() >= 10) {
		setCounter(0);
		sprite->setState(MegamanRunningLeft::getInstance());
	}
	else {
		incCounter();
	}


}
