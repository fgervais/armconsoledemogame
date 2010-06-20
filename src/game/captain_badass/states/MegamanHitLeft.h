/*
 * MegamanStandingRight.h
 *
 *  Created on: May 3, 2010
 *      Author: fgervais
 */

#ifndef MEGAMANHITLEFT_H_
#define MEGAMANHITLEFT_H_

#include "MegamanState.h"

class MegamanHitLeft : public MegamanState {
public:
	static MegamanState* getInstance();

	// Base class function override
	virtual void update(Megaman*);
	virtual void initialize(Megaman*);

private:
	MegamanHitLeft(uint32_t width, uint32_t height, Bitmap** frames, uint32_t numberOfFrame, Bitmap** animationMasks);
	virtual ~MegamanHitLeft();

	static MegamanState* instance;
};

#endif /* MEGAMANHITLEFT_H_ */
