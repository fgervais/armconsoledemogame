/*
 * MegamanStandingRight.cpp
 *
 *  Created on: May 3, 2010
 *      Author: fgervais
 */

#include "MegamanStandingRight.h"
#include "MegamanHitRight.h"
#include "Sprite.h"
#include "Megaman.h"
#include "Bitmap.h"
#include <iostream>
using namespace std;

MegamanState* MegamanHitRight::instance = 0;

MegamanHitRight::MegamanHitRight(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
	: MegamanState(animationWidth, animationHeight, animationFrames, numberOfFrame, animationMasks) {


}

MegamanHitRight::~MegamanHitRight() {

}

MegamanState* MegamanHitRight::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[11];
		animationFrames[0] = new Bitmap("src/display/state/MegamanHitRight/1.bmp");
		animationFrames[1] = new Bitmap("src/display/state/MegamanHitRight/2.bmp");
		animationFrames[2] = new Bitmap("src/display/state/MegamanHitRight/3.bmp");
		animationFrames[3] = new Bitmap("src/display/state/MegamanHitRight/4.bmp");
		animationFrames[4] = new Bitmap("src/display/state/MegamanHitRight/5.bmp");
		animationFrames[5] = new Bitmap("src/display/state/MegamanHitRight/6.bmp");
		animationFrames[6] = new Bitmap("src/display/state/MegamanHitRight/7.bmp");
		animationFrames[7] = new Bitmap("src/display/state/MegamanHitRight/8.bmp");
		animationFrames[8] = new Bitmap("src/display/state/MegamanHitRight/9.bmp");
		animationFrames[9] = new Bitmap("src/display/state/MegamanHitRight/10.bmp");
		animationFrames[10] = new Bitmap("src/display/state/MegamanHitRight/11.bmp");

		Bitmap** animationMasks = new Bitmap*[11];
		animationMasks[0] = new Bitmap("src/display/state/MegamanHitRight/mask1.bmp");
		animationMasks[1] = new Bitmap("src/display/state/MegamanHitRight/mask2.bmp");
		animationMasks[2] = new Bitmap("src/display/state/MegamanHitRight/mask3.bmp");
		animationMasks[3] = new Bitmap("src/display/state/MegamanHitRight/mask4.bmp");
		animationMasks[4] = new Bitmap("src/display/state/MegamanHitRight/mask5.bmp");
		animationMasks[5] = new Bitmap("src/display/state/MegamanHitRight/mask6.bmp");
		animationMasks[6] = new Bitmap("src/display/state/MegamanHitRight/mask7.bmp");
		animationMasks[7] = new Bitmap("src/display/state/MegamanHitRight/mask8.bmp");
		animationMasks[8] = new Bitmap("src/display/state/MegamanHitRight/mask9.bmp");
		animationMasks[9] = new Bitmap("src/display/state/MegamanHitRight/mask10.bmp");
		animationMasks[10] = new Bitmap("src/display/state/MegamanHitRight/mask11.bmp");
		instance = new MegamanHitRight(32, 48, animationFrames, 11, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */

void MegamanHitRight::update(Megaman* sprite) {
	// Update the current frame
	if(sprite->getCurrentFrame() < numberOfFrame-1) {
		sprite->incCurrentFrame();
	}
	else {
		sprite->setState(MegamanStandingRight::getInstance());
	}

}

void MegamanHitRight::initialize(Megaman* sprite) {
	sprite->setVelocity(-2, 0);
}
