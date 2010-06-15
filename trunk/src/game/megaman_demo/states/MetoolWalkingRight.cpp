/*
 * MetoolWalkingRight.cpp
 *
 *  Created on: May 13, 2010
 *      Author: fgervais
 */

#include "MetoolWalkingRight.h"
#include "Bitmap.h"
#include "Metool.h"
#include "Environment.h"
#include "Physics.h"

MetoolState* MetoolWalkingRight::instance = 0;
//Bitmap** MetoolWalkingRight::sharedFrames = 0;
//Bitmap** MetoolWalkingRight::sharedMasks = 0;

MetoolWalkingRight::MetoolWalkingRight(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: MetoolState(animationWidth, animationHeight, animationFrames, numberOfFrame, animationMasks) {

}

MetoolWalkingRight::~MetoolWalkingRight() {

}

MetoolState* MetoolWalkingRight::getInstance() {
	if(instance == 0) {
		//if(sharedFrames == 0) {
			Bitmap** animationFrames = new Bitmap*[4];
			//sharedFreames = new Bitmap*[4];
			animationFrames = new Bitmap*[4];
			animationFrames[0] = new Bitmap("src/display/state/MetoolWalkingRight/1.bmp");
			animationFrames[1] = new Bitmap("src/display/state/MetoolWalkingRight/2.bmp");
			animationFrames[2] = new Bitmap("src/display/state/MetoolWalkingRight/3.bmp");
			animationFrames[3] = new Bitmap("src/display/state/MetoolWalkingRight/4.bmp");
			//instance = new MetoolWalkingRight(22, 21, frames, 4);
		//}
		//if(sharedMasks == 0) {
			Bitmap** animationMasks = new Bitmap*[4];
			//sharedMasks = new Bitmap*[4];
			animationMasks[0] = new Bitmap("src/display/state/MetoolWalkingRight/mask1.bmp");
			animationMasks[1] = new Bitmap("src/display/state/MetoolWalkingRight/mask2.bmp");
			animationMasks[2] = new Bitmap("src/display/state/MetoolWalkingRight/mask3.bmp");
			animationMasks[3] = new Bitmap("src/display/state/MetoolWalkingRight/mask4.bmp");

			instance = new MetoolWalkingRight(22, 21, animationFrames, 4, animationMasks);
		}

		//instance->reset();
		return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */
void MetoolWalkingRight::initialize(Metool* sprite) {
	// This is the hard coded running speed
	// could be (should be?) somewhere defined else?
	sprite->setVelocity(sprite->getCurrentSpeed(), 0);
}

void MetoolWalkingRight::update(Metool* sprite) {
	// Update the current frame
	if(sprite->getCurrentFrame() < (numberOfFrame-1)) {
		sprite->incCurrentFrame();
	}
	else {
		sprite->setCurrentFrame(0);
	}

	// If we loose contact with the ground, then we are falling
	if(!sprite->isOnGround()) {
		// Update speed according to gravity
		int32_t velocityY = sprite->getVelocityY() + sprite->getEnvironment()->getPhysics()->getGravitation();
		sprite->setVelocityY(velocityY);
	}
	else {
		sprite->setVelocityY(0);
	}

}
