/*
 * MegamanSlidingLeft.h
 *
 *  Created on: 2010-05-30
 *      Author: Basse
 */

#ifndef LIFEGAUGENORMAL_H_
#define LIFEGAUGENORMAL_H_

#include "LifeGaugeState.h"

class LifeGaugeNormal: public LifeGaugeState {
public:
	static LifeGaugeState* getInstance();

	// Base class function override
	//virtual void show(LifeGauge*);
	virtual void initialize(LifeGauge*);
	virtual void update(LifeGauge*);

private:
	LifeGaugeNormal(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~LifeGaugeNormal();

	static LifeGaugeState* instance;
};

#endif /* LIFEGAUGENORMAL_H_ */
