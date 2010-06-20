/*
 * MegamanRunningRightShot.h
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#ifndef MEGAMANRUNNINGRIGHTSHOT_H_
#define MEGAMANRUNNINGRIGHTSHOT_H_

#include "MegamanState.h"

class MegamanRunningRightShot: public MegamanState {
public:
	static MegamanState* getInstance();

	// Base class function override
	virtual void jump(Megaman*);
	virtual void runRight(Megaman*);
	virtual void runLeft(Megaman*);
	virtual void shot(Megaman*);
	virtual void stopRunning(Megaman*);
	virtual void initialize(Megaman*);
	virtual void update(Megaman*);

private:
	MegamanRunningRightShot(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~MegamanRunningRightShot();

	static MegamanState* instance;
};

#endif /* MEGAMANRUNNINGRIGHTSHOT_H_ */
