/*
 * GameLevel.h
 *
 *  Created on: 2010-06-02
 *      Author: Emile
 */

#ifndef GAMELEVEL_H_
#define GAMELEVEL_H_

#include "Environment.h"
#include "State.h"

class GameLevel: public Environment {
public:
	GameLevel();
	virtual ~GameLevel();

	virtual void build();

	void loadHero(const State *);
	void buildLevelPattern(const char *);
};

#endif /* GAMELEVEL_H_ */
