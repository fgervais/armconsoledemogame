/*
 * MegamanRunningRightShot.h
 *
 *  Created on: 2010-05-29
 *      Author: Basse
 *      Modified: Brass
 */

#ifndef MegamanStandingLeftShoot_H_
#define MegamanStandingLeftShoot_H_

#include "MegamanState.h"

class MegamanStandingLeftShoot: public MegamanState {
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
	MegamanStandingLeftShoot(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~MegamanStandingLeftShoot();

	static MegamanState* instance;
};

#endif /* MegamanStandingLeftShoot_H_ */
