/*
 * BusterShotRight.h
 *
 *  Created on: 2010-06-07
 *      Author: Emile
 */

#ifndef BUSTERSHOTRIGHT_H_
#define BUSTERSHOTRIGHT_H_

#include "BusterState.h"

class BusterShotRight: public BusterState {
public:
	static BusterState* getInstance();

	// Base class function override
	virtual void initialize(Buster*);
	virtual void update(Buster*);

private:
	BusterShotRight(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~BusterShotRight();

	static BusterState* instance;
};

#endif /* BUSTERSHOTRIGHT_H_ */
