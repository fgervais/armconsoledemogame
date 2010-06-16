/*
 * ThrowingAxeShotRight.cpp
 *
 *  Created on: 2010-06-07
 *      Author: Emile
 */

#include "ThrowingAxeShotRight.h"
#include "Bitmap.h"
#include "ThrowingAxe.h"
#include "Physics.h"
#include "Environment.h"
#include "VisibleArea.h"
#include <iostream>
using namespace std;

ThrowingAxeState* ThrowingAxeShotRight::instance = 0;

ThrowingAxeShotRight::ThrowingAxeShotRight(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: ThrowingAxeState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {


}

ThrowingAxeShotRight::~ThrowingAxeShotRight() {

}

ThrowingAxeState* ThrowingAxeShotRight::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[1];
		animationFrames[0] = new Bitmap("src/display/state/ThrowingAxeShotRight/1.bmp");

		Bitmap** animationMasks = new Bitmap*[1];
		animationMasks[0] = new Bitmap("src/display/state/ThrowingAxeShotRight/mask1.bmp");

		instance = new ThrowingAxeShotRight(17, 16, animationFrames, 1, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */

void ThrowingAxeShotRight::initialize(ThrowingAxe* sprite) {
	if(sprite->getVelocityX() < 0) {
		// If we are already moving left, skip the first frame
		sprite->getCurrentFrame();
	}
	else {
		// This is the hard coded Shot speed
		// TODO could be (should be?) somewhere defined else?
		sprite->setVelocity(sprite->getCurrentSpeed(), -18);
	}
}

void ThrowingAxeShotRight::update(ThrowingAxe* sprite) {
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
