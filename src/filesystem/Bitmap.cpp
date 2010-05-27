/*
 * Bitmap.cpp
 *
 *  Created on: Mar 25, 2010
 *      Author: fgervais
 */

#include "Bitmap.h"
#include "Debug.h"

Bitmap::Bitmap(const char *path) {
	this->path = path;

	magic = 0;
	header = 0;
	infoHeader = 0;
	data = 0;
	loaded = 0;
}

Bitmap::~Bitmap() {
	/* Free memory */
	delete magic;
	delete header;
	delete infoHeader;
	delete data;
}

/**
 * Load the bitmap file to memory.
 *
 * @return 1 if successful. 0 otherwise.
 */
uint8_t Bitmap::load() {
	//Temporary storage for the image that's loaded
	SDL_Surface* loadedImage = 0;

	//Load the image
	loadedImage = SDL_LoadBMP( path );

	//If nothing went wrong in loading the image
	if( loadedImage != 0 )
	{
			//Create an optimized image
			data = SDL_DisplayFormat( loadedImage );

			//Free the old image
			SDL_FreeSurface( loadedImage );
			loaded = 1;

			return 0;
	}

	return 1;
}
