/*
 * MegamanRunningLeftShot.cpp
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#include "MegamanJumpingLeftShot.h"
#include "MegamanJumpingRight.h"
#include "MegamanJumpingLeft.h"
#include "MegamanRunningRight.h"
#include "MegamanStandingLeft.h"
#include "MegamanHitLeft.h"
#include "Bitmap.h"
#include "Megaman.h"
#include "ThrowingAxe.h"
#include "ThrowingAxeShotLeft.h"
#include "ShotgunPellet.h"
#include "shotgunShotLeft.h"
#include "Buster.h"
#include "BusterShotLeft.h"
#include "BusterC2ShotRight.h"
#include "Physics.h"
#include "Environment.h"
#include <iostream>
using namespace std;

MegamanState* MegamanJumpingLeftShot::instance = 0;

MegamanJumpingLeftShot::MegamanJumpingLeftShot(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: MegamanState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {


}

MegamanJumpingLeftShot::~MegamanJumpingLeftShot() {

}

MegamanState* MegamanJumpingLeftShot::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[11];
		animationFrames[0] = new Bitmap("src/display/state/MegamanJumpingLeftShot/1.bmp");
		animationFrames[1] = new Bitmap("src/display/state/MegamanJumpingLeftShot/2.bmp");
		animationFrames[2] = new Bitmap("src/display/state/MegamanJumpingLeftShot/3.bmp");
		animationFrames[3] = new Bitmap("src/display/state/MegamanJumpingLeftShot/4.bmp");
		animationFrames[4] = new Bitmap("src/display/state/MegamanJumpingLeftShot/5.bmp");
		animationFrames[5] = new Bitmap("src/display/state/MegamanJumpingLeftShot/6.bmp");
		animationFrames[6] = new Bitmap("src/display/state/MegamanJumpingLeftShot/7.bmp");

		Bitmap** animationMasks = new Bitmap*[11];
		animationMasks[0] = new Bitmap("src/display/state/MegamanJumpingLeftShot/mask1.bmp");
		animationMasks[1] = new Bitmap("src/display/state/MegamanJumpingLeftShot/mask2.bmp");
		animationMasks[2] = new Bitmap("src/display/state/MegamanJumpingLeftShot/mask3.bmp");
		animationMasks[3] = new Bitmap("src/display/state/MegamanJumpingLeftShot/mask4.bmp");
		animationMasks[4] = new Bitmap("src/display/state/MegamanJumpingLeftShot/mask5.bmp");
		animationMasks[5] = new Bitmap("src/display/state/MegamanJumpingLeftShot/mask6.bmp");
		animationMasks[6] = new Bitmap("src/display/state/MegamanJumpingLeftShot/mask7.bmp");
		instance = new MegamanJumpingLeftShot(36, 46, animationFrames, 7, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */
void MegamanJumpingLeftShot::runLeft(Megaman* sprite) {

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

void MegamanJumpingLeftShot::runRight(Megaman* sprite) {
	if(sprite->getVelocityX() == 0)
		sprite->setVelocityX(sprite->getCurrentSpeed());
}

void MegamanJumpingLeftShot::stopRunning(Megaman* sprite) {
	sprite->setVelocityX(0);
}

void MegamanJumpingLeftShot::shot(Megaman* sprite) {
	sprite->setState(MegamanJumpingLeftShot::getInstance());
}

void MegamanJumpingLeftShot::stopJumping(Megaman* sprite) {
	// Check if the sprite is not falling but jumping.
	if(sprite->getVelocityY() < 0)
		sprite->setVelocityY(0);
}

void MegamanJumpingLeftShot::hit(Megaman* sprite) {
	sprite->setState(MegamanHitLeft::getInstance());
}

void MegamanJumpingLeftShot::initialize(Megaman* sprite) {
	if(sprite->getVelocityY() >= 0) {
		// If we are falling, we should start rendering at frame 3
		sprite->setCurrentFrame(3);
	}
	else if(sprite->isOnGround()) {
		//Audio::playAsync(sprite->getJumpSoundFX());
	}

	uint32_t currentWeapon = sprite->getCurrentWeapon();
	//Create a new bullet, depending on the equipped weapon, gives it it's spawning position and add it to the parent sprite
	switch(currentWeapon) {

		case 1 :
		{
			ThrowingAxe* buster = new ThrowingAxe(ThrowingAxeShotLeft::getInstance(), sprite->getEnvironment(), sprite->getPositionX(), sprite->getPositionY());
			buster->enableCollisionCheck();
			sprite->addChild(buster);
			sprite->incCurrentBusterNum();
			break;
		}
		case 0 :
		{
			Buster* buster = 0;

			if(sprite->getCharge() == 3)
				buster = new Buster(BusterC2ShotRight::getInstance(), sprite->getEnvironment(), sprite->getPositionX(), sprite->getPositionY());
			else if(sprite->getCharge() == 2)
				buster = new Buster(BusterShotLeft::getInstance(), sprite->getEnvironment(), sprite->getPositionX(), sprite->getPositionY());
			else
				buster = new Buster(BusterShotLeft::getInstance(), sprite->getEnvironment(), sprite->getPositionX(), sprite->getPositionY());

			buster->enableCollisionCheck();
			sprite->addChild(buster);
			sprite->incCurrentBusterNum();
			break;
		}
		case 2 :
		{
			for(uint32_t i=0; i<sprite->getPelletNum(); i++){


				ShotgunPellet* buster = new ShotgunPellet(ShotgunShotLeft::getInstance(), sprite->getEnvironment(), sprite->getPositionX(), sprite->getPositionY(), sprite->getCount(), (i+1)*1234);
				buster->enableCollisionCheck();
				sprite->addChild(buster);
				sprite->incCurrentBusterNum();

			}
		}
		}
	cout << "Buster created" << endl;


}

void MegamanJumpingLeftShot::update(Megaman* sprite) {
	if(sprite->isOnGround()) {
		// We need to display the landing frames before switching state
		// but only if we are not running
		if(sprite->getCurrentFrame() < 6 && sprite->getVelocityX() == 0) {
			sprite->incCurrentFrame();
		}
		else {
				sprite->setState(MegamanStandingLeft::getInstance());
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


