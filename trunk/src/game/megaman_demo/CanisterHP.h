/*
 * CanisterHP.h
 *
 *  Created on: May 12, 2010
 *      Author: fgervais
 *      Edited: Brass
 */

#ifndef CanisterHP_H_
#define CanisterHP_H_

#include "Entity.h"

#include <stdint.h>

class Collider;
class CanisterHPState;
class Environment;
class State;

class CanisterHP: public Entity {
public:
	CanisterHP(CanisterHPState* initialState, Environment* environment);
	virtual ~CanisterHP();

	void setState(CanisterHPState* state);

	//Return HP value of the canister
	uint32_t getHPgain(){return 5;}

	// Base class override
	virtual void update();
	virtual void collideWith(Collider*);
	virtual void collideWith(Megaman*);
	//virtual void collideWith(CanisterHP*);
	//virtual void collideWith(Entity*);
	//virtual void collideWith(ThrowingAxe*);
private:
	// Current state
	//CanisterHPState* initialState;
	CanisterHPState* currentState;

	// Every possible CanisterHP state
	//CanisterHPState* CanisterHPWalkingLeft;
	//CanisterHPState* CanisterHPWalkingRight;
};

#endif /* CanisterHP_H_ */
