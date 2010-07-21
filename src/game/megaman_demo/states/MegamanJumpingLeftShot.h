/*
 * MegamanJumpingLeftShot.h
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 *      Edit: Brass
 */

#ifndef MEGAMANJUMPINGLEFTSHOT_H_
#define MEGAMANJUMPINGLEFTSHOT_H_

#include "MegamanState.h"

class MegamanJumpingLeftShot: public MegamanState {
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
	MegamanJumpingLeftShot(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~MegamanJumpingLeftShot();

	static MegamanState* instance;
};

#endif /* MegamanJumpingLeftShot_H_ */
