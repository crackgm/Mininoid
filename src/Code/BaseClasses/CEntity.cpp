/*
 * CEntity.cpp
 *
 *  Created on: 21 sie 2017
 *      Author: crackgm
 */

#include "CEntity.h"
#include "../Managers.h"

CEntity::CEntity() {
	StateManager::PeekState()->EntityList.push_back(this);

}

CEntity::~CEntity() {
	list<CEntity*>::iterator it;
	for (it = StateManager::PeekState()->EntityList.begin(); it != StateManager::PeekState()->EntityList.end(); ++it) {
		if (*it == this) {
			StateManager::PeekState()->EntityList.erase(it);

			break;
		}
	}
}
