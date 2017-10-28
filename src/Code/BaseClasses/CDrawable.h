/*
 * CDrawable.h
 *
 *  Created on: 19 sie 2017
 *      Author: crackgm
 */

#ifndef CODE_BASECLASSES_CDRAWABLE_H_
#define CODE_BASECLASSES_CDRAWABLE_H_

class CDrawable {
public:
	CDrawable();
	virtual void Render()=0;
	virtual ~CDrawable();
	int Depth = 0;
	bool Visible = true;
};

#endif /* CODE_BASECLASSES_CDRAWABLE_H_ */
