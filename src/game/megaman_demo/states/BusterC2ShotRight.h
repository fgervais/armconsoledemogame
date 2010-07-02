/*
 * BusterShotRight.h
 *
 *  Created on: 2010-06-07
 *      Author: Emile
 */

#ifndef BUSTERC2SHOTRIGHT_H_
#define BUSTERC2SHOTRIGHT_H_

#include "BusterState.h"

class BusterC2ShotRight: public BusterState {
public:
	static BusterState* getInstance();

	// Base class function override
	virtual void initialize(Buster*);
	virtual void update(Buster*);

private:
	BusterC2ShotRight(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~BusterC2ShotRight();

	static BusterState* instance;
};

#endif /* BUSTERC2SHOTRIGHT_H_ */
