/*
 * MegamanSlidingLeft.cpp
 *
 *  Created on: 2010-05-30
 *      Author: Basse
 */

#include "MegamanRunningRight.h"
#include "MegamanJumpingRight.h"
#include "MegamanSlidingRight.h"
#include "MegamanSlidingLeft.h"
#include "MegamanStandingRight.h"
#include "Bitmap.h"
#include "Megaman.h"
#include "Physics.h"
#include "Environment.h"
#include <iostream>
using namespace std;

MegamanState* MegamanSlidingRight::instance = 0;

MegamanSlidingRight::MegamanSlidingRight(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks, uint32_t counter)
: MegamanState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {

	this->counter = counter;

}

MegamanSlidingRight::~MegamanSlidingRight() {

}

MegamanState* MegamanSlidingRight::getInstance(uint32_t counter) {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[1];
		animationFrames[0] = new Bitmap("src/display/state/MegamanSlidingRight/1.bmp");

		Bitmap** animationMasks = new Bitmap*[1];
		animationMasks[0] = new Bitmap("src/display/state/MegamanSlidingRight/mask1.bmp");

		instance = new MegamanSlidingRight(38, 26, animationFrames, 1, animationMasks, counter);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */
void MegamanSlidingRight::jump(Megaman* sprite) {
	sprite->setVelocityY(-8);
	setCounter(0);
	sprite->setState(MegamanJumpingRight::getInstance());
}

void MegamanSlidingRight::slide(Megaman* sprite) {
	sprite->setState(MegamanSlidingLeft::getInstance(counter));
}

void MegamanSlidingRight::runRight(Megaman* sprite) {
	setCounter(0);
	sprite->setState(MegamanRunningRight::getInstance());
}

void MegamanSlidingRight::stopSliding(Megaman* sprite) {
	setCounter(0);
	sprite->setState(MegamanRunningRight::getInstance());
}

/*void MegamanSlidingRight::shot(Megaman* sprite) {
	sprite->setState(MegamanRunningRightShot::getInstance());
}*/

void MegamanSlidingRight::initialize(Megaman* sprite) {
		sprite->setVelocity(12, 0);
}

void MegamanSlidingRight::update(Megaman* sprite) {

	// If we loose contact with the ground, then we are falling
	// In our case, falling and jumping is handled by the same state
	if(!sprite->isOnGround()) {
		setCounter(0);
		sprite->setState(MegamanJumpingRight::getInstance());
	}
	else if(getCounter() >= 10) {
		setCounter(0);
		sprite->setState(MegamanRunningRight::getInstance());
	}
	else {
		incCounter();
	}

}