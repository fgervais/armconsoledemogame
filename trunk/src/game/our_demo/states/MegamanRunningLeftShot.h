/*
 * MegamanRunningLeftShot.h
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 */

#ifndef MEGAMANRUNNINGLEFTSHOT_H_
#define MEGAMANRUNNINGLEFTSHOT_H_

#include "MegamanState.h"

class MegamanRunningLeftShot: public MegamanState {
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
	MegamanRunningLeftShot(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~MegamanRunningLeftShot();

	static MegamanState* instance;
};

#endif /* MEGAMANRUNNINGLEFTSHOT_H_ */
