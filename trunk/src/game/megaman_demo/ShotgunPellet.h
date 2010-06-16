/*
 * ShotgunPellet.h
 *
 *  Created on: Mar 8, 2010
 *      Author: DUPA
 */

#ifndef SHOTGUNPELLET_H_
#define SHOTGUNPELLET_H_

#include "Entity.h"

#include <stdint.h>

class Environment;
class ShotgunState;
class VideoMemory;
class Collider;
class Wave;
class Random;

class ShotgunPellet : public Entity {
public:
	ShotgunPellet(ShotgunState* initialState, Environment* environment, uint32_t positionX, uint32_t positionY, uint32_t initializer, uint32_t ini2);
	virtual ~ShotgunPellet();

	void setState(ShotgunState* state);

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
	ShotgunState* initialState;
	ShotgunState* currentState;

	// SoundFX
	static Wave* ShotSoundFX;
	static Wave* collideSoundFX;

	Random* randomGen;

};

#endif /* MEGAMAN_H_ */
