/*
 * Collider.h
 *
 *  Created on: May 19, 2010
 *      Author: fgervais
 */

#ifndef COLLIDER_H_
#define COLLIDER_H_

class Megaman;
class Metool;
class CanisterHP;
class Entity;

/**
 * Something that can collide with something else.
 *
 * It should be modified according to your game.
 */
class Collider {
public:
	Collider();
	virtual ~Collider();

	/*
	 * Every subclass should implement that with basically the
	 * same implementation similar to the Visitor pattern.
	 *
	 * e.g.
	 * collideWith(Collider* collider) {
	 *   collider->collideWith(this);
	 * }
	 */
	virtual void collideWith(Collider*) = 0;
	virtual void collideWith(Megaman*) {}
	virtual void collideWith(Metool*) {}
	virtual void collideWith(CanisterHP*){}
	virtual void collideWith(Entity*) {}
};

#endif /* COLLIDER_H_ */
