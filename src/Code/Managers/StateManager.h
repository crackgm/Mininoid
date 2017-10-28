/*
 * StateManager.h
 *
 *  Created on: 19 sie 2017
 *      Author: crackgm
 */
#include <stack>
#include <cstdlib>
#include "../BaseClasses/CState.h"

using namespace std;

#ifndef CODE_MANAGERS_STATEMANAGER_H_
#define CODE_MANAGERS_STATEMANAGER_H_


class StateManager {
public:
	static void PushState(CState* state);
	static void PopState();
	static CState* PeekState();
private:
	static stack<CState*> StateStack;
};

#endif /* CODE_MANAGERS_STATEMANAGER_H_ */
