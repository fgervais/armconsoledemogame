/*
 * BusterShotRight.h
 *
 *  Created on: 2010-06-15
 *      Author: DUPA
 */

#ifndef THROWINGAXESHOTRIGHT_H_
#define THROWINGAXESHOTRIGHT_H_

#include "ThrowingAxeState.h"

class ThrowingAxeShotRight: public ThrowingAxeState {
public:
	static ThrowingAxeState* getInstance();

	// Base class function override
	virtual void initialize(ThrowingAxe*);
	virtual void update(ThrowingAxe*);

private:
	ThrowingAxeShotRight(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~ThrowingAxeShotRight();

	static ThrowingAxeState* instance;
};

#endif /* BUSTERSHOTRIGHT_H_ */
