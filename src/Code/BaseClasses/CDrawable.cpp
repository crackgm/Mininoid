/*
 * CDrawable.cpp
 *
 *  Created on: 19 sie 2017
 *      Author: crackgm
 */

#include "../BaseClasses/CDrawable.h"
#include "../Managers.h"
#include <iostream>

CDrawable::CDrawable() {
	StateManager::PeekState()->DrawableList.push_back(this);

}

CDrawable::~CDrawable() {
	// TODO Auto-generated destructor stub
	list<CDrawable*>::iterator it;
	for (it = StateManager::PeekState()->DrawableList.begin(); it != StateManager::PeekState()->DrawableList.end(); ++it) {
		if (*it == this) {
			StateManager::PeekState()->DrawableList.erase(it);
			break;
		}
	}
}

