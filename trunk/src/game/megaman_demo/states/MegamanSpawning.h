/*
 * MegamanSpawing.h
 *
 *      Author: Brass
 */

#ifndef MegamanSpawning_H_
#define MegamanSpawning_H_

#include "MegamanState.h"

class Megaman;

class MegamanSpawning: public MegamanState {
public:
	static MegamanState* getInstance();

	// Base class function override
	virtual void stopJumping(Megaman*);
	virtual void initialize(Megaman*);
	virtual void update(Megaman*);

private:
	MegamanSpawning(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~MegamanSpawning();

	static MegamanState* instance;
};

#endif /* MegamanSpawning_H_ */
