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
	virtual void collideWith(CanisterHP*);


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

	uint32_t getCount() {return count; }
	uint32_t getPelletNum() {return pelletNum; }


	// Action functions
	void jump();
	void charge();
	void runLeft();
	void runRight();
	void stopRunning();
	void stopJumping();
	void stopSliding();
	void shot();
	void slide();
	void hit();
	void changeWeapon();

	void setCharge(uint32_t);
	uint32_t getCharge() { return chargeNum; };



private:
	// Current state
	//MegamanState* initialState;
	MegamanState* currentState;


	// Buster max and current amount on the screen
	static const uint32_t maxBusterNum = 3;
	uint32_t currentBusterNum;

	//number of pellet each shot of the shotgun will generate
	static const uint32_t pelletNum = 3;

	uint32_t baseJumpPower;
	uint32_t currentJumpPower;

	uint32_t currentWeapon;

	//this is a counter used for the pseudo-random, there might be a better way to do this
	uint32_t count;

	//Charge number on the buster
	uint32_t chargeNum;

};

#endif /* MEGAMAN_H_ */
