/*
 * State.cpp
 *
 *  Created on: May 18, 2010
 *      Author: fgervais
 */

#include "State.h"

#include "Bitmap.h"
#include "VideoMemory.h"
#include "Sprite.h"
#include "Environment.h"
#include "VisibleArea.h"
#include "System.h"
#include <iostream>
using namespace std;

State::State(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks) {
	this->animationWidth = animationWidth;
	this->animationHeight = animationHeight;
	this->animationFrames = animationFrames;
	this->numberOfFrame = numberOfFrame;
	//this->currentFrame = 0;
	this->animationMasks = animationMasks;

	// Ensure every bitmap are loaded into memory
	for(uint32_t frameNumber=0; frameNumber<numberOfFrame; frameNumber++) {
		if(!(animationFrames[frameNumber]->isLoaded())) {
			animationFrames[frameNumber]->load();
		}
	}

	for(uint32_t frameNumber=0; frameNumber<numberOfFrame; frameNumber++) {
		if(!(animationMasks[frameNumber]->isLoaded())) {
			animationMasks[frameNumber]->load();
		}
	}
}

State::~State() {

}

uint32_t State::getAnimationWidth() {
	return animationWidth;
}

uint32_t State::getAnimationHeight() {
	return animationHeight;
}

/**
 * Reset the state.
 *
 * Currently only reset the frame counter to 0.
 */
//void State::reset() {
//	currentFrame = 0;
//}

void State::render(Sprite* sprite, SDL_Surface* sdl_Surface) {
	System::render(this, sprite, sdl_Surface);
}
