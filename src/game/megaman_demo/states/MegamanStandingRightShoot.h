/*
 * MegamanRunningRightShot.h
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 *      Modified: Brass
 */

#ifndef MegamanStandingRightShoot_H_
#define MegamanStandingRightShoot_H_

#include "MegamanState.h"

class MegamanStandingRightShoot: public MegamanState {
public:
	static MegamanState* getInstance();

	// Base class function override
	virtual void jump(Megaman*);
	virtual void runRight(Megaman*);
	virtual void runLeft(Megaman*);
	virtual void shot(Megaman*);
	virtual void initialize(Megaman*);
	virtual void update(Megaman*);
	virtual void stopShooting(Megaman*);

private:
	MegamanStandingRightShoot(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~MegamanStandingRightShoot();

	static MegamanState* instance;
};

#endif /* MegamanStandingRightShoot_H_ */
