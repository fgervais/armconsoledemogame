/*
 * BusterState.h
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#ifndef SHOTGUNSTATE_H_
#define SHOTGUNSTATE_H_

#include "State.h"

#include <stdint.h>

class ShotgunPellet;

class ShotgunState : public State {
public:
	ShotgunState(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~ShotgunState();

	virtual void update(ShotgunPellet*) {}
	virtual void initialize(ShotgunPellet*) {}

};

#endif /* BUSTERSTATE_H_ */
