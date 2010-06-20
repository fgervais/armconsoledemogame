/*
 * Buster.h
 *
 *  Created on: Mar 8, 2010
 *      Author: fournierseb
 */

#ifndef BUSTER_H_
#define BUSTER_H_

#include "Entity.h"

#include <stdint.h>

class Environment;
class BusterState;
class VideoMemory;
class Collider;
class Wave;

class Buster : public Entity {
public:
	Buster(BusterState* initialState, Environment* environment, uint32_t positionX, uint32_t positionY);
	virtual ~Buster();

	void setState(BusterState* state);

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
	BusterState* initialState;
	BusterState* currentState;

	// SoundFX
	static Wave* ShotSoundFX;
	static Wave* collideSoundFX;

};

#endif /* MEGAMAN_H_ */
