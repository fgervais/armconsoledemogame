/*
 * Buster.h
 *
 *  Created on: Mar 8, 2010
 *      Author: fournierseb
 */

#ifndef THROWINGAXE_H_
#define THROWINGAXE_H_

#include "Entity.h"

#include <stdint.h>

class Environment;
class ThrowingAxeState;
class VideoMemory;
class Collider;
class Wave;
class Random;

class ThrowingAxe : public Entity {
public:
	ThrowingAxe(ThrowingAxeState* initialState, Environment* environment, uint32_t positionX, uint32_t positionY);
	virtual ~ThrowingAxe();

	void setState(ThrowingAxeState* state);



	// Base class override
	virtual void update();
	virtual void collideWith(Collider*);
	virtual void collideWith(Megaman*);
	virtual void collideWith(Metool*);


	// SoundFX Accessors
	Wave* getShotSoundFX() { return ShotSoundFX; }
	Wave* getCollideSoundFX() { return collideSoundFX; }

	// Action functions
	void shotLeft();
	void shotRight();
private:
	// Current state
	ThrowingAxeState* initialState;
	ThrowingAxeState* currentState;



	// SoundFX
	static Wave* ShotSoundFX;
	static Wave* collideSoundFX;
	Random* randomGen;

	//uint32_t test;

};

#endif /* MEGAMAN_H_ */
