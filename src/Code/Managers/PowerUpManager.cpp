/*
 * PowerUpManager.cpp
 *
 *  Created on: 12 sty 2018
 *      Author: patryk
 */

#include <Managers/PowerUpManager.h>

vector<PowerUpManager::pu> PowerUpManager::powerUps;
PowerUpManager::PowerUpManager() {
	// TODO Auto-generated constructor stub

}

sf::Texture* PowerUpManager::GetTexture(int type) {
	return nullptr;
}

float PowerUpManager::GetSpeed(int type) {
	return 0;
}

PowerUpManager::~PowerUpManager() {
	// TODO Auto-generated destructor stub
}

