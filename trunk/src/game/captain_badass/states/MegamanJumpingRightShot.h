/*
 * MegamanRunningLeftShot.h
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#ifndef MEGAMANJUMPINGRIGHTSHOT_H_
#define MEGAMANJUMPINGRIGHTSHOT_H_

#include "MegamanState.h"

class MegamanJumpingRightShot: public MegamanState {
public:
	static MegamanState* getInstance();

	// Base class function override
	virtual void hit(Megaman*);
	virtual void shot(Megaman*);
	virtual void runLeft(Megaman*);
	virtual void runRight(Megaman*);
	virtual void stopRunning(Megaman*);
	virtual void stopJumping(Megaman*);
	virtual void initialize(Megaman*);
	virtual void update(Megaman*);

private:
	MegamanJumpingRightShot(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~MegamanJumpingRightShot();

	static MegamanState* instance;
};

#endif /* MEGAMANJUMPINGRIGHTSHOT_H_ */
