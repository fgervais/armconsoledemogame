/*
 * MegamanStandingRight.h
 *
 *  Created on: May 3, 2010
 *      Author: fgervais
 */

#ifndef MEGAMANHITRIGHT_H_
#define MEGAMANHITRIGHT_H_

#include "MegamanState.h"

class MegamanHitRight : public MegamanState {
public:
	static MegamanState* getInstance();

	// Base class function override
	virtual void update(Megaman*);
	virtual void initialize(Megaman*);

private:
	MegamanHitRight(uint32_t width, uint32_t height, Bitmap** frames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~MegamanHitRight();

	static MegamanState* instance;
};

#endif /* MEGAMANHITRIGHT_H_ */
