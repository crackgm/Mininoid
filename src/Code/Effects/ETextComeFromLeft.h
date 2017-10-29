/*
 * ETextComeFromLeft.h
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */

#ifndef CODE_EFFECTS_ETEXTCOMEFROMLEFT_H_
#define CODE_EFFECTS_ETEXTCOMEFROMLEFT_H_
#include "EText.h"
#include "../BaseClasses/CEffect.h"
#include "../BaseClasses/CEntity.h"

class ETextComeFromLeft : public CEffect, CEntity {
public:
	int alpha;
	float time, x, speed, aspeed, toX;
	EText *txt;
	ETextComeFromLeft(EText *txt, float time, float x);
	void Update();
	bool CheckFinish();

	virtual ~ETextComeFromLeft();
};

#endif /* CODE_EFFECTS_ETEXTCOMEFROMLEFT_H_ */
