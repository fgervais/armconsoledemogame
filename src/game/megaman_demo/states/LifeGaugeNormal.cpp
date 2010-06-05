/*
 * MegamanSlidingLeft.cpp
 *
 *  Created on: 2010-05-30
 *      Author: Basse
 */

#include "LifeGaugeNormal.h"
#include "Bitmap.h"
#include "LifeGauge.h"
#include "Environment.h"
#include <iostream>
using namespace std;

LifeGaugeState* LifeGaugeNormal::instance = 0;

LifeGaugeNormal::LifeGaugeNormal(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationanimationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
: LifeGaugeState(animationWidth, animationHeight, animationanimationFrames, numberOfFrame, animationMasks) {

}

LifeGaugeNormal::~LifeGaugeNormal() {

}

LifeGaugeState* LifeGaugeNormal::getInstance() {
	if(instance == 0) {
		Bitmap** animationFrames = new Bitmap*[1];
		animationFrames[0] = new Bitmap("src/display/interface/LifeGauge/1.bmp");

		Bitmap** animationMasks = new Bitmap*[1];
		animationMasks[0] = new Bitmap("src/display/interface/LifeGauge/mask1.bmp");

		Bitmap* unity = new Bitmap("src/display/interface/LifeGauge/unity.bmp");

		instance = new LifeGaugeNormal(14, 64, animationFrames, 1, animationMasks);
	}
	//instance->reset();
	return instance;
}

/* BASE CLASS FUNCTION OVERRIDE */


void LifeGaugeNormal::initialize(LifeGauge* sprite) {

}

void LifeGaugeNormal::update(LifeGauge* sprite) {

}
