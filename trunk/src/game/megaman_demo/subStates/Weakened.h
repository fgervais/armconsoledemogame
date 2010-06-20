/*
 * MetoolWalkingLeft.h
 *
 *  Created on: May 13, 2010
 *      Author: fgervais
 */

#ifndef WEAKENED_H_
#define WEAKENED_H_

#include "State.h"

#include <stdint.h>

class Entity;

class Weakened: public State {
public:

	static State* getInstance();

	// Base class function override
	virtual void initialize(Sprite*);
	virtual void update(Sprite*);

private:
	Weakened(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);

	virtual ~Weakened();

	static State* instance;

};

#endif /* WEAKENED_H_ */
