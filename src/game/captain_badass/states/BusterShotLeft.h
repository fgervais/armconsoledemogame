/*
 * BusterShotLeft.h
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#ifndef BUSTERSHOTLEFT_H_
#define BUSTERSHOTLEFT_H_

#include "BusterState.h"

class BusterShotLeft: public BusterState {
public:
	static BusterState* getInstance();

	// Base class function override
	virtual void initialize(Buster*);
	virtual void update(Buster*);

private:
	BusterShotLeft(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~BusterShotLeft();

	static BusterState* instance;
};

#endif /* BUSTERSHOTLEFT_H_ */
