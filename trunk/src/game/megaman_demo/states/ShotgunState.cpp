/*
 * BusterState.cpp
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#include "ShotgunState.h"
#include <iostream>

using namespace std;

ShotgunState::ShotgunState(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks)
	: State(animationWidth, animationHeight, animationFrames, numberOfFrame, animationMasks) {

}

ShotgunState::~ShotgunState() {

}
