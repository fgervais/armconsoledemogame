/*
 * MetoolState.h
 *
 *  Created on: May 13, 2010
 *      Author: fgervais
 */

#ifndef LIFEGAUGESTATE_H_
#define LIFEGAUGESTATE_H_

#include "State.h"

#include <stdint.h>

class LifeGauge;

class LifeGaugeState : public State {
public:
	LifeGaugeState(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~LifeGaugeState();

	virtual void update(LifeGauge*) {}
	virtual void initialize(LifeGauge*) {}

};

#endif /* LIFEGAUGESTATE_H_ */
