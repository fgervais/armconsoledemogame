/*
 * Jump.cpp
 *
 *  Created on: 2010-06-14
 *      Author: Emile
 */

#include "Jump.h"
#include "MegamanStandingLeft.h"
#include "MegamanRunningLeft.h"

#include "MegamanHitLeft.h"
#include "Bitmap.h"
#include "Megaman.h"
#include "Physics.h"
#include "Environment.h"
#include "Wave.h"
#include <iostream>
using namespace std;
/*#include "AudioHelper.h"
#include "Audio.h"
#include "LPC2478.h"*/

State* Jump::instance = 0;

Jump::Jump(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
	: MegamanState(animationWidth, animationHeight, animationFrames, numberOfFrame, animationMasks) {

}

Jump::~Jump() {

}

State* Jump::getInstance() {

	if(instance == 0) {

		Bitmap** animationFrames = new Bitmap*[7];
		animationFrames[0] = new Bitmap("src/display/state/MegamanJumpingLeft/1.bmp");
		animationFrames[1] = new Bitmap("src/display/state/MegamanJumpingLeft/2.bmp");
		animationFrames[2] = new Bitmap("src/display/state/MegamanJumpingLeft/3.bmp");
		animationFrames[3] = new Bitmap("src/display/state/MegamanJumpingLeft/4.bmp");
		animationFrames[4] = new Bitmap("src/display/state/MegamanJumpingLeft/5.bmp");
		animationFrames[5] = new Bitmap("src/display/state/MegamanJumpingLeft/6.bmp");
		animationFrames[6] = new Bitmap("src/display/state/MegamanJumpingLeft/7.bmp");

		Bitmap** animationMasks = new Bitmap*[7];
		animationMasks[0] = new Bitmap("src/display/state/MegamanJumpingLeft/mask1.bmp");
		animationMasks[1] = new Bitmap("src/display/state/MegamanJumpingLeft/mask2.bmp");
		animationMasks[2] = new Bitmap("src/display/state/MegamanJumpingLeft/mask3.bmp");
		animationMasks[3] = new Bitmap("src/display/state/MegamanJumpingLeft/mask4.bmp");
		animationMasks[4] = new Bitmap("src/display/state/MegamanJumpingLeft/mask5.bmp");
		animationMasks[5] = new Bitmap("src/display/state/MegamanJumpingLeft/mask6.bmp");
		animationMasks[6] = new Bitmap("src/display/state/MegamanJumpingLeft/mask7.bmp");


		instance = new Jump(30, 46, animationFrames, 7, animationMasks);
	}
	//instance->reset();
	return instance;
}

void Jump::runLeft(Megaman* sprite) {
	if(sprite->getVelocityX() == 0)
		sprite->setVelocityX(-sprite->getCurrentSpeed());
}

void Jump::runRight(Megaman* sprite) {
	// FIXME set direction to right, so the entity will be going right
	if(sprite->getVelocityX() < 0)
	{
		sprite->setVelocityX(-sprite->getVelocityX());
		sprite->setState((MegamanState*)Jump::getInstance());
	}
	else if(sprite->getVelocityX() == 0) {
		sprite->setVelocityX(sprite->getCurrentSpeed());
		sprite->setState((MegamanState*)Jump::getInstance());
	}
}

void Jump::stopRunning(Megaman* sprite) {
	sprite->setVelocityX(0);
}

void Jump::stopJumping(Megaman* sprite) {
	// Check if the sprite is not falling but jumping.
	if(sprite->getVelocityY() < 0)
		sprite->setVelocityY(0);
}

void Jump::hit(Megaman* sprite) {
	sprite->setState(MegamanHitLeft::getInstance());
}

void Jump::initialize(Megaman* sprite) {
	if(sprite->getVelocityY() >= 0) {
		// If we are falling, we should start rendering at frame 3
		sprite->setCurrentFrame(3);
	}
	else {
		Mix_PlayChannel( -1, sprite->getJumpSoundFX()->getData(), 0 );
		//Audio::playAsync(sprite->getJumpSoundFX());
	}
}

void Jump::update(Entity* sprite) {
	if(sprite->isOnGround()) {

		// We need to display the landing frames before switching state
		// but only if we are not running
		if(sprite->getCurrentFrame() < 6 && sprite->getVelocityX() == 0) {
			sprite->incCurrentFrame();
		}
		else {
			//if(sprite->getVelocityX() < 0) {
				//sprite->setState(MegamanRunningLeft::getInstance());
			//}
			//else {
				sprite->setState(MegamanStandingLeft::getInstance());
			//}

			if(Mix_PlayChannel( -1, sprite->getLandSoundFX()->getData(), 0 ) == -1)
				cout << "Error playing sound" << endl;
			//Audio::playAsync(sprite->getLandSoundFX());
		}
		//sprite->setVelocity(sprite->getVelocityX(), 0);
	}else {
		// Manual frame update
		// Going up
		if(sprite->getVelocityY() < 0) {
			if(sprite->getCurrentFrame() < 2) {
				sprite->incCurrentFrame();
			}
		}
		// Going down
		else if(sprite->getCurrentFrame() < 4) {
				sprite->incCurrentFrame();
		}
		// Update speed according to gravity
		int32_t velocityY = sprite->getVelocityY() + sprite->getEnvironment()->getPhysics()->getGravitation();
		sprite->setVelocityY(velocityY);

	}
}
