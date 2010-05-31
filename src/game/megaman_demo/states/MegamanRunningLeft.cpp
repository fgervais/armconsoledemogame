/*
 * MegamanOnGroundLeft.cpp
 *
 *  Created on: Apr 30, 2010
 *      Author: fgervais
 */

#include "MegamanRunningLeftShot.h"
#include "MegamanRunningLeft.h"
#include "MegamanJumpingLeft.h"
#include "MegamanRunningRight.h"
#include "MegamanStandingLeft.h"
#include "MegamanSlidingLeft.h"
#include "Bitmap.h"
#include "Megaman.h"
#include "Physics.h"
#include "Environment.h"
#include <iostream>
using namespace std;

MegamanState* MegamanRunningLeft::instance = 0;

MegamanRunningLeft::MegamanRunningLeft(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: MegamanState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {


}

MegamanRunningLeft::~MegamanRunningLeft() {

}

MegamanState* MegamanRunningLeft::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[11];
		animationFrames[0] = new Bitmap("src/display/state/MegamanRunningLeft/1.bmp");
		animationFrames[1] = new Bitmap("src/display/state/MegamanRunningLeft/2.bmp");
		animationFrames[2] = new Bitmap("src/display/state/MegamanRunningLeft/3.bmp");
		animationFrames[3] = new Bitmap("src/display/state/MegamanRunningLeft/4.bmp");
		animationFrames[4] = new Bitmap("src/display/state/MegamanRunningLeft/5.bmp");
		animationFrames[5] = new Bitmap("src/display/state/MegamanRunningLeft/6.bmp");
		animationFrames[6] = new Bitmap("src/display/state/MegamanRunningLeft/7.bmp");
		animationFrames[7] = new Bitmap("src/display/state/MegamanRunningLeft/8.bmp");
		animationFrames[8] = new Bitmap("src/display/state/MegamanRunningLeft/9.bmp");
		animationFrames[9] = new Bitmap("src/display/state/MegamanRunningLeft/10.bmp");
		animationFrames[10] = new Bitmap("src/display/state/MegamanRunningLeft/11.bmp");

		Bitmap** animationMasks = new Bitmap*[11];
		animationMasks[0] = new Bitmap("src/display/state/MegamanRunningLeft/mask1.bmp");
		animationMasks[1] = new Bitmap("src/display/state/MegamanRunningLeft/mask2.bmp");
		animationMasks[2] = new Bitmap("src/display/state/MegamanRunningLeft/mask3.bmp");
		animationMasks[3] = new Bitmap("src/display/state/MegamanRunningLeft/mask4.bmp");
		animationMasks[4] = new Bitmap("src/display/state/MegamanRunningLeft/mask5.bmp");
		animationMasks[5] = new Bitmap("src/display/state/MegamanRunningLeft/mask6.bmp");
		animationMasks[6] = new Bitmap("src/display/state/MegamanRunningLeft/mask7.bmp");
		animationMasks[7] = new Bitmap("src/display/state/MegamanRunningLeft/mask8.bmp");
		animationMasks[8] = new Bitmap("src/display/state/MegamanRunningLeft/mask9.bmp");
		animationMasks[9] = new Bitmap("src/display/state/MegamanRunningLeft/mask10.bmp");
		animationMasks[10] = new Bitmap("src/display/state/MegamanRunningLeft/mask11.bmp");
		instance = new MegamanRunningLeft(35, 35, animationFrames, 11, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */
void MegamanRunningLeft::jump(Megaman* sprite) {
	sprite->setVelocityY(-8);
	sprite->setState(MegamanJumpingLeft::getInstance());
}

void MegamanRunningLeft::runRight(Megaman* sprite) {
	sprite->setState(MegamanRunningRight::getInstance());
}

void MegamanRunningLeft::stopRunning(Megaman* sprite) {
	sprite->setState(MegamanStandingLeft::getInstance());
}

void MegamanRunningLeft::shot(Megaman* sprite) {
	sprite->setState(MegamanRunningLeftShot::getInstance());
}

void MegamanRunningLeft::slide(Megaman* sprite) {
	sprite->setState(MegamanSlidingLeft::getInstance(0));
}

void MegamanRunningLeft::initialize(Megaman* sprite) {
	if(sprite->getVelocityX() < 0) {
		// If we are already moving left, skip the first frame
		sprite->setCurrentFrame(1);
		sprite->setVelocity(-6, 0);
	}
	else {
		// This is the hard coded running speed
		// could be (should be?) somewhere defined else?
		sprite->setVelocity(-6, 0);
	}
}

void MegamanRunningLeft::update(Megaman* sprite) {
	// Update current frame
	if(sprite->getCurrentFrame() < (numberOfFrame-1)) {
		sprite->incCurrentFrame();
	}
	else {
		// The first frame is displayed only once when we transition from
		// a standing position
		sprite->setCurrentFrame(1);
	}

	// If we loose contact with the ground, then we are falling
	// In our case, falling and jumping is handled by the same state
	if(!sprite->isOnGround()) {
		sprite->setState(MegamanJumpingLeft::getInstance());
	}

}
