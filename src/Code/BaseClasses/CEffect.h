/*
 * CEffect.h
 *
 *  Created on: 28 paź 2017
 *      Author: crackgm
 */

#ifndef CODE_BASECLASSES_CEFFECT_H_
#define CODE_BASECLASSES_CEFFECT_H_

class CEffect {
public:
	CEffect();
	virtual bool CheckFinish() = 0;
	virtual ~CEffect();
};

#endif /* CODE_BASECLASSES_CEFFECT_H_ */
