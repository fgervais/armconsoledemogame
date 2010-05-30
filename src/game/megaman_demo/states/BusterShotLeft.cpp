/*
 * BusterShotLeft.cpp
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#include "BusterShotLeft.h"
#include "Bitmap.h"
#include "Buster.h"
#include "Physics.h"
#include "Environment.h"
#include <iostream>
using namespace std;

BusterState* BusterShotLeft::instance = 0;

BusterShotLeft::BusterShotLeft(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: BusterState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {


}

BusterShotLeft::~BusterShotLeft() {

}

BusterState* BusterShotLeft::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[1];
		animationFrames[0] = new Bitmap("E:/EclipseProjects/demo/src/display/state/BusterShotLeft/1.bmp");

		Bitmap** animationMasks = new Bitmap*[1];
		animationMasks[0] = new Bitmap("E:/EclipseProjects/demo/src/display/state/BusterShotLeft/mask1.bmp");

		instance = new BusterShotLeft(8, 6, animationFrames, 1, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */

void BusterShotLeft::initialize(Buster* sprite) {
	if(sprite->getVelocityX() < 0) {
		// If we are already moving left, skip the first frame
		sprite->getCurrentFrame();
	}
	else {
		// This is the hard coded Shot speed
		// could be (should be?) somewhere defined else?
		sprite->setVelocity(-10, 0);
	}
}

void BusterShotLeft::update(Buster* sprite) {
	// Update current frame
	if(sprite->getCurrentFrame() < (numberOfFrame-1)) {
		sprite->incCurrentFrame();
	}
	else {
		// The first frame is displayed only once when we transition from
		// a standing position
		sprite->setCurrentFrame(1);
	}

}
