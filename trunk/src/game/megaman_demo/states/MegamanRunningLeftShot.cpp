/*
 * MegamanRunningLeftShot.cpp
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#include "MegamanRunningLeftShot.h"
#include "MegamanRunningLeft.h"
#include "MegamanJumpingLeft.h"
#include "MegamanRunningRight.h"
#include "MegamanStandingLeft.h"
#include "Bitmap.h"
#include "Megaman.h"
#include "Buster.h"
#include "BusterShotLeft.h"
#include "ShotgunPellet.h"
#include "shotgunShotLeft.h"
#include "ThrowingAxe.h"
#include "ThrowingAxeShotLeft.h"
#include "Physics.h"
#include "Environment.h"
#include <iostream>
using namespace std;

MegamanState* MegamanRunningLeftShot::instance = 0;

MegamanRunningLeftShot::MegamanRunningLeftShot(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: MegamanState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {


}

MegamanRunningLeftShot::~MegamanRunningLeftShot() {

}

MegamanState* MegamanRunningLeftShot::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[11];
		animationFrames[0] = new Bitmap("src/display/state/MegamanRunningLeftShoot/0.bmp");
		animationFrames[1] = new Bitmap("src/display/state/MegamanRunningLeftShoot/1.bmp");
		animationFrames[2] = new Bitmap("src/display/state/MegamanRunningLeftShoot/2.bmp");
		animationFrames[3] = new Bitmap("src/display/state/MegamanRunningLeftShoot/3.bmp");
		animationFrames[4] = new Bitmap("src/display/state/MegamanRunningLeftShoot/4.bmp");
		animationFrames[5] = new Bitmap("src/display/state/MegamanRunningLeftShoot/5.bmp");
		animationFrames[6] = new Bitmap("src/display/state/MegamanRunningLeftShoot/6.bmp");
		animationFrames[7] = new Bitmap("src/display/state/MegamanRunningLeftShoot/7.bmp");
		animationFrames[8] = new Bitmap("src/display/state/MegamanRunningLeftShoot/8.bmp");
		animationFrames[9] = new Bitmap("src/display/state/MegamanRunningLeftShoot/9.bmp");
		animationFrames[10] = new Bitmap("src/display/state/MegamanRunningLeftShoot/10.bmp");

		Bitmap** animationMasks = new Bitmap*[11];
		animationMasks[0] = new Bitmap("src/display/state/MegamanRunningLeftShoot/mask0.bmp");
		animationMasks[1] = new Bitmap("src/display/state/MegamanRunningLeftShoot/mask1.bmp");
		animationMasks[2] = new Bitmap("src/display/state/MegamanRunningLeftShoot/mask2.bmp");
		animationMasks[3] = new Bitmap("src/display/state/MegamanRunningLeftShoot/mask3.bmp");
		animationMasks[4] = new Bitmap("src/display/state/MegamanRunningLeftShoot/mask4.bmp");
		animationMasks[5] = new Bitmap("src/display/state/MegamanRunningLeftShoot/mask5.bmp");
		animationMasks[6] = new Bitmap("src/display/state/MegamanRunningLeftShoot/mask6.bmp");
		animationMasks[7] = new Bitmap("src/display/state/MegamanRunningLeftShoot/mask7.bmp");
		animationMasks[8] = new Bitmap("src/display/state/MegamanRunningLeftShoot/mask8.bmp");
		animationMasks[9] = new Bitmap("src/display/state/MegamanRunningLeftShoot/mask9.bmp");
		animationMasks[10] = new Bitmap("src/display/state/MegamanRunningLeftShoot/mask10.bmp");
		instance = new MegamanRunningLeftShot(35, 34, animationFrames, 11, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */
void MegamanRunningLeftShot::jump(Megaman* sprite) {
	sprite->setVelocityY(-sprite->getCurrentJumpPower());
	sprite->setState(MegamanJumpingLeft::getInstance());
}

void MegamanRunningLeftShot::shot(Megaman* sprite) {
	sprite->setState(MegamanRunningLeftShot::getInstance());
}

void MegamanRunningLeftShot::runRight(Megaman* sprite) {
	sprite->setState(MegamanRunningRight::getInstance());
}

void MegamanRunningLeftShot::runLeft(Megaman* sprite) {
	sprite->setState(MegamanRunningLeft::getInstance());
}

void MegamanRunningLeftShot::stopRunning(Megaman* sprite) {
	sprite->setState(MegamanStandingLeft::getInstance());
}

void MegamanRunningLeftShot::initialize(Megaman* sprite) {
	if(sprite->getVelocityX() < 0) {
		// If we are already moving left, skip the first frame
		sprite->getCurrentFrame();
	}
	else {
		// This is the hard coded running speed
		// could be (should be?) somewhere defined else?
		sprite->setVelocity(-sprite->getCurrentSpeed(), 0);
	}

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

void MegamanRunningLeftShot::update(Megaman* sprite) {
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

	//Linger effect
	if(sprite->getCounter(this) >= 5) {
		sprite->setState(MegamanRunningLeft::getInstance());
		}
	else {
		sprite->incCounter(this);
		}

}
