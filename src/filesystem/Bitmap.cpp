/*
 * Bitmap.cpp
 *
 *  Created on: Mar 25, 2010
 *      Author: fgervais
 */

#include "Bitmap.h"
#include <iostream>
using namespace std;

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
void Bitmap::load() {
	//Temporary storage for the image that's loaded
	SDL_Surface* loadedImage = 0;

	//Load the image
	data = SDL_LoadBMP( path );

	//If nothing went wrong in loading the image
	if( data != 0 )
	{

		cout << "Loaded file " << path << endl;
		/*
		//Create an optimized image
		data = SDL_DisplayFormat( loadedImage );

		//Free the old image
		SDL_FreeSurface( loadedImage );
		*/
		loaded = 1;
	}
	else
		cout << "Error while loading file " << path << endl ;
}
