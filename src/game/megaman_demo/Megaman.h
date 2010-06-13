/*
 * Megaman.h
 *
 *  Created on: Mar 8, 2010
 *      Author: fgervais
 */

#ifndef MEGAMAN_H_
#define MEGAMAN_H_

#include "Sprite.h"

#include <stdint.h>

class Environment;
class MegamanState;
class VideoMemory;
class Collider;
class Wave;

class Megaman : public Sprite {
public:
	Megaman(MegamanState* initialState, Environment* environment);
	virtual ~Megaman();

	void setState(MegamanState* state);

	// Base class override
	virtual void update();
	virtual void collideWith(Collider*);
	virtual void collideWith(Megaman*);
	virtual void collideWith(Metool*);

	// SoundFX Accessors
	Wave* getJumpSoundFX() { return jumpSoundFX; }
	Wave* getLandSoundFX() { return landSoundFX; }

	// Buster related variables get, decrement and increment
	uint32_t getMaxBusterNum() { return maxBusterNum; };
	uint32_t getCurrentBusterNum() { return currentBusterNum; };
	void decCurrentBusterNum() { currentBusterNum--; };
	void incCurrentBusterNum() { currentBusterNum++; };


	// Action functions
	void jump();
	void runLeft();
	void runRight();
	void stopRunning();
	void stopJumping();
	void stopSliding();
	void shot();
	void slide();
	void hit();

	// Counter functions
	uint32_t getCounter() { return counter; };
	void setCounter(uint32_t num) { counter = num; };
	void incCounter() { counter++; };

	// HP functions
	uint32_t getCurrentHP()	{ return currentHP; };
	uint32_t getMaxHP()	{ return maxHP; };
	void setCurrentHP(uint32_t num) { currentHP = num; };

private:
	// Current state
	//MegamanState* initialState;
	MegamanState* currentState;

	// SoundFX
	static Wave* jumpSoundFX;
	static Wave* landSoundFX;

	uint32_t counter;

	// Buster max and current amount on the screen
	static const uint32_t maxBusterNum = 3;
	uint32_t currentBusterNum;
	uint32_t currentHP;
	uint32_t maxHP;
};

#endif /* MEGAMAN_H_ */
