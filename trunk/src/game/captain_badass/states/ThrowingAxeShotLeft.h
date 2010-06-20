/*
 * ThrowingAxeShotLeft.h
 *
 *  Created on: 2010-06-14
 *      Author: DUPA
 */

#ifndef THROWINGAXESHOTLEFT_H_
#define THROWINGAXESHOTLEFT_H_

#include "ThrowingAxeState.h"

class ThrowingAxeShotLeft: public ThrowingAxeState {
public:
	static ThrowingAxeState* getInstance();

	// Base class function override
	virtual void initialize(ThrowingAxe*);
	virtual void update(ThrowingAxe*);

private:
	ThrowingAxeShotLeft(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~ThrowingAxeShotLeft();

	static ThrowingAxeState* instance;
};

#endif /* ThrowingAxeSHOTLEFT_H_ */
