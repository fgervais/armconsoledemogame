/*
 * MegamanRunningRightShot.cpp
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#include "MegamanRunningRightShot.h"
#include "MegamanRunningRight.h"
#include "MegamanJumpingRight.h"
#include "MegamanRunningLeft.h"
#include "MegamanStandingRight.h"
#include "Bitmap.h"
#include "Megaman.h"
#include "Buster.h"
#include "BusterShotRight.h"
#include "Physics.h"
#include "Environment.h"
#include <iostream>
using namespace std;

MegamanState* MegamanRunningRightShot::instance = 0;

MegamanRunningRightShot::MegamanRunningRightShot(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: MegamanState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {


}

MegamanRunningRightShot::~MegamanRunningRightShot() {

}

MegamanState* MegamanRunningRightShot::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[11];
		animationFrames[0] = new Bitmap("src/display/state/MegamanRunningRight/1.bmp");
		animationFrames[1] = new Bitmap("src/display/state/MegamanRunningRight/2.bmp");
		animationFrames[2] = new Bitmap("src/display/state/MegamanRunningRight/3.bmp");
		animationFrames[3] = new Bitmap("src/display/state/MegamanRunningRight/4.bmp");
		animationFrames[4] = new Bitmap("src/display/state/MegamanRunningRight/5.bmp");
		animationFrames[5] = new Bitmap("src/display/state/MegamanRunningRight/6.bmp");
		animationFrames[6] = new Bitmap("src/display/state/MegamanRunningRight/7.bmp");
		animationFrames[7] = new Bitmap("src/display/state/MegamanRunningRight/8.bmp");
		animationFrames[8] = new Bitmap("src/display/state/MegamanRunningRight/9.bmp");
		animationFrames[9] = new Bitmap("src/display/state/MegamanRunningRight/10.bmp");
		animationFrames[10] = new Bitmap("src/display/state/MegamanRunningRight/11.bmp");

		Bitmap** animationMasks = new Bitmap*[11];
		animationMasks[0] = new Bitmap("src/display/state/MegamanRunningRight/mask1.bmp");
		animationMasks[1] = new Bitmap("src/display/state/MegamanRunningRight/mask2.bmp");
		animationMasks[2] = new Bitmap("src/display/state/MegamanRunningRight/mask3.bmp");
		animationMasks[3] = new Bitmap("src/display/state/MegamanRunningRight/mask4.bmp");
		animationMasks[4] = new Bitmap("src/display/state/MegamanRunningRight/mask5.bmp");
		animationMasks[5] = new Bitmap("src/display/state/MegamanRunningRight/mask6.bmp");
		animationMasks[6] = new Bitmap("src/display/state/MegamanRunningRight/mask7.bmp");
		animationMasks[7] = new Bitmap("src/display/state/MegamanRunningRight/mask8.bmp");
		animationMasks[8] = new Bitmap("src/display/state/MegamanRunningRight/mask9.bmp");
		animationMasks[9] = new Bitmap("src/display/state/MegamanRunningRight/mask10.bmp");
		animationMasks[10] = new Bitmap("src/display/state/MegamanRunningRight/mask11.bmp");
		instance = new MegamanRunningRightShot(35, 35, animationFrames, 11, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */
void MegamanRunningRightShot::jump(Megaman* sprite) {
	sprite->setVelocityY(-sprite->getCurrentJumpPower());
	sprite->setState(MegamanJumpingRight::getInstance());
}

void MegamanRunningRightShot::shot(Megaman* sprite) {
	sprite->setState(MegamanRunningRightShot::getInstance());
}

void MegamanRunningRightShot::runRight(Megaman* sprite) {
	sprite->setState(MegamanRunningRight::getInstance());
}

void MegamanRunningRightShot::runLeft(Megaman* sprite) {
	sprite->setState(MegamanRunningLeft::getInstance());
}

void MegamanRunningRightShot::stopRunning(Megaman* sprite) {
	sprite->setState(MegamanStandingRight::getInstance());
}

void MegamanRunningRightShot::initialize(Megaman* sprite) {
	if(sprite->getVelocityX() < 0) {
		// If we are already moving left, skip the first frame
		sprite->getCurrentFrame();
	}
	else {
		// This is the hard coded running speed
		// could be (should be?) somewhere defined else?
		sprite->setVelocity(sprite->getCurrentSpeed(), 0);
	}

	//Create a new buster, gives him his spawning position and add it to the parent sprite
	Buster* buster = new Buster(BusterShotRight::getInstance(), sprite->getEnvironment(), sprite->getPositionX(), sprite->getPositionY());
	cout << "Buster created" << endl;
	sprite->addChild(buster);
	sprite->incCurrentBusterNum();
}

void MegamanRunningRightShot::update(Megaman* sprite) {
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
		sprite->setState(MegamanJumpingRight::getInstance());
	}
}
