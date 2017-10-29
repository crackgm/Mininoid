/*
 * ETextLeaveToLeft.h
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */

#ifndef CODE_EFFECTS_ETEXTLEAVETOLEFT_H_
#define CODE_EFFECTS_ETEXTLEAVETOLEFT_H_
#include "EText.h"
#include "../BaseClasses/CEffect.h"
#include "../BaseClasses/CEntity.h"

class ETextLeaveToLeft : public CEffect, CEntity {
public:

	int alpha;
	float time, startx, x, speed, aspeed;
	EText *txt;
	ETextLeaveToLeft(EText *txt, float time, float x);
	void Update();
	bool CheckFinish();
	virtual ~ETextLeaveToLeft();
};

#endif /* CODE_EFFECTS_ETEXTLEAVETOLEFT_H_ */


