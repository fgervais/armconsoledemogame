/*
 * Wave.cpp
 *
 *  Created on: Apr 2, 2010
 *      Author: fgervais
 */

#include "Wave.h"
#include <iostream>
using namespace std;

Wave::Wave(const char *path) {
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
 * @return 1 if successful. 0 otherwise.
 */
uint8_t Wave::load() {

	data = Mix_LoadWAV(path);

	if(data == 0)
	{
		cout << "Error while loading file " << path << endl;
		return 0;
	}
	else
	{
		cout << "Loaded file " << path << endl;
		loaded = 1;
	}

	return 1;

	/*FRESULT f_err_code;
	UINT byteRead;

	f_err_code = f_open(&handle, path, FA_OPEN_EXISTING | FA_READ);

	if(f_err_code == 0) {
		Debug::writeLine("WAVE File opened");
	}
	else {
		Debug::writeLine("Failed to open file");
		return 0;
	}

	riffHeader = new RIFFHeader();
	f_read(&handle, (void*)riffHeader, sizeof(RIFFHeader), &byteRead);

	waveHeader = new WAVEHeader();
	f_read(&handle, (void*)waveHeader, sizeof(WAVEHeader), &byteRead);

	// For now only 16 bits wide sample are supported
	if(waveHeader->bitPerSample != 16) {
		Debug::writeLine("Unsupported file");
		return 0;
	}

	dataHeader = new DataHeader();
	f_read(&handle, (void*)dataHeader, sizeof(DataHeader), &byteRead);

	data = new int16_t[dataHeader->size/2];
	f_read(&handle, (void*)data, dataHeader->size, &byteRead);

	f_close(&handle);
	loaded = 1;
	return 1;*/
}
