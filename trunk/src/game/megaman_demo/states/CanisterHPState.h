/*
 * CanisterHPState.h
 *
 *  Created on: May 13, 2010
 *      Author: fgervais
 *      Edited: Brass
 */

#ifndef CanisterHPState_H_
#define CanisterHPState_H_

#include "State.h"

#include <stdint.h>

class CanisterHP;

class CanisterHPState : public State {
public:
	CanisterHPState(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~CanisterHPState();

	virtual void update(CanisterHP*) {}
	virtual void initialize(CanisterHP*) {}
};

#endif /* CanisterHPState_H_ */
