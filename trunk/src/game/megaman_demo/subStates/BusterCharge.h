/*
 * MetoolWalkingLeft.h
 *
 *  Created on: May 13, 2010
 *      Author: fgervais
 */

#ifndef BUSTERCHARGE_H_
#define BUSTERCHARGE_H_

#include "State.h"

#include <stdint.h>

class Entity;

class BusterCharge: public State {
public:

	static State* getInstance();

	// Base class function override
	virtual void initialize(Sprite*);
	virtual void update(Sprite*);

private:
	BusterCharge(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);

	virtual ~BusterCharge();

	static State* instance;


};

#endif /* BUSTERCHARGE_H_ */
