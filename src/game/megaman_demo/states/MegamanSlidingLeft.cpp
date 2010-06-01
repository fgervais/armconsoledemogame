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

MegamanSlidingLeft::MegamanSlidingLeft(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: MegamanState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {

}

MegamanSlidingLeft::~MegamanSlidingLeft() {

}

MegamanState* MegamanSlidingLeft::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[1];
		animationFrames[0] = new Bitmap("src/display/state/MegamanSlidingLeft/1.bmp");

		Bitmap** animationMasks = new Bitmap*[1];
		animationMasks[0] = new Bitmap("src/display/state/MegamanSlidingLeft/mask1.bmp");

		instance = new MegamanSlidingLeft(38, 26, animationFrames, 1, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */
void MegamanSlidingLeft::jump(Megaman* sprite) {
	sprite->setVelocityY(-8);
	sprite->setState(MegamanJumpingLeft::getInstance());
}

//void MegamanSlidingLeft::slide(Megaman* sprite) {
	//MegamanSlidingRight::getInstance()->setCounter(0);
	//sprite->setState(MegamanSlidingRight::getInstance());
//}

//void MegamanSlidingLeft::runLeft(Megaman* sprite) {
	//sprite->setState(MegamanRunningLeft::getInstance());
//}

void MegamanSlidingLeft::stopSliding(Megaman* sprite) {
	sprite->setState(MegamanStandingLeft::getInstance());
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
		sprite->setState(MegamanJumpingLeft::getInstance());
	}
	else if(sprite->getCounter() >= 10) {
		sprite->setState(MegamanRunningLeft::getInstance());
		//sprite->setState(MegamanStandingLeft::getInstance());
	}
	else {
		sprite->incCounter();
	}


}
