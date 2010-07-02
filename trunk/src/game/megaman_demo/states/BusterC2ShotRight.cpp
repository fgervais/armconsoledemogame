/*
 * BusterShotRight.cpp
 *
 *  Created on: 2010-06-07
 *      Author: Emile
 */

#include "BusterC2ShotRight.h"
#include "Bitmap.h"
#include "Buster.h"
#include "Physics.h"
#include "Environment.h"
#include <iostream>
using namespace std;

BusterState* BusterC2ShotRight::instance = 0;

BusterC2ShotRight::BusterC2ShotRight(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: BusterState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {


}

BusterC2ShotRight::~BusterC2ShotRight() {

}

BusterState* BusterC2ShotRight::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[5];
		animationFrames[0] = new Bitmap("src/display/state/BusterC1ShotRight/1.bmp");
		animationFrames[1] = new Bitmap("src/display/state/BusterC1ShotRight/2.bmp");
		animationFrames[2] = new Bitmap("src/display/state/BusterC1ShotRight/3.bmp");
		animationFrames[3] = new Bitmap("src/display/state/BusterC1ShotRight/4.bmp");
		animationFrames[4] = new Bitmap("src/display/state/BusterC1ShotRight/5.bmp");

		Bitmap** animationMasks = new Bitmap*[5];
		animationMasks[0] = new Bitmap("src/display/state/BusterC1ShotRight/mask1.bmp");
		animationMasks[1] = new Bitmap("src/display/state/BusterC1ShotRight/mask2.bmp");
		animationMasks[2] = new Bitmap("src/display/state/BusterC1ShotRight/mask3.bmp");
		animationMasks[3] = new Bitmap("src/display/state/BusterC1ShotRight/mask4.bmp");
		animationMasks[4] = new Bitmap("src/display/state/BusterC1ShotRight/mask5.bmp");

		instance = new BusterC2ShotRight(40, 32, animationFrames, 5, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */

void BusterC2ShotRight::initialize(Buster* sprite) {
	if(sprite->getVelocityX() < 0) {
		// If we are already moving left, skip the first frame
		sprite->getCurrentFrame();
	}
	else {
		// This is the hard coded Shot speed
		// TODO could be (should be?) somewhere defined else?
		sprite->setVelocity(sprite->getCurrentSpeed(), 0);
	}
}

void BusterC2ShotRight::update(Buster* sprite) {
	// Update current frame
	if(sprite->getCurrentFrame() == 3) {
		sprite->setCurrentFrame(3);
	}
	else
	{
		sprite->incCurrentFrame();
	}

}
