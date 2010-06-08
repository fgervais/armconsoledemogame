/*
 * MetoolState.h
 *
 *  Created on: May 13, 2010
 *      Author: fgervais
 */

#ifndef SCREENUISTATE_H_
#define SCREENUISTATE_H_

#include "State.h"

#include <stdint.h>

class ScreenUI;

class ScreenUIState : public State {
public:
	ScreenUIState(uint32_t animationWidth, uint32_t animationHeight, Bitmap** animationFrames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~ScreenUIState();

	virtual void update(ScreenUI*) {}
	virtual void initialize(ScreenUI*) {}

};

#endif /* SCREENUISTATE_H_ */
