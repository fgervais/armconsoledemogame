/*
 * GameLevel.h
 *
 *  Created on: 2010-06-02
 *      Author: Emile
 */

#ifndef GAMELEVEL_H_
#define GAMELEVEL_H_

#include "Environment.h"

class GameLevel: public Environment {
public:
	GameLevel();
	virtual ~GameLevel();

	virtual void build();
};

#endif /* GAMELEVEL_H_ */
