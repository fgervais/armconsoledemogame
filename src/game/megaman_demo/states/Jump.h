/*
 * Jump.h
 *
 *  Created on: 2010-06-14
 *      Author: Emile
 */

#ifndef JUMP_H_
#define JUMP_H_

#include "MegamanState.h"
#include "Entity.h"
class Wave;

class Jump: public MegamanState {
public:
	static State* getInstance();

	// Base class function override
	virtual void runLeft(Megaman*);
	virtual void runRight(Megaman*);
	virtual void stopRunning(Megaman*);
	virtual void stopJumping(Megaman*);
	virtual void hit(Megaman*);
	virtual void initialize(Megaman*);
	virtual void update(Entity*);

private:
	Jump(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~Jump();

	static State* instance;
};

#endif /* JUMP_H_ */
