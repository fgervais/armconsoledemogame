/*
 * MegamanJumpingRight.cpp
 *
 *  Created on: May 7, 2010
 *      Author: fgervais
 */

#include "MegamanJumpingRight.h"
#include "MegamanStandingRight.h"
#include "MegamanJumpingLeft.h"
#include "MegamanRunningRight.h"
#include "MegamanHitRight.h"
#include "Bitmap.h"
#include "Sprite.h"
#include "Megaman.h"
#include "Physics.h"
#include "Environment.h"
#include "Wave.h"
//#include "AudioHelper.h"
//#include "LPC2478.h"
#include <iostream>
//#include "Audio.h"

MegamanState* MegamanJumpingRight::instance = 0;

MegamanJumpingRight::MegamanJumpingRight(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
	: MegamanState(animationWidth, animationHeight, animationFrames, numberOfFrame, animationMasks) {

}

MegamanJumpingRight::~MegamanJumpingRight() {

}

MegamanState* MegamanJumpingRight::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[7];
		animationFrames[0] = new Bitmap("src/display/state/MegamanJumpingRight/1.bmp");
		animationFrames[1] = new Bitmap("src/display/state/MegamanJumpingRight/2.bmp");
		animationFrames[2] = new Bitmap("src/display/state/MegamanJumpingRight/3.bmp");
		animationFrames[3] = new Bitmap("src/display/state/MegamanJumpingRight/4.bmp");
		animationFrames[4] = new Bitmap("src/display/state/MegamanJumpingRight/5.bmp");
		animationFrames[5] = new Bitmap("src/display/state/MegamanJumpingRight/6.bmp");
		animationFrames[6] = new Bitmap("src/display/state/MegamanJumpingRight/7.bmp");

		Bitmap** animationMasks = new Bitmap*[7];
		animationMasks[0] = new Bitmap("src/display/state/MegamanJumpingRight/mask1.bmp");
		animationMasks[1] = new Bitmap("src/display/state/MegamanJumpingRight/mask2.bmp");
		animationMasks[2] = new Bitmap("src/display/state/MegamanJumpingRight/mask3.bmp");
		animationMasks[3] = new Bitmap("src/display/state/MegamanJumpingRight/mask4.bmp");
		animationMasks[4] = new Bitmap("src/display/state/MegamanJumpingRight/mask5.bmp");
		animationMasks[5] = new Bitmap("src/display/state/MegamanJumpingRight/mask6.bmp");
		animationMasks[6] = new Bitmap("src/display/state/MegamanJumpingRight/mask7.bmp");


		instance = new MegamanJumpingRight(30, 46, animationFrames, 7, animationMasks);
	}
	//instance->reset();
	return instance;
}

void MegamanJumpingRight::runLeft(Megaman* sprite) {

	if(sprite->getVelocityX() > 0)
	{
		sprite->setVelocityX(-sprite->getVelocityX());
		sprite->setState(MegamanJumpingLeft::getInstance());
	}
	else if(sprite->getVelocityX() == 0)
	{
		sprite->setVelocityX(-6);
		sprite->setState(MegamanJumpingLeft::getInstance());
	}
}

void MegamanJumpingRight::runRight(Megaman* sprite) {
	if(sprite->getVelocityX() == 0)
		sprite->setVelocityX(6);
}

void MegamanJumpingRight::stopRunning(Megaman* sprite) {
	sprite->setVelocityX(0);
}

void MegamanJumpingRight::stopJumping(Megaman* sprite) {
	// Check if the sprite is not falling but jumping.
	if(sprite->getVelocityY() < 0)
		sprite->setVelocityY(0);
}

void MegamanJumpingRight::initialize(Megaman* sprite) {
	if(sprite->getVelocityY() >= 0) {
		// If we are falling, we should start rendering at frame 3
		sprite->setCurrentFrame(3);
	}
	else {
		Mix_PlayChannel( -1, sprite->getJumpSoundFX()->getData(), 0 );
		//Audio::playAsync(sprite->getJumpSoundFX());
	}
}

void MegamanJumpingRight::update(Megaman* sprite) {
	if(sprite->isOnGround()) {
		// We need to display the landing frames before switching state
		// but only if we are not running
		if(sprite->getCurrentFrame() < 6 && sprite->getVelocityX() == 0) {
			sprite->incCurrentFrame();
		}
		else {
			//if(sprite->getVelocityX() > 0) {
				//sprite->setState(MegamanRunningRight::getInstance());
			//}
			//else {
				sprite->setState(MegamanStandingRight::getInstance());

			//}
			Mix_PlayChannel( -1, sprite->getLandSoundFX()->getData(), 0 );
			//Audio::playAsync(sprite->getLandSoundFX());
		}
		//sprite->setVelocity(sprite->getVelocityX(), 0);
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
