/*
 * State.cpp
 *
 *  Created on: May 18, 2010
 *      Author: fgervais
 */

#include "Animation.h"

#include "Bitmap.h"
#include "VideoMemory.h"
#include "Sprite.h"
#include "Environment.h"
#include "VisibleArea.h"
#include <iostream>
using namespace std;

Animation::Animation(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks) {
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

Animation::~Animation() {

}

uint32_t Animation::getAnimationWidth() {
	return animationWidth;
}

uint32_t Animation::getAnimationHeight() {
	return animationHeight;
}

/**
 * Reset the Animation.
 *
 * Currently only reset the frame counter to 0.
 */
//void Animation::reset() {
//	currentFrame = 0;
//}

void Animation::render(Sprite* sprite, SDL_Surface* sdl_Surface) {
	VisibleArea* visibleArea = sprite->getEnvironment()->getVisibleArea();

	uint32_t positionX = sprite->getPositionX();
	uint32_t positionY = sprite->getPositionY();

	// Get x,y coordinates inside the visible area
	uint32_t renderPositionX = positionX - visibleArea->x;
	uint32_t renderPositionY = positionY - visibleArea->y;

	/*
	 * These are used to subtract part of the image from the
	 * rendering process.
	 */
	uint32_t renderMaskX1 = 0;
	uint32_t renderMaskY1 = 0;
	uint32_t renderMaskX2 = animationWidth;
	uint32_t renderMaskY2 = animationHeight;


	/*
	 * These 4 following tests check if part of the image is outside
	 * the visible area. If so, set the render mask so it won't
	 * render the part outside the screen.
	 */
	if(positionX < visibleArea->x) {
		renderMaskX1 = visibleArea->x - positionX;
		renderPositionX = 0;
	}
	if(positionY < visibleArea->y) {
		renderMaskY1 = visibleArea->y - positionY;
		renderPositionY = 0;
	}
	if((positionX+animationWidth) > (visibleArea->x+visibleArea->width)) {
		renderMaskX2 = (visibleArea->x+visibleArea->width) - positionX;
	}
	if((positionY+animationHeight) > (visibleArea->y+visibleArea->height)) {
		renderMaskY2 = (visibleArea->y+visibleArea->height) - positionY;
	}

	// Draw the image on the screen
	uint32_t sdl_SurfaceWidth = sdl_Surface->w;
	uint32_t* sdl_SurfacePointer = (uint32_t *)sdl_Surface->pixels;

	uint32_t currentFrame = sprite->getCurrentFrame();

	// Render the part of the tile inside the render mask

	uint8_t* animationFramesPixels = (uint8_t *)animationFrames[currentFrame]->getData()->pixels;
	uint8_t* animationMasksPixels = (uint8_t *)animationMasks[currentFrame]->getData()->pixels;

	for (uint32_t i=renderMaskY1; i<renderMaskY2; i++) {
		for (uint32_t j=renderMaskX1; j<renderMaskX2; j++) {
			// This is complicated to understand but I don't think we can simplify it

			/*sdl_SurfacePointer[((i-renderMaskY1)+renderPositionY)*sdl_SurfaceWidth + ((j-renderMaskX1)+renderPositionX)]
							   &= animationFramesPixels[i*animationWidth + j];
			sdl_SurfacePointer[((i-renderMaskY1)+renderPositionY)*sdl_SurfaceWidth + ((j-renderMaskX1)+renderPositionX)]
			                   |= animationFramesPixels[i*animationWidth + j];*/

			uint8_t* maskPixel = animationMasksPixels + (i * animationMasks[currentFrame]->getData()->pitch + j * 3);
			uint8_t* animationPixel = animationFramesPixels + (i * animationFrames[currentFrame]->getData()->pitch + j * 3);

			sdl_SurfacePointer[((i-renderMaskY1)+renderPositionY)*sdl_SurfaceWidth + ((j-renderMaskX1)+renderPositionX)] &= maskPixel[0]

			| (maskPixel[1] << 8) | (maskPixel[2] << 16);

			sdl_SurfacePointer[((i-renderMaskY1)+renderPositionY)*sdl_SurfaceWidth + ((j-renderMaskX1)+renderPositionX)] |=

			animationPixel[0] | (animationPixel[1] << 8) | (animationPixel[2] << 16);

			//sdl_SurfacePointer[((i-renderMaskY1)+renderPositionY)*sdl_SurfaceWidth + ((j-renderMaskX1)+renderPositionX)] &= animationMasksPixels[(i * animationMasks[currentFrame]->getData()->pitch + j * 3) + 0] | (animationMasksPixels[(i * animationMasks[currentFrame]->getData()->pitch + j * 3) + 1] << 8) | (animationMasksPixels[(i * animationMasks[currentFrame]->getData()->pitch + j * 3) + 2] << 16);
			//sdl_SurfacePointer[((i-renderMaskY1)+renderPositionY)*sdl_SurfaceWidth + ((j-renderMaskX1)+renderPositionX)] |= animationFramesPixels[(i * animationFrames[currentFrame]->getData()->pitch + j * 3) + 0] | (animationFramesPixels[(i * animationFrames[currentFrame]->getData()->pitch + j * 3) + 1] << 8) | (animationFramesPixels[(i * animationFrames[currentFrame]->getData()->pitch + j * 3) + 2] << 16);

			/*sdl_SurfacePointer[((i-renderMaskY1)+renderPositionY)*sdl_SurfaceWidth + ((j-renderMaskX1)+renderPositionX)] = animationFramesPixels[(i * animationFrames[currentFrame]->getData()->pitch + j * 3) + 0];
			sdl_SurfacePointer[((i-renderMaskY1)+renderPositionY)*sdl_SurfaceWidth + ((j-renderMaskX1)+renderPositionX)] |= animationFramesPixels[(i * animationFrames[currentFrame]->getData()->pitch + j * 3) + 1] << 8;
			sdl_SurfacePointer[((i-renderMaskY1)+renderPositionY)*sdl_SurfaceWidth + ((j-renderMaskX1)+renderPositionX)] |= animationFramesPixels[(i * animationFrames[currentFrame]->getData()->pitch + j * 3) + 2] << 16;*/

		}

		/*sdl_SurfacePointer[((i-renderMaskY1)+renderPositionY)*sdl_SurfaceWidth + ((j-renderMaskX1)+renderPositionX)]
									   = animationFramesPixels[i*animationWidth + j];*/
	}


}
