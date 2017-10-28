/*
 * CCollidable.cpp
 *
 *  Created on: 21 sie 2017
 *      Author: crackgm
 */

#include "CCollidable.h"
#include "../Managers.h"
#include <iostream>


CCollidable::CCollidable() {
	StateManager::PeekState()->CollidableList.push_back(this);
	colenable = true;
}

CCollidable::~CCollidable() {
	list<CCollidable*>::iterator it;
	for (it = StateManager::PeekState()->CollidableList.begin(); it != StateManager::PeekState()->CollidableList.end(); ++it) {
		if (*it == this) {
			StateManager::PeekState()->CollidableList.erase(it);
			break;
		}
	}
}

