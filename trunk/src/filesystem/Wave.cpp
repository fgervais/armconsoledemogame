/*
 * Wave.cpp
 *
 *  Created on: Apr 2, 2010
 *      Author: fgervais
 */

#include "Wave.h"

Wave::Wave(const string *path) {
	this->path = path;

	riffHeader = 0;
	waveHeader = 0;
	dataHeader = 0;
	data = 0;
	loaded = 0;
}

Wave::~Wave() {
	/* Free memory */
	delete riffHeader;
	delete waveHeader;
	delete dataHeader;
	delete[] data;
}

/**
 * Load the wave file to memory.
 *
 * @return 0 if successful. 1 otherwise.
 */
uint8_t Wave::load() {
	sound = Mix_LoadWAV( "path" );
	
	//If there was a problem loading the sound effects
    if( sound == NULL )
    	return 1;
    return 0; 
}

