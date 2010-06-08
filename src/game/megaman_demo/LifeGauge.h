/*
 * LifeGauge.h
 *
 *  Created on: 2010-06-04
 *      Author: Basse
 */

#ifndef LIFEGAUGE_H_
#define LIFEGAUGE_H_

#include "Sprite.h"
#include "Bitmap.h"

#include <stdint.h>

class Environment;
class LifeGaugeState;
class VideoMemory;
class Wave;

class LifeGauge : public Sprite {
public:
	LifeGauge(LifeGaugeState* initialState, Environment* environment);
	virtual ~LifeGauge();

	void setState(LifeGaugeState* state);

	// Base class override
	virtual void update();
	virtual void render(SDL_Surface*);
	virtual void collideWith(Collider* collider) {}
	void linkTo(Sprite* sprite);
	void setOffset(uint32_t offsetX, uint32_t offsetY);
	// Action functions
	//void show();
	//void hide();

private:
	// Current state
	LifeGaugeState* currentState;

	// Image of 1 unity
	Bitmap* unity;

	// Sprite with attributes needed for the UI (hero hp in this case)
	Sprite* hero;

	// Offset in the screen
	uint32_t offsetX;
	uint32_t offsetY;

};

#endif /* LIFEGAUGE_H_ */
