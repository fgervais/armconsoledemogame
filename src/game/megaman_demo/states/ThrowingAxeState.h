/*
 * BusterState.h
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#ifndef THROWINGAXESTATE_H_
#define THROWINGAXESTATE_H_

#include "State.h"

#include <stdint.h>

class ThrowingAxe;

class ThrowingAxeState : public State {
public:
	ThrowingAxeState(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~ThrowingAxeState();

	virtual void update(ThrowingAxe*) {}
	virtual void initialize(ThrowingAxe*) {}

};

#endif /* BUSTERSTATE_H_ */
