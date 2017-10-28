/*
 * MouseManager.h
 *
 *  Created on: 20 sie 2017
 *      Author: crackgm
 */

#ifndef CODE_MANAGERS_MOUSEMANAGER_H_
#define CODE_MANAGERS_MOUSEMANAGER_H_
#include <SFML/System.hpp>

class MouseManager {
public:
	static int GetX();
	static int GetY();
	static bool LeftPressed();
	static bool LeftReleased();
	static bool RightPressed();
	static bool RightReleased();
	static void MouseUpdater();
private:
	static bool left;
	static bool right;
	static bool leftr;
	static bool rightr;
};

#endif /* CODE_MANAGERS_MOUSEMANAGER_H_ */
