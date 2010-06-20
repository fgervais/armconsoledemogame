/*
 * ShotgunShotLeft.cpp
 *
 *  Created on: 2010-05-29
 *      Author: DUPA
 */

#include "ShotgunShotLeft.h"
#include "Bitmap.h"
#include "ShotgunPellet.h"
#include "Physics.h"
#include "Environment.h"
#include <iostream>
using namespace std;

ShotgunState* ShotgunShotLeft::instance = 0;

ShotgunShotLeft::ShotgunShotLeft(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: ShotgunState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {


}

ShotgunShotLeft::~ShotgunShotLeft() {

}

ShotgunState* ShotgunShotLeft::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[1];
		animationFrames[0] = new Bitmap("src/display/state/ShotgunShotLeft/1.bmp");

		Bitmap** animationMasks = new Bitmap*[1];
		animationMasks[0] = new Bitmap("src/display/state/ShotgunShotLeft/mask1.bmp");

		instance = new ShotgunShotLeft(17, 16, animationFrames, 1, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */

void ShotgunShotLeft::initialize(ShotgunPellet* sprite) {
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

void ShotgunShotLeft::update(ShotgunPellet* sprite) {
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
