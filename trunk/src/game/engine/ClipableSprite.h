/*
 * ClipableSprite.h
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#ifndef CLIPABLESPRITE_H_
#define CLIPABLESPRITE_H_

#include "Sprite.h"

#include <stdint.h>

class ClipableSprite : public Sprite {
public:
	ClipableSprite(State* initialState, Environment* environment);
	virtual ~ClipableSprite();

	// Base class override
	virtual void update();

	void clipTo(Sprite* clipSprite, uint32_t offsetX, uint32_t offsetY);
	uint32_t isClipped() {	return clipped;	};

private:
	Sprite* clipSprite;
	uint32_t offsetX;
	uint32_t offsetY;
	uint32_t clipped;
};

#endif /* CLIPABLESPRITE_H_ */
