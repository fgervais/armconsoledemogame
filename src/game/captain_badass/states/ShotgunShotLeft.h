/*
 * ShotgunShotLeft.h
 *
 *  Created on: 2010-05-29
 *      Author: DUPA
 */

#ifndef SHOTGUNSHOTLEFT_H_
#define SHOTGUNSHOTLEFT_H_

#include "ShotgunState.h"

class ShotgunShotLeft: public ShotgunState {
public:
	static ShotgunState* getInstance();

	// Base class function override
	virtual void initialize(ShotgunPellet*);
	virtual void update(ShotgunPellet*);

private:
	ShotgunShotLeft(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~ShotgunShotLeft();

	static ShotgunState* instance;
};

#endif /* ShotgunSHOTLEFT_H_ */
