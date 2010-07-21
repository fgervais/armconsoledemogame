/*
 * MegamanRunningRightShot.cpp
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 *      Modified: Brass
 */

#include "MegamanStandingLeftShoot.h"
#include "MegamanRunningLeftShot.h"
#include "MegamanRunningRight.h"
#include "MegamanJumpingLeft.h"
#include "MegamanRunningLeft.h"
#include "MegamanStandingLeft.h"
#include "Bitmap.h"
#include "Megaman.h"
#include "Buster.h"
#include "ShotgunPellet.h"
#include "shotgunShotLeft.h"
#include "BusterShotLeft.h"
#include "ThrowingAxe.h"
#include "ThrowingAxeShotLeft.h"
#include "Physics.h"
#include "Environment.h"
#include <iostream>
using namespace std;

MegamanState* MegamanStandingLeftShoot::instance = 0;

MegamanStandingLeftShoot::MegamanStandingLeftShoot(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: MegamanState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {


}

MegamanStandingLeftShoot::~MegamanStandingLeftShoot() {

}

MegamanState* MegamanStandingLeftShoot::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[2];
		animationFrames[0] = new Bitmap("src/display/state/MegamanShootLeft/0.bmp");
		animationFrames[1] = new Bitmap("src/display/state/MegamanShootLeft/1.bmp");

		Bitmap** animationMasks = new Bitmap*[2];
		animationMasks[0] = new Bitmap("src/display/state/MegamanShootLeft/mask0.bmp");
		animationMasks[1] = new Bitmap("src/display/state/MegamanShootLeft/mask1.bmp");
		instance = new MegamanStandingLeftShoot(28, 34, animationFrames, 2, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */
void MegamanStandingLeftShoot::jump(Megaman* sprite) {
	sprite->setVelocityY(-sprite->getCurrentJumpPower());
	sprite->setState(MegamanJumpingLeft::getInstance());
}

void MegamanStandingLeftShoot::shot(Megaman* sprite) {
	sprite->setState(MegamanStandingLeftShoot::getInstance());
}

void MegamanStandingLeftShoot::runRight(Megaman* sprite) {
	sprite->setState(MegamanRunningRight::getInstance());
}

void MegamanStandingLeftShoot::runLeft(Megaman* sprite) {
	sprite->setState(MegamanRunningLeft::getInstance());
}

void MegamanStandingLeftShoot::initialize(Megaman* sprite) {

	uint32_t currentWeapon = sprite->getCurrentWeapon();
	//Create a new buster, gives him his spawning position and add it to the parent sprite

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
			Buster* buster = new Buster(BusterShotLeft::getInstance(), sprite->getEnvironment(), sprite->getPositionX(), sprite->getPositionY());
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

void MegamanStandingLeftShoot::update(Megaman* sprite) {
	// Update current frame
	if(sprite->getCurrentFrame() < (numberOfFrame-1)) {
		sprite->incCurrentFrame();
	}


	else {
		// The first frame is displayed only once when we transition from
		// a standing position
		sprite->setCurrentFrame(1);
	}

	// If we loose contact with the ground, then we are falling
	// In our case, falling and jumping is handled by the same state
	if(!sprite->isOnGround()) {
		sprite->setState(MegamanJumpingLeft::getInstance());
	}


}
