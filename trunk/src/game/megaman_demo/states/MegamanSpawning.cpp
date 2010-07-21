/*
 * MegamanSpawing.cpp
 *
 *      Author: Brass
 */

#include "MegamanSpawning.h"
#include "MegamanStandingRight.h"
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

MegamanState* MegamanSpawning::instance = 0;

MegamanSpawning::MegamanSpawning(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
	: MegamanState(animationWidth, animationHeight, animationFrames, numberOfFrame, animationMasks) {

}

MegamanSpawning::~MegamanSpawning() {

}

MegamanState* MegamanSpawning::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[7];
		animationFrames[0] = new Bitmap("src/display/state/MegamanSpawning/1.bmp");
		animationFrames[1] = new Bitmap("src/display/state/MegamanSpawning/2.bmp");
		animationFrames[2] = new Bitmap("src/display/state/MegamanSpawning/3.bmp");
		animationFrames[3] = new Bitmap("src/display/state/MegamanSpawning/4.bmp");
		animationFrames[4] = new Bitmap("src/display/state/MegamanSpawning/5.bmp");
		animationFrames[5] = new Bitmap("src/display/state/MegamanSpawning/6.bmp");
		animationFrames[6] = new Bitmap("src/display/state/MegamanSpawning/7.bmp");

		Bitmap** animationMasks = new Bitmap*[7];
		animationMasks[0] = new Bitmap("src/display/state/MegamanSpawning/mask1.bmp");
		animationMasks[1] = new Bitmap("src/display/state/MegamanSpawning/mask2.bmp");
		animationMasks[2] = new Bitmap("src/display/state/MegamanSpawning/mask3.bmp");
		animationMasks[3] = new Bitmap("src/display/state/MegamanSpawning/mask4.bmp");
		animationMasks[4] = new Bitmap("src/display/state/MegamanSpawning/mask5.bmp");
		animationMasks[5] = new Bitmap("src/display/state/MegamanSpawning/mask6.bmp");
		animationMasks[6] = new Bitmap("src/display/state/MegamanSpawning/mask7.bmp");


		instance = new MegamanSpawning(30, 48, animationFrames, 7, animationMasks);
	}
	return instance;
}

void MegamanSpawning::stopJumping(Megaman* sprite) {
	// Check if the sprite is not falling but jumping.
	if(sprite->getVelocityY() < 0)
		sprite->setVelocityY(0);
}

void MegamanSpawning::initialize(Megaman* sprite) {
		sprite->setCurrentFrame(1);
}

void MegamanSpawning::update(Megaman* sprite) {
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
			//else {*/
		sprite->setState(MegamanStandingRight::getInstance());

			//}
			//Mix_PlayChannel( -1, sprite->getLandSoundFX()->getData(), 0 );
			//Audio::playAsync(sprite->getLandSoundFX());
		}
		//sprite->setVelocity(sprite->getVelocityX(), 0);
	}
	else {
		// Update speed according to gravity
		int32_t velocityY = sprite->getVelocityY() + sprite->getEnvironment()->getPhysics()->getGravitation();
		sprite->setVelocityY(velocityY);

	}
}
