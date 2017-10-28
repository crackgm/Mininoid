/*
 * CEntity.h
 *
 *  Created on: 21 sie 2017
 *      Author: crackgm
 */

#ifndef CODE_BASECLASSES_CENTITY_H_
#define CODE_BASECLASSES_CENTITY_H_

class CEntity {
public:
	CEntity();
	virtual void Update()=0;
	virtual ~CEntity();
};

#endif /* CODE_BASECLASSES_CENTITY_H_ */
