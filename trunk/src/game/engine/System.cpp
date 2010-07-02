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
	return 1; // return true on succes
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
	uint32_t height = background->getHeight();

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
