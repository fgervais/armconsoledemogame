/*
 * Renderable.h
 *
 *  Created on: Mar 8, 2010
 *      Author: fgervais
 */

#ifndef RENDERABLE_H_
#define RENDERABLE_H_

class SDL_Surface;

class Renderable {
public:
	Renderable();
	virtual ~Renderable();

	virtual void render(SDL_Surface*) = 0;
};

#endif /* RENDERABLE_H_ */
