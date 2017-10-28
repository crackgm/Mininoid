/*
 * MouseManager.cpp
 *
 *  Created on: 20 sie 2017
 *      Author: crackgm
 */

#include "../Managers.h"

bool MouseManager::left = false;
bool MouseManager::right = false;
bool MouseManager::leftr = false;
bool MouseManager::rightr = false;

int MouseManager::GetX() {
	return(sf::Mouse::getPosition(*GameManager::Window).x);
}

int MouseManager::GetY() {
	return(sf::Mouse::getPosition(*GameManager::Window).y);
}

bool MouseManager::LeftPressed() {
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool MouseManager::LeftReleased() {
	return leftr;
}

bool MouseManager::RightReleased() {
	return rightr;
}

bool MouseManager::RightPressed() {
	return sf::Mouse::isButtonPressed(sf::Mouse::Right);
}

void MouseManager::MouseUpdater() {
	if (leftr) leftr = false;
	if (rightr) rightr = false;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		left = true;
	}
	if (left && !sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		left = false;
		leftr = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		right = true;
	}
	if (right && !sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		right = false;
		rightr = true;
	}
}
