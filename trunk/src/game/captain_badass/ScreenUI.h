/*
 * GameUI.h
 *
 *  Created on: 2010-06-05
 *      Author: Basse
 */

#ifndef SCREENUI_H_
#define SCREENUI_H_

#include "Sprite.h"

#include <stdint.h>

class Environment;
class ScreenUIState;
class VideoMemory;
class Wave;

class ScreenUI : public Sprite {
public:
	ScreenUI(ScreenUIState* initialState, Environment* environment);
	virtual ~ScreenUI();

	void setState(ScreenUIState* state);

	// Base class override
	virtual void update();
	virtual void collideWith(Collider* collider) {}
	// Action functions
	void show();
	void hide();
	// Link to a unit to obtain specific value in it
	void linkTo(Sprite* sprite);

	uint32_t getOffsetX() { return offsetX; };
	uint32_t getOffsetY() { return offsetY; };
	uint8_t getIsHidden() { return isHidden; };

private:
	// Current state
	ScreenUIState* currentState;

	uint32_t offsetX;
	uint32_t offsetY;

	// Boolean, 0 if the UI is not hidden and 1 if it is
	uint8_t isHidden;

	// Linked sprite
	Sprite* linkedSprite;

};

#endif /* SCREENUI_H_ */
