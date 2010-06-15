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
#include "MegamanHitRight.h"
#include "Bitmap.h"
#include "Megaman.h"
#include "Physics.h"
#include "Environment.h"
#include <iostream>
using namespace std;

MegamanState* MegamanSlidingRight::instance = 0;

MegamanSlidingRight::MegamanSlidingRight(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: MegamanState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {

}

MegamanSlidingRight::~MegamanSlidingRight() {

}

MegamanState* MegamanSlidingRight::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[1];
		animationFrames[0] = new Bitmap("src/display/state/MegamanSlidingRight/1.bmp");

		Bitmap** animationMasks = new Bitmap*[1];
		animationMasks[0] = new Bitmap("src/display/state/MegamanSlidingRight/mask1.bmp");

		instance = new MegamanSlidingRight(38, 26, animationFrames, 1, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */
void MegamanSlidingRight::jump(Megaman* sprite) {
	sprite->setVelocityY(-sprite->getCurrentJumpPower());
	sprite->setState(MegamanJumpingRight::getInstance());
}

//void MegamanSlidingRight::slide(Megaman* sprite) {
	//sprite->setState(MegamanSlidingLeft::getInstance());
//}

//void MegamanSlidingRight::runRight(Megaman* sprite) {
	//sprite->setState(MegamanRunningRight::getInstance());
//}

void MegamanSlidingRight::stopSliding(Megaman* sprite) {
	sprite->setState(MegamanStandingRight::getInstance());
}

void MegamanSlidingRight::hit(Megaman* sprite) {
	sprite->setState(MegamanHitRight::getInstance());
}

/*void MegamanSlidingRight::shot(Megaman* sprite) {
	sprite->setState(MegamanRunningRightShot::getInstance());
}*/

void MegamanSlidingRight::initialize(Megaman* sprite) {
		sprite->setVelocity(sprite->getCurrentSpeed()*2, 0);
}

void MegamanSlidingRight::update(Megaman* sprite) {

	// If we loose contact with the ground, then we are falling
	// In our case, falling and jumping is handled by the same state
	if(!sprite->isOnGround()) {
		sprite->setState(MegamanJumpingRight::getInstance());
	}
	else if(sprite->getCounter(this) >= 10) {
		//sprite->setState(MegamanRunningRight::getInstance());
		sprite->setState(MegamanStandingRight::getInstance());
	}
	else {
		sprite->incCounter(this);
	}

}
