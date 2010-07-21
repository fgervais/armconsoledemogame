/*
 * CanisterHPIddleState.h
 *
 *  Created on: May 13, 2010
 *      Author: fgervais
 *      Edited: Brass
 */

#ifndef CanisterHPIddleState_H_
#define CanisterHPIddleState_H_

#include "CanisterHPState.h"

#include <stdint.h>

class CanisterHP;
class Sprite;

class CanisterHPIddleState: public CanisterHPState {
public:

	static CanisterHPState* getInstance();

	// Base class function override
	virtual void initialize(CanisterHP*);
	virtual void update(CanisterHP*);

private:
	CanisterHPIddleState(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);

	virtual ~CanisterHPIddleState();

	static CanisterHPState* instance;
	//static Bitmap** sharedFrames;
	//static Bitmap** sharedMasks;
};

#endif /* CanisterHPIddleState_H_ */
