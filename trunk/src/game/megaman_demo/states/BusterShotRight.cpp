/*
 * BusterShotRight.cpp
 *
 *  Created on: 2010-06-07
 *      Author: Emile
 */

#include "BusterShotRight.h"
#include "Bitmap.h"
#include "Buster.h"
#include "Physics.h"
#include "Environment.h"
#include <iostream>
using namespace std;

BusterState* BusterShotRight::instance = 0;

BusterShotRight::BusterShotRight(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: BusterState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {


}

BusterShotRight::~BusterShotRight() {

}

BusterState* BusterShotRight::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[1];
		animationFrames[0] = new Bitmap("src/display/state/BusterShotRight/1.bmp");

		Bitmap** animationMasks = new Bitmap*[1];
		animationMasks[0] = new Bitmap("src/display/state/BusterShotRight/mask1.bmp");

		instance = new BusterShotRight(8, 6, animationFrames, 1, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */

void BusterShotRight::initialize(Buster* sprite) {
	if(sprite->getVelocityX() < 0) {
		// If we are already moving left, skip the first frame
		sprite->getCurrentFrame();
	}
	else {
		// This is the hard coded Shot speed
		// TODO could be (should be?) somewhere defined else?
		sprite->setVelocity(18, 0);
	}
}

void BusterShotRight::update(Buster* sprite) {
	// Update current frame
	if(sprite->getCurrentFrame() < (numberOfFrame-1)) {
		sprite->incCurrentFrame();
	}
	else {
		// The first frame is displayed only once when we transition from
		// a standing position
		sprite->setCurrentFrame(0);
	}

}
