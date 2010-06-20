/*
 * BusterShotRight.h
 *
 *  Created on: 2010-06-15
 *      Author: DUPA
 */

#ifndef SHOTGUNSHOTRIGHT_H_
#define SHOTGUNSHOTRIGHT_H_

#include "ShotgunState.h"

class ShotgunShotRight: public ShotgunState {
public:
	static ShotgunState* getInstance();

	// Base class function override
	virtual void initialize(Shotgun*);
	virtual void update(Shotgun*);

private:
	ShotgunShotRight(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~ShotgunShotRight();

	static ShotgunState* instance;
};

#endif /* BUSTERSHOTRIGHT_H_ */
