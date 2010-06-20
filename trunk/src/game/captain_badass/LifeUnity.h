/*
 * Tile.h
 *
 *  Created on: Mar 8, 2010
 *      Author: fgervais
 */

#ifndef LIFEUNITY_H_
#define LIFEUNITY_H_

#include "SDL.h"
#include <stdint.h>

class Environment;
class VideoMemory;
class Bitmap;

class LifeUnity {
public:
	LifeUnity(uint32_t width, uint32_t height, Bitmap* frame, Environment* environment);
	virtual ~LifeUnity();

	void render(SDL_Surface* sdl_Surface, uint32_t positionX, uint32_t positionY);
	void update();

	void setPosition(uint32_t x, uint32_t y);
	void set(Environment* environment);

private:
	uint32_t height;
	uint32_t width;
	Bitmap* frame;
	uint32_t positionX;
	uint32_t positionY;
	Environment* environment;
};

#endif /* LIFEUNITY_H_ */
