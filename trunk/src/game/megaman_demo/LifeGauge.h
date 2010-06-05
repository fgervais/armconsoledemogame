/*
 * LifeGauge.h
 *
 *  Created on: 2010-06-04
 *      Author: Basse
 */

#ifndef LIFEGAUGE_H_
#define LIFEGAUGE_H_

#include "ClipableSprite.h"

#include <stdint.h>

class Environment;
class LifeGaugeState;
class VideoMemory;
class Wave;

class LifeGauge : public ClipableSprite {
public:
	LifeGauge(LifeGaugeState* initialState, Environment* environment);
	virtual ~LifeGauge();

	void setState(LifeGaugeState* state);

	// Base class override
	virtual void update();
	virtual void collideWith(Collider* collider) {}
	// Action functions
	//void show();
	//void hide();

private:
	// Current state
	LifeGaugeState* currentState;

};

#endif /* LIFEGAUGE_H_ */
