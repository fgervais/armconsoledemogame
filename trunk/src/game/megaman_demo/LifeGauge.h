/*
 * LifeGauge.h
 *
 *  Created on: 2010-06-04
 *      Author: Basse
 */

#ifndef LIFEGAUGE_H_
#define LIFEGAUGE_H_

#include "Megaman.h"
#include "Bitmap.h"

#include <stdint.h>

class Environment;
class LifeGaugeState;
class LifeUnity;
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
	void linkTo(Megaman* sprite);
	Megaman* getLinkedSprite() { return hero; };
	void setOffset(uint32_t offsetX, uint32_t offsetY);
	LifeUnity* getUnity(uint32_t num);
	// Action functions
	//void show();
	//void hide();

private:
	// Current state
	LifeGaugeState* currentState;

	// Image of 1 unity
	LifeUnity** unity;

	// Sprite with attributes needed for the UI (hero hp in this case)
	Megaman* hero;

	// Offset in the screen
	uint32_t offsetX;
	uint32_t offsetY;

};

#endif /* LIFEGAUGE_H_ */
