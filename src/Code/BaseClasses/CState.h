/*
 * CState.h
 *
 *  Created on: 19 sie 2017
 *      Author: crackgm
 */

#ifndef CODE_BASECLASSES_CSTATE_H_
#define CODE_BASECLASSES_CSTATE_H_
#include <list>
#include <cstdlib>
#include "CDrawable.h"
#include "CEntity.h"
#include "CCollidable.h"
#include "CEffect.h"

using namespace std;

class CState {
public:
	list<CDrawable*> DrawableList;
	list<CEntity*> EntityList;
	list<CCollidable*> CollidableList;
	list<CEffect*> EffectList;

	virtual void Create()=0;
	virtual void Update()=0;
	virtual void Render()=0;
	virtual  ~CState(){};
};

#endif /* CODE_BASECLASSES_CSTATE_H_ */
