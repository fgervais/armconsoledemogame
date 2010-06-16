/*
 * ThrowingAxeShotLeft.cpp
 *
 *  Created on: 2010-05-29
 *      Author: DUPA
 */

#include "ThrowingAxeShotLeft.h"
#include "Bitmap.h"
#include "ThrowingAxe.h"
#include "Physics.h"
#include "Environment.h"
#include <iostream>
using namespace std;

ThrowingAxeState* ThrowingAxeShotLeft::instance = 0;

ThrowingAxeShotLeft::ThrowingAxeShotLeft(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: ThrowingAxeState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {


}

ThrowingAxeShotLeft::~ThrowingAxeShotLeft() {

}

ThrowingAxeState* ThrowingAxeShotLeft::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[8];
		animationFrames[0] = new Bitmap("src/display/state/ThrowingAxeShotLeft/1.bmp");
		animationFrames[1] = new Bitmap("src/display/state/ThrowingAxeShotLeft/2.bmp");
		animationFrames[2] = new Bitmap("src/display/state/ThrowingAxeShotLeft/3.bmp");
		animationFrames[3] = new Bitmap("src/display/state/ThrowingAxeShotLeft/4.bmp");
		animationFrames[4] = new Bitmap("src/display/state/ThrowingAxeShotLeft/5.bmp");
		animationFrames[5] = new Bitmap("src/display/state/ThrowingAxeShotLeft/6.bmp");
		animationFrames[6] = new Bitmap("src/display/state/ThrowingAxeShotLeft/7.bmp");
		animationFrames[7] = new Bitmap("src/display/state/ThrowingAxeShotLeft/8.bmp");


		Bitmap** animationMasks = new Bitmap*[8];
		animationMasks[0] = new Bitmap("src/display/state/ThrowingAxeShotLeft/mask1.bmp");
		animationMasks[1] = new Bitmap("src/display/state/ThrowingAxeShotLeft/mask2.bmp");
		animationMasks[2] = new Bitmap("src/display/state/ThrowingAxeShotLeft/mask3.bmp");
		animationMasks[3] = new Bitmap("src/display/state/ThrowingAxeShotLeft/mask4.bmp");
		animationMasks[4] = new Bitmap("src/display/state/ThrowingAxeShotLeft/mask5.bmp");
		animationMasks[5] = new Bitmap("src/display/state/ThrowingAxeShotLeft/mask6.bmp");
		animationMasks[6] = new Bitmap("src/display/state/ThrowingAxeShotLeft/mask7.bmp");
		animationMasks[7] = new Bitmap("src/display/state/ThrowingAxeShotLeft/mask8.bmp");


		instance = new ThrowingAxeShotLeft(17, 16, animationFrames, 8, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */

void ThrowingAxeShotLeft::initialize(ThrowingAxe* sprite) {
	if(sprite->getVelocityX() < 0) {
		// If we are already moving left, skip the first frame
		sprite->getCurrentFrame();
	}
	else {
		// This is the hard coded Shot speed
		// TODO could be (should be?) somewhere defined else?
		sprite->setVelocity(-sprite->getCurrentSpeed(), -18);
	}
}

void ThrowingAxeShotLeft::update(ThrowingAxe* sprite) {
	// Update current frame
	if(sprite->getCurrentFrame() < (numberOfFrame-1)) {
		sprite->incCurrentFrame();
	}
	else {
		// The first frame is displayed only once when we transition from
		// a standing position
		sprite->setCurrentFrame(0);
	}
	//gets the axe to fall
	int32_t velocityY = sprite->getVelocityY() + sprite->getEnvironment()->getPhysics()->getGravitation();
			sprite->setVelocityY(velocityY);

}
