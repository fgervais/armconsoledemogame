/*
 * Enemy.h
 *
 *  Created on: May 12, 2010
 *      Author: fgervais
 */

#ifndef METOOL_H_
#define METOOL_H_

#include "Entity.h"

#include <stdint.h>

class Collider;
class MetoolState;
class Environment;
class State;

class Metool: public Entity {
public:
	Metool(MetoolState* initialState, Environment* environment);
	virtual ~Metool();

	void setState(MetoolState* state);

	// State accessor
	//MetoolState* getWalkingLeftState() { return metoolWalkingLeft; }
	//MetoolState* getWalkingRightState() { return metoolWalkingRight; }
	//MetoolState* getInitialState() { return initialState; }

	// Base class override
	virtual void update();
	virtual void collideWith(Collider*);
	virtual void collideWith(Megaman*);
	virtual void collideWith(Metool*);
	virtual void collideWith(Entity*);
	//virtual void collideWith(ThrowingAxe*);
private:
	// Current state
	//MetoolState* initialState;
	MetoolState* currentState;

	// Every possible Metool state
	//MetoolState* metoolWalkingLeft;
	//MetoolState* metoolWalkingRight;
};

#endif /* METOOL_H_ */
