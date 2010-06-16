/*
 * Entity.h
 *
 *  Created on: 2010-06-14
 *      Author: Basse
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "Sprite.h"

#include <stdint.h>

class Environment;
class State;
class VideoMemory;
class Collider;
class Wave;

class Entity : public Sprite {
public:
	Entity(State* initialState, Environment* environment);
	virtual ~Entity();

	// State handling
	void setState(State* state);
	void addSubState(State*);
	void removeSubState(State*);

	// State counters handling
	void setCounter(State*,uint32_t);
	uint32_t getCounter(State*);
	void incCounter(State*);
	void decCounter(State*);

	// SoundFX Accessors
	Wave* getJumpSoundFX() { return jumpSoundFX; }
	Wave* getLandSoundFX() { return landSoundFX; }

	// Attributes handling
	uint32_t getMaxHP() { return maxHP; };
	void setMaxHP(uint32_t maxHP) { this->maxHP = maxHP; };
	uint32_t getCurrentHP() { return currentHP; };
	void setCurrentHP(uint32_t currentHP) { this->currentHP = currentHP; };

	uint32_t getBaseSpeed() { return baseSpeed; };
	void setBaseSpeed(uint32_t baseSpeed) { this->baseSpeed = baseSpeed; };
	uint32_t getCurrentSpeed() { return currentSpeed; };
	void setCurrentSpeed(uint32_t currentSpeed) { this->currentSpeed = currentSpeed; };

	uint32_t getBaseDamage() { return baseDamage; };
	void setBaseDamage(uint32_t baseDamage) { this->baseDamage = baseDamage; };
	uint32_t getCurrentDamage() { return currentDamage; };
	void setCurrentDamage(uint32_t currentDamage) { this->currentDamage = currentDamage; };

	uint32_t getBaseArmorValue() { return baseArmorValue; };
	void setBaseArmorValue(uint32_t baseArmorValue) { this->baseArmorValue = baseArmorValue; };
	uint32_t getCurrentArmorValue() { return currentArmorValue; };
	void setCurrentArmorValue(uint32_t currentArmorValue) { this->currentArmorValue = currentArmorValue; };

	uint8_t isWalkable() { return walkable; };


	// Base class override
	virtual void update();

private:
	// Current state
	State* currentState;
	State** subState;

protected:
	uint32_t* stateCounter;

	uint32_t currentHP;
	uint32_t maxHP;
	uint32_t currentSpeed;
	uint32_t baseSpeed;
	uint32_t currentDamage;
	uint32_t baseDamage;
	uint32_t currentArmorValue;
	uint32_t baseArmorValue;
	uint8_t walkable;
	// SoundFX
	static Wave* jumpSoundFX;
	static Wave* landSoundFX;


};

#endif /* ENTITY_H_ */
