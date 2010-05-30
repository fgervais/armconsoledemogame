/*
 * BusterState.h
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#ifndef BUSTERSTATE_H_
#define BUSTERSTATE_H_

#include "State.h"

#include <stdint.h>

class Buster;

class BusterState : public State {
public:
	BusterState(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~BusterState();

	virtual void update(Buster*) {}
	virtual void initialize(Buster*) {}
};

#endif /* BUSTERSTATE_H_ */
