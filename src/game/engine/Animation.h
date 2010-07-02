/*
 * Animation.h
 *
 *  Created on: May 18, 2010
 *      Author: fgervais
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <stdint.h>
#include <iostream>

class Bitmap;
class Sprite;
class SDL_Surface;

class Animation {
public:
	Animation(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~Animation();

	// Accessors
	uint32_t getAnimationWidth();
	uint32_t getAnimationHeight();

	//virtual void reset();

	virtual void update(Sprite*) { std::cout << "criss" << std::endl;}
	virtual void render(Sprite*, SDL_Surface*);
	virtual void initialize(Sprite*) {}

protected:
	// Subclass may need to update the current frame manually
	//uint32_t currentFrame;	// This was used before the Animation handling change
	uint32_t numberOfFrame;

private:
	uint32_t animationHeight;
	uint32_t animationWidth;
	Bitmap** animationFrames;
	Bitmap** animationMasks;
};

#endif /* ANIMATION_H_ */
