/*
d * ETextBounce.h
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */

#ifndef CODE_EFFECTS_ETEXTBOUNCE_H_
#define CODE_EFFECTS_ETEXTBOUNCE_H_
#include "EText.h"
#include "../BaseClasses/CEffect.h"
#include "../BaseClasses/CEntity.h"

class ETextBounce : public CEffect, CEntity {
public:
	ETextBounce(EText *txt, float time);

	float time, scale, angle, temp, speed;

	void Update();
	bool CheckFinish();
	EText *txt;
	virtual ~ETextBounce();
};

#endif /* CODE_EFFECTS_ETEXTBOUNCE_H_ */





