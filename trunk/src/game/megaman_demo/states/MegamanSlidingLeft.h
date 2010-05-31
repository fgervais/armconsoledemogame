/*
 * MegamanSlidingLeft.h
 *
 *  Created on: 2010-05-30
 *      Author: Basse
 */

#ifndef MEGAMANSLIDINGLEFT_H_
#define MEGAMANSLIDINGLEFT_H_

#include "MegamanState.h"

class MegamanSlidingLeft: public MegamanState {
public:
	static MegamanState* getInstance(uint32_t counter);

	// Base class function override
	virtual void jump(Megaman*);
	virtual void slide(Megaman*);
	virtual void runLeft(Megaman*);
	virtual void stopSliding(Megaman*);
	//virtual void shot(Megaman*);
	virtual void initialize(Megaman*);
	virtual void update(Megaman*);

	uint32_t getCounter() { return counter; };
	void setCounter(uint32_t num) { counter = num; };
	void incCounter() { counter++; };

private:
	MegamanSlidingLeft(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks, uint32_t counter);
	virtual ~MegamanSlidingLeft();

	uint32_t counter;
	static MegamanState* instance;
};

#endif /* MEGAMANSLIDINGLEFT_H_ */
