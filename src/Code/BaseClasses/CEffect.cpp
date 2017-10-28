/*
 * CEffect.cpp
 *
 *  Created on: 28 paź 2017
 *      Author: crackgm
 */

#include "CEffect.h"
#include "../Managers.h"
#include <iostream>

CEffect::CEffect() {
	StateManager::PeekState()->EffectList.push_back(this);
}

CEffect::~CEffect() {
	list<CEffect*>::iterator it;
	for (it = StateManager::PeekState()->EffectList.begin(); it != StateManager::PeekState()->EffectList.end(); ++it) {
		if (*it == this) {
			StateManager::PeekState()->EffectList.erase(it);
			break;
		}
	}
}
