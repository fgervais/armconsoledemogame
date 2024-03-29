/*
 * MegamanStandingLeft.cpp
 *
 *  Created on: May 3, 2010
 *      Author: fgervais
 */

#include "MegamanStandingLeft.h"
#include "MegamanStandingLeftShoot.h"
#include "MegamanJumpingLeft.h"
#include "MegamanRunningRight.h"
#include "MegamanRunningLeft.h"
#include "MegamanSlidingLeft.h"
#include "MegamanHitLeft.h"
#include "Bitmap.h"
#include "Megaman.h"

MegamanState* MegamanStandingLeft::instance = 0;

MegamanStandingLeft::MegamanStandingLeft(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: MegamanState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {


}

MegamanStandingLeft::~MegamanStandingLeft() {

}

MegamanState* MegamanStandingLeft::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[1];
		animationFrames[0] = new Bitmap("src/display/state/MegamanStandingLeft/1.bmp");

		Bitmap** animationMasks = new Bitmap*[1];
		animationMasks[0] = new Bitmap("src/display/state/MegamanStandingLeft/mask1.bmp");
		instance = new MegamanStandingLeft(35, 35, animationFrames, 1, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */
void MegamanStandingLeft::jump(Megaman* sprite) {
	sprite->setVelocityY(-sprite->getCurrentJumpPower());
	sprite->setState(MegamanJumpingLeft::getInstance());
}

void MegamanStandingLeft::slide(Megaman* sprite) {
	sprite->setState(MegamanSlidingLeft::getInstance());
}

void MegamanStandingLeft::hit(Megaman* sprite) {
	sprite->setState(MegamanHitLeft::getInstance());
}

void MegamanStandingLeft::shot(Megaman* sprite){
	sprite->setState(MegamanStandingLeftShoot::getInstance());
}

void MegamanStandingLeft::runLeft(Megaman* sprite) {
	sprite->setState(MegamanRunningLeft::getInstance());
}

void MegamanStandingLeft::runRight(Megaman* sprite) {
	sprite->setState(MegamanRunningRight::getInstance());
}

void MegamanStandingLeft::update(Megaman* sprite) {
	// This should happen only if the Megaman spawn in the air
	if(!sprite->isOnGround()) {
		sprite->setState(MegamanJumpingLeft::getInstance());
	}
}

void MegamanStandingLeft::initialize(Megaman* sprite) {
	sprite->setVelocity(0, 0);
}
