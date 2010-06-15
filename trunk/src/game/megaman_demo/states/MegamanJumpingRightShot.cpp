/*
 * MegamanRunningLeftShot.cpp
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#include "MegamanJumpingRightShot.h"
#include "MegamanJumpingRight.h"
#include "MegamanJumpingLeft.h"
#include "MegamanRunningRight.h"
#include "MegamanStandingRight.h"
#include "MegamanHitRight.h"
#include "Bitmap.h"
#include "Megaman.h"
#include "Buster.h"
#include "BusterShotRight.h"
#include "Physics.h"
#include "Environment.h"
#include <iostream>
using namespace std;

MegamanState* MegamanJumpingRightShot::instance = 0;

MegamanJumpingRightShot::MegamanJumpingRightShot(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: MegamanState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {


}

MegamanJumpingRightShot::~MegamanJumpingRightShot() {

}

MegamanState* MegamanJumpingRightShot::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[11];
		animationFrames[0] = new Bitmap("src/display/state/MegamanJumpingRightShot/1.bmp");
		animationFrames[1] = new Bitmap("src/display/state/MegamanJumpingRightShot/2.bmp");
		animationFrames[2] = new Bitmap("src/display/state/MegamanJumpingRightShot/3.bmp");
		animationFrames[3] = new Bitmap("src/display/state/MegamanJumpingRightShot/4.bmp");
		animationFrames[4] = new Bitmap("src/display/state/MegamanJumpingRightShot/5.bmp");
		animationFrames[5] = new Bitmap("src/display/state/MegamanJumpingRightShot/6.bmp");
		animationFrames[6] = new Bitmap("src/display/state/MegamanJumpingRightShot/7.bmp");

		Bitmap** animationMasks = new Bitmap*[11];
		animationMasks[0] = new Bitmap("src/display/state/MegamanJumpingRightShot/mask1.bmp");
		animationMasks[1] = new Bitmap("src/display/state/MegamanJumpingRightShot/mask2.bmp");
		animationMasks[2] = new Bitmap("src/display/state/MegamanJumpingRightShot/mask3.bmp");
		animationMasks[3] = new Bitmap("src/display/state/MegamanJumpingRightShot/mask4.bmp");
		animationMasks[4] = new Bitmap("src/display/state/MegamanJumpingRightShot/mask5.bmp");
		animationMasks[5] = new Bitmap("src/display/state/MegamanJumpingRightShot/mask6.bmp");
		animationMasks[6] = new Bitmap("src/display/state/MegamanJumpingRightShot/mask7.bmp");
		instance = new MegamanJumpingRightShot(36, 46, animationFrames, 7, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */
void MegamanJumpingRightShot::runLeft(Megaman* sprite) {

	if(sprite->getVelocityX() > 0)
	{
		sprite->setVelocityX(-sprite->getVelocityX());
		sprite->setState(MegamanJumpingLeft::getInstance());
	}
	else if(sprite->getVelocityX() == 0)
	{
		sprite->setVelocityX(-sprite->getCurrentSpeed());
		sprite->setState(MegamanJumpingLeft::getInstance());
	}
}

void MegamanJumpingRightShot::runRight(Megaman* sprite) {
	if(sprite->getVelocityX() == 0)
		sprite->setVelocityX(sprite->getCurrentSpeed());
}

void MegamanJumpingRightShot::stopRunning(Megaman* sprite) {
	sprite->setVelocityX(0);
}

void MegamanJumpingRightShot::stopJumping(Megaman* sprite) {
	// Check if the sprite is not falling but jumping.
	if(sprite->getVelocityY() < 0)
		sprite->setVelocityY(0);
}

void MegamanJumpingRightShot::hit(Megaman* sprite) {
	sprite->setState(MegamanHitRight::getInstance());
}

void MegamanJumpingRightShot::initialize(Megaman* sprite) {
	if(sprite->getVelocityY() >= 0) {
		// If we are falling, we should start rendering at frame 3
		sprite->setCurrentFrame(3);
	}
	else if(sprite->isOnGround()) {
		//Audio::playAsync(sprite->getJumpSoundFX());
	}

	//Create a new buster, gives him his spawning position and add it to the parent sprite
	Buster* buster = new Buster(BusterShotRight::getInstance(), sprite->getEnvironment(), sprite->getPositionX(), sprite->getPositionY());
	cout << "Buster created" << endl;
	sprite->addChild(buster);
	sprite->incCurrentBusterNum();
}

void MegamanJumpingRightShot::update(Megaman* sprite) {
	if(sprite->isOnGround()) {
		// We need to display the landing frames before switching state
		// but only if we are not running
		if(sprite->getCurrentFrame() < 6 && sprite->getVelocityX() == 0) {
			sprite->incCurrentFrame();
		}
		else {
				sprite->setState(MegamanStandingRight::getInstance());
		}
	}
	else {
		// Manual frame update
		// Going up
		if(sprite->getVelocityY() < 0) {
			if(sprite->getCurrentFrame() < 2) {
				sprite->incCurrentFrame();
			}
		}
		// Going down
		else {
			if(sprite->getCurrentFrame() < 4) {
				sprite->incCurrentFrame();
			}
		}
		// Update speed according to gravity
		int32_t velocityY = sprite->getVelocityY() + sprite->getEnvironment()->getPhysics()->getGravitation();
		sprite->setVelocityY(velocityY);

	}
}


void MegamanJumpingRightShot::shot(Megaman* sprite) {
	sprite->setState(MegamanJumpingRightShot::getInstance());
}
