/*
 * System.cpp
 *
 *  Created on: 2010-06-28
 *      Author: Emile
 */

#include "System.h"
#include "Background.h"
#include "Bitmap.h"
#include "Environment.h"
#include "Wave.h"
#include "VisibleArea.h"
#include "Tile.h"
#include "Sprite.h"
#include "State.h"
#include "SDL.h"

System::System() {
}

System::~System() {
}

/************************************************
 * getLineCount - Read all the content of a file
 * Params:
 *  path - the path including the filename for the file you want to read
 * Return: the number of line on success or 0(NULL) on fail.
 *
 ************************************************/
uint32_t System::getLineCount(const char* path) {
	FILE * file = fopen(path, "rb"); // open the stream
	int32_t c = 0, b;
	while ((b = fgetc(file)) != EOF) {
		c += (b == 10) ? 1 : 0;
	}
	fclose(file);

	// if the counter c is less than zero, return 0
	if (c > 0)
		return c;
	return 0;
} // EndOF Function getLineCount

/************************************************
 * getFileContent - Read all the content of a file line by line
 * Params:
 *  path 	- the path including the filename for the file you want to read
 *  content	- reference to the content array
 *  len 	- reference to the number of line in the file
 * Return: 1 on success or 0(NULL) on fail.
 ************************************************/
uint8_t System::getFileContent(const char* path, char ** &content, uint32_t& len) {
	// local variable
	FILE *file;
	uint32_t cpt = 0;

	len = getLineCount(path); // get number of line in the file
	if (len == 0)
		return 0; // fail because file empty

	// set the array size according to the number of line in the file
	content = new char*[len];

	file = fopen(path, "rb"); // open the file

	if (file == 0) { // if opening file went wrong
		return 0; // return null on fail
	} else {
		// read all the file line by line and store the line in the content array
		while (fgets(content[cpt++] = new char[100], 100, file) != NULL);

		fclose(file); // close the file
	}
	return 1; // return true on success
} // EndOF Function getFileContent


/* Sound / Music functions
 * playSound : Used to play a sound effect
 * playMusic : Used to play music
 */

 void System::playSound(Wave * wave) {
	// Mix_PlayChannel( -1, wave->getData(), 0 );
 }

 void System::playMusic(Wave * wave) {
	// Mix_PlayChannel( -1, wave->getData(), 0 );
 }

 // End of Sound / Music functions

 /* Rendering funtions
  * These functions are used to render the background, the tiles, the sprites, etc.
  * They also receive a destination surface, it's the surface where the object will be rendered.
  */

 /**
  * Background rendering function.
  *
  * This is quite a critical function since it's the hardest thing the console
  * has to do on every cycle.
  *
  * This function has been optimized but not without some drawback.
  * First, the background must repeat every 256 pixels and has to be
  * 768 pixel wide. That means that the same image repeat 3 times.
  *
  * Furthermore, the background will be rendered only once vertically.
  *
  * @param videoMemory
  */
 void System::render(Background * background, SDL_Surface* sdl_Surface) {

	Environment* environment = background->getEnvironment();
	Bitmap* bitmap = background->getHandle();
	uint32_t width = background->getWidth();

	// this is unused
	//uint32_t height = background->getHeight();

 	VisibleArea* visibleArea = environment->getVisibleArea();

 	/*
 	 * Calculate the visible area of the background according to the speed multiplier.
 	 *
 	 * We do this because the background normally scroll slower than the layer
 	 * where the hero is.
 	 */
 	uint32_t renderX1 = visibleArea->x >> 1;
 	//uint32_t renderY1 = visibleArea->y >> 1;

 	uint32_t renderWidth = visibleArea->width;
 	uint32_t renderHeight = visibleArea->height;

 	// These are safe initial guess
 	uint32_t renderMaskX1 = renderX1 % width;

 	// Draw the image on the screen
 	uint32_t sdl_SurfaceWidth = sdl_Surface->w;
 	uint32_t* sdl_SurfacePointer = (uint32_t *)sdl_Surface->pixels;

 	uint8_t* backgroundPixels = (uint8_t*) bitmap->getData()->pixels;
 		for (uint32_t i=0; i<renderHeight; i++) {
 			for (uint32_t j=0; j<renderWidth; j++) {
 				//sdl_SurfacePointer[i*sdl_SurfaceWidth + j]
 				//				   = image[i*width + ((j+renderMaskX1) & (width-1))];

 				//uint8_t* backgroundPixel = backgroundPixels + (i * bitmap->getData()->pitch + j * 3);
 				//uint8_t* backgroundPixel = backgroundPixels + (i * bitmap->getData()->pitch + ((j+renderMaskX1) & (width-1)) * 3);
 				//uint8_t* backgroundPixel = backgroundPixels + (i * bitmap->getData()->pitch + ((j+renderMaskX1) % bitmap->getData()->pitch) * 3);
 				//uint8_t* backgroundPixel = backgroundPixels + (i * bitmap->getData()->pitch + ((j+renderMaskX1) & (256-1)) * 3);
 				uint8_t* backgroundPixel = backgroundPixels + (i * bitmap->getData()->pitch + ((j+renderMaskX1) % width) * 3);

 				sdl_SurfacePointer[i*sdl_SurfaceWidth + j]
 				                   = backgroundPixel[0] | backgroundPixel[1] << 8 | backgroundPixel[2] << 16;
 			}
 		}

 }

 void System::render(Tile* tile, SDL_Surface* sdl_Surface) {

	 Environment* environment = tile->getEnvironment();
	Bitmap** frames = tile->getFrames();
	uint32_t width = tile->getWidth();
	uint32_t height = tile->getHeight();
	uint32_t currentFrame = tile->getCurrentFrame();
	uint32_t positionX = tile->getPositionX();
	uint32_t positionY = tile->getPositionY();

 	VisibleArea* visibleArea = environment->getVisibleArea();

 	//Make a temporary rectangle to hold the offsets
 	SDL_Rect offset;
 	//Give the offsets to the rectangle
 	offset.x = positionX - visibleArea->x;
 	offset.y = positionY - visibleArea->y;
 	SDL_BlitSurface( frames[currentFrame]->getData(), NULL, sdl_Surface, &offset );

 	// Get x,y coordinates inside the visible area
 	uint32_t renderPositionX = positionX - visibleArea->x;
 	uint32_t renderPositionY = positionY - visibleArea->y;

 	/*
 	 * These are used to subtract part of the image from the
 	 * rendering process.
 	 */
 	uint32_t renderMaskX1 = 0;
 	uint32_t renderMaskY1 = 0;
 	uint32_t renderMaskX2 = width;
 	uint32_t renderMaskY2 = height;

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
 	if((positionX+width) > (visibleArea->x+visibleArea->width)) {
 		renderMaskX2 = (visibleArea->x+visibleArea->width) - positionX;
 	}
 	if((positionY+height) > (visibleArea->y+visibleArea->height)) {
 		renderMaskY2 = (visibleArea->y+visibleArea->height) - positionY;
 	}

 	// Draw the image on the screen
 	uint32_t sdl_SurfaceWidth = sdl_Surface->w;
 	/*uint32_t* sdl_SurfacePointer = sdl_Surface->getPointer();

 	// Render the part of the tile inside the render mask
 	for (uint32_t i=renderMaskY1; i<renderMaskY2; i++) {
 		for (uint32_t j=renderMaskX1; j<renderMaskX2; j++) {
 			// This is complicated to understand but I don't think we can simplify it
 			sdl_SurfacePointer[((i-renderMaskY1)+renderPositionY)*sdl_SurfaceWidth + ((j-renderMaskX1)+renderPositionX)]
 							   = frames[currentFrame]->getData()[i*width + j];
 		}
 	}*/

 }

 void System::render(State* state, Sprite* sprite, SDL_Surface* sdl_Surface) {
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
 	uint32_t renderMaskX2 = state->getAnimationWidth();
 	uint32_t renderMaskY2 = state->getAnimationHeight();


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
 	if((positionX+state->getAnimationWidth()) > (visibleArea->x+visibleArea->width)) {
 		renderMaskX2 = (visibleArea->x+visibleArea->width) - positionX;
 	}
 	if((positionY+state->getAnimationHeight()) > (visibleArea->y+visibleArea->height)) {
 		renderMaskY2 = (visibleArea->y+visibleArea->height) - positionY;
 	}

 	// Draw the image on the screen
 	uint32_t sdl_SurfaceWidth = sdl_Surface->w;
 	uint32_t* sdl_SurfacePointer = (uint32_t *)sdl_Surface->pixels;

 	uint32_t currentFrame = sprite->getCurrentFrame();

 	// Render the part of the tile inside the render mask

 	Bitmap** animationFrames = state->getAnimationFrames();
 	Bitmap** animationMasks = state->getAnimationMasks();

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
