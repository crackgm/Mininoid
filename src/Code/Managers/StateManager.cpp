/*
 * StateManager.cpp
 *
 *  Created on: 19 sie 2017
 *      Author: crackgm
 */

#include "../Managers.h"

#include <stack>
#include <cstdlib>

#include "../BaseClasses/CState.h"
using namespace std;
stack<CState*> StateManager::StateStack;
void StateManager::PushState(CState* state) {
	StateManager::StateStack.push(state);
	StateManager::PeekState()->Create();

}

void StateManager::PopState() {
	StateManager::StateStack.pop();
}

CState* StateManager::PeekState() {
	return StateManager::StateStack.top();
}
