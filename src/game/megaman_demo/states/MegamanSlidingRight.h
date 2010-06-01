/*
 * MegamanSlidingLeft.h
 *
 *  Created on: 2010-05-30
 *      Author: Basse
 */

#ifndef MEGAMANSLIDINGRIGHT_H_
#define MEGAMANSLIDINGRIGHT_H_

#include "MegamanState.h"

class MegamanSlidingRight: public MegamanState {
public:
	static MegamanState* getInstance();

	// Base class function override
	virtual void jump(Megaman*);
	//virtual void slide(Megaman*);
	//virtual void runRight(Megaman*);
	virtual void stopSliding(Megaman*);
	//virtual void shot(Megaman*);
	virtual void initialize(Megaman*);
	virtual void update(Megaman*);

	uint32_t getCounter() { return counter; };
	void setCounter(uint32_t num) { counter = num; };
	void incCounter() { counter++; };

private:
	MegamanSlidingRight(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~MegamanSlidingRight();

	uint32_t counter;
	static MegamanState* instance;
};

#endif /* MEGAMANSLIDINGRight_H_ */
