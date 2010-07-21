/*
 * CanisterHPIddleState.cpp
 *
 *  Created on: May 13, 2010
 *      Author: fgervais
 *      Edited: Brass
 */

#include "CanisterHPIddleState.h"
#include "Bitmap.h"
#include "CanisterHP.h"
#include "Environment.h"
#include "Physics.h"

CanisterHPState* CanisterHPIddleState::instance = 0;
//Bitmap** CanisterHPIddleState::sharedFrames = 0;
//Bitmap** CanisterHPIddleState::sharedMasks = 0;

CanisterHPIddleState::CanisterHPIddleState(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: CanisterHPState(animationWidth, animationHeight, animationFrames, numberOfFrame, animationMasks) {

}

CanisterHPIddleState::~CanisterHPIddleState() {

}

CanisterHPState* CanisterHPIddleState::getInstance() {
	if(instance == 0) {
	//if(sharedFrames == 0) {
		Bitmap** animationFrames = new Bitmap*[5];
		//sharedFreames = new Bitmap*[4];
		animationFrames = new Bitmap*[4];
		animationFrames[0] = new Bitmap("src/display/CanisterHP/1.bmp");
		animationFrames[1] = new Bitmap("src/display/CanisterHP/2.bmp");
		animationFrames[2] = new Bitmap("src/display/CanisterHP/3.bmp");
		animationFrames[3] = new Bitmap("src/display/CanisterHP/4.bmp");
		animationFrames[4] = new Bitmap("src/display/CanisterHP/5.bmp");
		//instance = new CanisterHPWalkingLeft(22, 21, frames, 4);
	//}
	//if(sharedMasks == 0) {
		Bitmap** animationMasks = new Bitmap*[5];
		//sharedMasks = new Bitmap*[4];
		animationMasks[0] = new Bitmap("src/display/CanisterHP/mask1.bmp");
		animationMasks[1] = new Bitmap("src/display/CanisterHP/mask2.bmp");
		animationMasks[2] = new Bitmap("src/display/CanisterHP/mask3.bmp");
		animationMasks[3] = new Bitmap("src/display/CanisterHP/mask4.bmp");
		animationMasks[4] = new Bitmap("src/display/CanisterHP/mask5.bmp");

		instance = new CanisterHPIddleState(15, 13, animationFrames, 5, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */
void CanisterHPIddleState::initialize(CanisterHP* sprite) {
	// This is the hard coded running speed
	// could be (should be?) somewhere defined else?
	//sprite->setVelocity(-sprite->getCurrentSpeed(), 0);
}

void CanisterHPIddleState::update(CanisterHP* sprite) {
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
