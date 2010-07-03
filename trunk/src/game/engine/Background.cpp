/*
 * Background.cpp
 *
 *  Created on: Mar 10, 2010
 *      Author: fgervais
 */

#include "Background.h"
#include "Environment.h"
#include "VideoMemory.h"
#include "VisibleArea.h"
#include "System.h"
#include "Bitmap.h"
//#include "LPC2478.h"
//#include "DMAChannel.h"
//#include "DMAConfiguration.h"
#include <iostream>
using namespace std;

Background::Background(Bitmap* bitmap, uint32_t width, uint32_t height, Environment* environment) {
	this->bitmap = bitmap;
	this->height = height;
	this->width = width;

	this->environment = environment;

	if(!bitmap->isLoaded()) {
		bitmap->load();
	}

	//uint32_t dmaControl = 480;		// Transfer size
	//dmaControl |= (4<<12);	// Source burst size = 32
	//dmaControl |= (4<<15);	// Destination burst size = 32
	//dmaControl |= (2<<18);	// Source width = 32 bits
	//dmaControl |= (2<<21);	// Destination width = 32 bits
	//dmaControl |= (1<<26);	// Source increment
	//dmaControl |= (1<<27);	// Destination increment

	// Create LLI for DMA transfer
	//lli = new DMACCxLLI*[height];
	//for(uint32_t i=0; i<height; i++) {
	//	lli[i] = new DMACCxLLI();
	//	lli[i]->DMACCxControl = dmaControl;
	//}

}

Background::~Background() {

}

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
void Background::render(SDL_Surface* sdl_Surface) {
	System::render(this, sdl_Surface);
}

void Background::set(Environment* environment) {
	this->environment = environment;
}

/* PRIVATE FUNCTIONS */
