/*
 * Megaman.h
 *
 *  Created on: Mar 8, 2010
 *      Author: fgervais
 */

#ifndef MEGAMAN_H_
#define MEGAMAN_H_

#include "Entity.h"

#include <stdint.h>

using namespace std;

class Environment;
class MegamanState;
class VideoMemory;
class Collider;
class Wave;

class Megaman : public Entity {
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


	uint32_t getCurrentWeapon() {return currentWeapon;}

	// Buster related variables get, decrement and increment
	uint32_t getMaxBusterNum() { return maxBusterNum; };
	uint32_t getCurrentBusterNum() { return currentBusterNum; };
	void decCurrentBusterNum() { currentBusterNum--; };
	void incCurrentBusterNum() { currentBusterNum++; };

	uint32_t getBaseJumpPower() { return baseJumpPower; };
	uint32_t getCurrentJumpPower() { return currentJumpPower; };
	void setBaseJumpPower(uint32_t baseJumpPower) { this->baseJumpPower = baseJumpPower; };
	void setCurrentJumpPower(uint32_t currentJumpPower) { this->currentJumpPower = currentJumpPower; };


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
	void changeWeapon();



private:
	// Current state
	//MegamanState* initialState;
	MegamanState* currentState;

	// SoundFX
	static Wave* jumpSoundFX;
	static Wave* landSoundFX;


	// Buster max and current amount on the screen
	static const uint32_t maxBusterNum = 3;
	uint32_t currentBusterNum;

	uint32_t baseJumpPower;
	uint32_t currentJumpPower;

	uint32_t currentWeapon;

};

#endif /* MEGAMAN_H_ */
