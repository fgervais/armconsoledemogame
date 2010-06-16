/*
 * ShotgunShotRight.cpp
 *
 *  Created on: 2010-06-15
 *      Author: DUPA
 */

#include "ShotgunShotRight.h"
#include "Bitmap.h"
#include "ShotgunPellet.h"
#include "Physics.h"
#include "Environment.h"
#include "VisibleArea.h"
#include <iostream>
using namespace std;

ShotgunState* ShotgunShotRight::instance = 0;

ShotgunShotRight::ShotgunShotRight(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: ShotgunState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {


}

ShotgunShotRight::~ShotgunShotRight() {

}

ShotgunState* ShotgunShotRight::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[1];
		animationFrames[0] = new Bitmap("src/display/state/ShotgunShotRight/1.bmp");

		Bitmap** animationMasks = new Bitmap*[1];
		animationMasks[0] = new Bitmap("src/display/state/ShotgunShotRight/mask1.bmp");

		instance = new ShotgunShotRight(4, 4, animationFrames, 1, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */

void ShotgunShotRight::initialize(ShotgunPellet* sprite) {
	if(sprite->getVelocityX() < 0) {
		// If we are already moving left, skip the first frame
		sprite->getCurrentFrame();
	}
	else {
		// This is the hard coded Shot speed
		// TODO could be (should be?) somewhere defined else?
		//sprite->setVelocity(sprite->getVelocityX(), sprite->getVelocityY());
	}
}

void ShotgunShotRight::update(ShotgunPellet* sprite) {
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
