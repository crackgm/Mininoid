/*
 * OComboDrawer.h
 *
 *  Created on: 29 paź 2017
 *      Author: crackgm
 */

#ifndef CODE_OBJECTS_OCOMBODRAWER_H_
#define CODE_OBJECTS_OCOMBODRAWER_H_
#include "../BaseClasses/CEntity.h"
#include "../BaseClasses/CDrawable.h"
#include "../Effects/EText.h"
#include <sstream>

using namespace std;

class OComboDrawer : public CEntity {
public:
	stringstream text;
	EText *txt;
	OComboDrawer();
	static int ComboCounter;
	int time,lastcombo;
	void Update();
	virtual ~OComboDrawer();
};

#endif /* CODE_OBJECTS_OCOMBODRAWER_H_ */
